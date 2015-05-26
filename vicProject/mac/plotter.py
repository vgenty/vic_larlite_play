from ROOT import *
from looks import *


looks_minos()
tf = TFile.Open("the_data.root","READ")

gStyle.SetOptStat(1111)

c1 = TCanvas()
hCluster = tf.hCluster
hCluster.GetXaxis().SetTitle("larlite::cluster->IntegralAverage()")
hCluster.Draw()


c2 = TCanvas()
hFromHits = tf.hFromHits
hFromHits.GetXaxis().SetTitle("Average larlite::hit->Integral()")
hFromHits.Draw()

