# SampleTracker

This repository showcases how you can implement a new tracking algorithm for BioTracker. 

Please note that tracking algorithms are only certain to work with BioTracker if they are compiled
with the same compiler using the same C++ standard library. 

## Building on Windows

Configuring without rebuilding the BioTracker:  
- Download and extract the latest Biotracker and library from https://github.com/BioroboticsLab/biotracker_core/releases  
- Clone or fork the sampletracker and configure using CMake
- Building requires the same dependencies as the BioTracker. They are toolchained exactly like the BioTracker, see corresponding readme. 
- In CMake, set variable "BTLibrary" to the the path you extracted the library to. Alternatively, set your path enviromental variable correctly.
- Configure & Build
- Run Biotracker and load generated DLL

## Building on Linux

Toolchain is windows-specific and needs adjustment for linux convinience.  
Build the BioTracker from source and add generated libraries to the binary folder of the release download.
Otherwise do as in the windows guide.