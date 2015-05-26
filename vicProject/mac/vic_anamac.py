#!/usr/bin/python

import sys, os

from larlite import larlite
import ROOT

# Load my shared object
ROOT.gSystem.Load("libvic_larlite_play_vicProject.so")

the_file = sys.argv[1]


# My shared object knows about larlite hopefully if it's in same namespace
proc = larlite.ana_processor()
proc.set_io_mode(larlite.storage_manager.kREAD)
proc.add_input_file(the_file)

vic_ana = larlite.vicAna()
proc.add_process(vic_ana)
proc.set_ana_output_file("the_data.root");

proc.run()

# my_ana = XXXXX.XXXXXClusAna()

# my_proc.add_process(my_ana)

# while my_proc.process_event():
#     print "Hit Enter to continue to the next event..."
#     sys.stdin.readline()


# # done!

# Lets just try to do one event first


sys.exit(0)
