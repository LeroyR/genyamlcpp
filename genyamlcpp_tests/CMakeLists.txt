cmake_minimum_required(VERSION 3.1)
project(genyamlcpp_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    ${CMAKE_MODULE_PATH}
)

if(NOT CPPYAML_HEADER_INCLUDE_DIR)
    set(CPPYAML_HEADER_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/include)
endif()

MESSAGE(AUTHOR_WARNING "generate cppyaml files with " 
    "'rosrun genyamlcpp genyamlcpp_message_artifact -o ${CPPYAML_HEADER_INCLUDE_DIR}'"
    " to generate headers or set CPPYAML_HEADER_INCLUDE_DIR to the correct path")

##############################
##  Deps
##############################
find_package(catkin REQUIRED
    COMPONENTS
    cmake_modules
    genyamlcpp

    geometry_msgs
    std_msgs
)
include_directories(${catkin_INCLUDE_DIRS})

#find_package(YamlCpp REQUIRED)
#include_directories(${YAMLCPP_INCLUDE_DIR})

##################################
## CATKIN
##################################
catkin_package(#INCLUDE_DIRS include
    #LIBRARIES
    #CATKIN_DEPENDS 
    #DEPENDS
)

##############################
##  Build
##############################

## Python
#catkin_python_setup()

##############################
## Install rules
##############################

##############################
## Tests
##############################
if(CATKIN_ENABLE_TESTING)

    file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test/resources" TEST_RESOURCES_DIR)
    configure_file(test/resources/config.h.in "${CMAKE_CURRENT_BINARY_DIR}/resources/config.h")
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    include_directories(${CPPYAML_HEADER_INCLUDE_DIR})

    catkin_add_gtest(${project}_std_msgs test/std_msgs.cpp)
    target_link_libraries(${project}_std_msgs ${catkin_LIBRARIES} yaml-cpp)

    catkin_add_gtest(${project}_geometry_msgs test/geometry_msgs.cpp)
    target_link_libraries(${project}_geometry_msgs ${catkin_LIBRARIES} yaml-cpp)
endif()

