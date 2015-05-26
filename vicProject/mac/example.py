import sys
from ROOT import gSystem
gSystem.Load("libvic_larlite_play_vicProject")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing vicProject..."

sys.exit(0)

