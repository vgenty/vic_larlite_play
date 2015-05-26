#ifndef LARLITE_VICANA_CXX
#define LARLITE_VICANA_CXX

#include "vicAna.h"

namespace larlite {

  bool vicAna::initialize() {

    _hCluster  = new TH1D("hCluster",";;",250,0,1000);
    _hfromHits = new TH1D("hFromHits",";;",250,0,1000);
 
    return true;
  }
  
  bool vicAna::analyze(storage_manager* storage) {
  
    //
    // Do your event-by-event analysis here. This function is called for 
    // each event in the loop. You have "storage" pointer which contains 
    // event-wise data. To see what is available, check the "Manual.pdf":
    //
    // http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
    // 
    // Or you can refer to Base/DataFormatConstants.hh for available data type
    // enum values. Here is one example of getting PMT waveform collection.
    //
    // event_fifo* my_pmtfifo_v = (event_fifo*)(storage->get_data(DATA::PMFIFO));
    //
    // if( event_fifo )
    //
    //   std::cout << "Event ID: " << my_pmtfifo_v->event_id() << std::endl;
    //

    std::cout << "Event: " << storage->get_entries_read() << "\n";

    // Hopefully the type is correct here

    auto evt_clusters = storage->get_data<event_cluster>("fuzzycluster"); // Get clusters
    auto evt_hits     = storage->get_data<event_hit>    ("gaushit");      // Get hits
    auto evt_ass_data = storage->get_data<event_ass>    ("fuzzycluster"); // Get their associatio
    AssSet_t cluster_to_hit_ass;

    // What type is this ?
    try {
       cluster_to_hit_ass= evt_ass_data->association(evt_clusters->id(),evt_hits->id());   
    } catch(DataFormatException) {
      std::cout << "caught? \n";
    }
    // Ok we will put all the events in the same histogram why not

    // Do clusters
    for(int i = 0; i < evt_clusters->size(); ++i)
      _hCluster->Fill(evt_clusters->at(i).IntegralAverage());

    auto clusterQ = 0.0;
    auto count    = 0.0;

    for(auto const& hit_indices : cluster_to_hit_ass) {
      clusterQ = 0.0;
      count    = 0.0;
      for(auto const& hit_index : hit_indices) {
	clusterQ += (*evt_hits)[hit_index].Integral();
	count++;
      }
      
      _hfromHits->Fill(clusterQ/count);
    }
  



    // Why does this fail?
    // for(auto cluster : evt_clusters)
    //   _hCluster->Fill(cluster.Charge());
    
    return true;
  }

  bool vicAna::finalize() {

    // This function is called at the end of event loop.
    // Do all variable finalization you wish to do here.
    // If you need, you can store your ROOT class instance in the output
    // file. You have an access to the output file through "_fout" pointer.
    //
    // Say you made a histogram pointer h1 to store. You can do this:
    //
    // if(_fout) { _fout->cd(); h1->Write(); }
    //
    // else 
    //   print(MSG::ERROR,__FUNCTION__,"Did not find an output file pointer!!! File not opened?");
    //

    _hCluster->Write();
    _hfromHits->Write();
  

  
    return true;
  }

}
#endif
