cmake_minimum_required(VERSION 2.8.3)
project(gencppyaml)
find_package(catkin REQUIRED COMPONENTS genmsg)

set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    ${CMAKE_MODULE_PATH}
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS genmsg
  CFG_EXTRAS gencppyaml-extras.cmake
)

include_directories(include)

add_subdirectory(scripts)

file(WRITE ${CATKIN_DEVEL_PREFIX}/${GENMSG_LANGS_DESTINATION}/gencppyaml "cppyaml")
install(FILES ${CATKIN_DEVEL_PREFIX}/${GENMSG_LANGS_DESTINATION}/gencppyaml
  DESTINATION ${GENMSG_LANGS_DESTINATION})

catkin_python_setup()
