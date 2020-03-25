install(
  FILES msg.h.template srv.h.template
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(
  FILES msg.h.template srv.h.template
  DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}/genyamlcpp
)

catkin_install_python(
  PROGRAMS gen_yamlcpp.py genyamlcpp_message_artifacts
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

