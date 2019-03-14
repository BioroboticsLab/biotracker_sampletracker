##############################################################
#### Biotracker: Sampletracker
##############################################################
include(biotracker-utility/VSSugar)
VSSourceGroups(${CMAKE_CURRENT_LIST_DIR})

include(biotracker-utility/TrackerPlugin)

set(target biotracker-sample.bio_tracker)

add_behavior_plugin(${target}
    "PluginContext.cpp"
    "BioTrackerPlugin.cpp"
    "View/TrackedElementView.cpp"
    "View/TrackerParameterView.cpp"
    "Model/null_Model.cpp"
    "Model/BioTrackerTrackingAlgorithm.cpp"
    "Model/TrackerParameter.cpp"
    "Controller/ControllerTrackedComponent.cpp"
    "Controller/ControllerTrackingAlgorithm.cpp"
    "Controller/null_Controller.cpp"
)

install(TARGETS ${target} OPTIONAL DESTINATION .)