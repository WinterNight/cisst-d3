# Project name
project(ComponentViewerD3)

cmake_minimum_required(VERSION 2.6)

# set all libraries needed
set (REQUIRED_CISST_LIBRARIES cisstCommon cisstVector cisstOSAbstraction cisstMultiTask)

# find cisst and make sure the required libraries have been compiled
find_package (cisst COMPONENTS ${REQUIRED_CISST_LIBRARIES} QUIET)

if (cisst_FOUND_AS_REQUIRED)
  # load cisst configuration
  include (${CISST_USE_FILE})
  add_executable (componentViewerD3 main.cpp ComponentViewerD3.h ComponentViewerD3.cpp 
    Layer.h Parser.h Parser.cpp Process.h Process.cpp Component.h Component.cpp Interface.h Interface.cpp)
  cisst_target_link_libraries (componentViewerD3 ${REQUIRED_CISST_LIBRARIES})
else (cisst_FOUND_AS_REQUIRED)
    message("cisst NOT FOUND")
endif(cisst_FOUND_AS_REQUIRED)
