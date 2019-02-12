#pragma once

#include <yaml-cpp/yaml.h>

#include <ros/duration.h>

#include "boost/date_time/posix_time/posix_time.hpp"

namespace YAML
{

template <>
struct convert<ros::Duration>
{
  static Node encode(const ros::Duration& d)
  {
    Node node;
    node["sec"] = d.sec;
	  node["nsec"] = d.nsec;
    return node;
  }

  static bool decode(const Node& node, ros::Duration& d)
  {
     if (node.IsScalar()) {
      auto t = boost::posix_time::duration_from_string(node.as<std::string>());
      d.fromSec(t.total_seconds());
	  } else {
      if (node["sec"]) {
        d.sec = node["sec"].as<uint32_t>();
      }
      if (node["nsec"]) {
        d.nsec = node["nsec"].as<uint32_t>();
      } 
	  }
    return true;
  }
};

}