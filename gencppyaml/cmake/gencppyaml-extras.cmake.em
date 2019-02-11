@[if DEVELSPACE]@
# bin and template dir variables in develspace
set(GENCPPYAML_BIN "@(CMAKE_CURRENT_SOURCE_DIR)/scripts/gen_cppyaml.py")
set(GENCPPYAML_TEMPLATE_DIR "@(CMAKE_CURRENT_SOURCE_DIR)/scripts")
@[else]@
# bin and template dir variables in installspace
set(GENCPPYAML_BIN "${GENCPPYAML_DIR}/../../../@(CATKIN_PACKAGE_BIN_DESTINATION)/gen_cppyaml.py")
set(GENCPPYAML_TEMPLATE_DIR "${GENCPPYAML_DIR}/..")
@[end if]@

# Generate .msg->.h for cpp
# The generated .h files should be added ALL_GEN_OUTPUT_FILES_cpp
macro(_generate_msg_cppyaml ARG_PKG ARG_MSG ARG_IFLAGS ARG_MSG_DEPS ARG_GEN_OUTPUT_DIR)
  file(MAKE_DIRECTORY ${ARG_GEN_OUTPUT_DIR}/yaml)

  #Create input and output filenames
  get_filename_component(MSG_NAME ${ARG_MSG} NAME)
  get_filename_component(MSG_SHORT_NAME ${ARG_MSG} NAME_WE)

  set(MSG_GENERATED_NAME ${MSG_SHORT_NAME}.h)
  set(GEN_OUTPUT_FILE ${ARG_GEN_OUTPUT_DIR}/yaml/${MSG_GENERATED_NAME})

  assert(CATKIN_ENV)
  add_custom_command(OUTPUT ${GEN_OUTPUT_FILE}
      DEPENDS ${GENCPPYAML_BIN} ${ARG_MSG} ${ARG_MSG_DEPS} ${MSG_PLUGIN} "${GENCPPYAML_TEMPLATE_DIR}/msg.h.template" ${ARGN}
      COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENCPPYAML_BIN} ${ARG_MSG}
      ${ARG_IFLAGS}
      -p ${ARG_PKG}
      -o ${ARG_GEN_OUTPUT_DIR}/yaml
      -e ${GENCPPYAML_TEMPLATE_DIR}
      COMMENT "Generating Cppyaml code from ${ARG_PKG}/${MSG_NAME} -> ${GEN_OUTPUT_FILE} 
      ${PYTHON_EXECUTABLE} ${GENCPPYAML_BIN} ${ARG_MSG}
      -p ${ARG_PKG} 
      -o ${ARG_GEN_OUTPUT_DIR}/yaml
      -e ${GENCPPYAML_TEMPLATE_DIR}"
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
      )
  list(APPEND ALL_GEN_OUTPUT_FILES_cppyaml ${GEN_OUTPUT_FILE})

  gencppyaml_append_include_dirs()
endmacro()

#GENCPPYAML uses the same program to generate srv and msg files, so call the same macro
macro(_generate_srv_cppyaml ARG_PKG ARG_SRV ARG_IFLAGS ARG_MSG_DEPS ARG_GEN_OUTPUT_DIR)
  _generate_msg_cppyaml(${ARG_PKG} ${ARG_SRV} "${ARG_IFLAGS}" "${ARG_MSG_DEPS}" ${ARG_GEN_OUTPUT_DIR} "${GENCPP_TEMPLATE_DIR}/srv.h.template")
endmacro()

macro(_generate_module_cppyaml)
  # the macros, they do nothing
endmacro()

set(gencppyaml_INSTALL_DIR include)

macro(GENCPPYAML_append_include_dirs)
  if(NOT GENCPPYAML_APPENDED_INCLUDE_DIRS)
    # make sure we can find generated messages and that they overlay all other includes
    include_directories(BEFORE ${CATKIN_DEVEL_PREFIX}/${GENCPPYAML_INSTALL_DIR})
    # pass the include directory to catkin_package()
    list(APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${CATKIN_DEVEL_PREFIX}/${GENCPPYAML_INSTALL_DIR})
    set(GENCPPYAML_APPENDED_INCLUDE_DIRS TRUE)
  endif()
endmacro()
