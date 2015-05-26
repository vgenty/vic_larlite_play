/**
 * \file vicAna.h
 *
 * \ingroup vicProject
 * 
 * \brief Class def header for a class vicAna
 *
 * @author vgenty
 */

/** \addtogroup vicProject

    @{*/

#ifndef LARLITE_VICANA_H
#define LARLITE_VICANA_H

#include "Analysis/ana_base.h"

#include "DataFormat/cluster.h"
#include "DataFormat/hit.h"
#include "DataFormat/event_ass.h"

#include "TH1D.h"

namespace larlite {
  /**
     \class vicAna
     User custom analysis class made by SHELL_USER_NAME
   */
  class vicAna : public ana_base{
  
  public:

    /// Default constructor
    vicAna(){ _name="vicAna"; _fout=0;}

    /// Default destructor
    virtual ~vicAna(){}

    /** IMPLEMENT in vicAna.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in vicAna.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in vicAna.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:

  private:
    TH1D* _hCluster;
    TH1D* _hfromHits;

  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
