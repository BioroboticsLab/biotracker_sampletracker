# SampleTracker

This repository showcases how you can implement a new tracking algorithm for BioTracker. 

Just fork this repository and you're ready to go.

Please note that tracking algorithms are only certain to work with BioTracker if they are compiled
with the same compiler using the same C++ standard library. 

## Manual setup

### CMake config

We use CMake in combination with the CPM package manager for our projects.

Initialization of CPM in CMakeLists.txt
```CMake
set(CPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpm_packages" CACHE TYPE STRING)
find_package(Git)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "CPM requires Git.")
endif()
if (NOT EXISTS ${CPM_DIR}/CPM.cmake)
  message(STATUS "Cloning repo (https://github.com/iauns/cpm)")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" clone https://github.com/iauns/cpm ${CPM_DIR}
    RESULT_VARIABLE error_code
    OUTPUT_QUIET ERROR_QUIET)
  if(error_code)
    message(FATAL_ERROR "CPM failed to get the hash for HEAD")
  endif()
endif()
include(${CPM_DIR}/CPM.cmake)
```

Now you can use our shared c++ compilation settings and add the BioTracker Core as a CPM dependency.
```CMake
if(NOT DEFINED CMAKECONFIG_PATH)
    CPM_AddModule("cmakeconfig"
        GIT_REPOSITORY "https://github.com/BioroboticsLab/cmakeconfig.git"
        GIT_TAG "master")
else()
    CPM_AddModule("cmakeconfig"
        SOURCE_DIR "${CMAKECONFIG_PATH}")
endif()

include_biotracker_core("master")

CPM_Finish()

biorobotics_config()
```

### Registration
```C++
extern "C" {
    void registerTracker() {
        BioTracker::Core::Registry::getInstance().registerTrackerType<SampleTracker>("SampleTracker");
    }
}
```


