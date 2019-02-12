#include "resources/config.h"
#include <gtest/gtest.h>

#include <std_msgs/yaml/String.h>
#include <std_msgs/yaml/Bool.h>
#include <std_msgs/yaml/Float32.h>
#include <std_msgs/yaml/Float64.h>

#include <std_msgs/yaml/Byte.h>
#include <std_msgs/yaml/Char.h>

#include <std_msgs/yaml/Int8.h>
#include <std_msgs/yaml/Int16.h>
#include <std_msgs/yaml/Int32.h>
#include <std_msgs/yaml/Int64.h>

#include <std_msgs/yaml/Duration.h>
#include <std_msgs/yaml/Time.h>
#include <std_msgs/yaml/Header.h>

TEST(String, write)
{
  std_msgs::String msg;
  msg.data = "foo";

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::String msg2 = node["msg"].as<std_msgs::String>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Bool, write)
{
  std_msgs::Bool msg;
  msg.data = true;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Bool msg2 = node["msg"].as<std_msgs::Bool>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Bool, read)
{
  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/std.yaml");
  std_msgs::Bool bt = node["bool_t"].as<std_msgs::Bool>();
  std_msgs::Bool bf = node["bool_f"].as<std_msgs::Bool>();

  EXPECT_EQ(true,bt.data);
  EXPECT_EQ(false,bf.data);
}

TEST(Float32, write)
{
  std_msgs::Float32 msg;
  msg.data = 1.5;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Float32 msg2 = node["msg"].as<std_msgs::Float32>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Float64, write)
{
  std_msgs::Float64 msg;
  msg.data = 1.5;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Float64 msg2 = node["msg"].as<std_msgs::Float64>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Byte, write)
{
  std_msgs::Byte msg;
  msg.data = 2;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Byte msg2 = node["msg"].as<std_msgs::Byte>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Char, write)
{
  std_msgs::Char msg;
  msg.data = 'F';

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Char msg2 = node["msg"].as<std_msgs::Char>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Int8, write)
{
  std_msgs::Int8 msg;
  msg.data = 8;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Int8 msg2 = node["msg"].as<std_msgs::Int8>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Int16, write)
{
  std_msgs::Int16 msg;
  msg.data = 16;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Int16 msg2 = node["msg"].as<std_msgs::Int16>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Int32, write)
{
  std_msgs::Int32 msg;
  msg.data = 32;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Int32 msg2 = node["msg"].as<std_msgs::Int32>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Int64, write)
{
  std_msgs::Int64 msg;
  msg.data = 64l;

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Int64 msg2 = node["msg"].as<std_msgs::Int64>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Duration, write)
{
  std_msgs::Duration msg;
  msg.data = ros::Duration(20);

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Duration msg2 = node["msg"].as<std_msgs::Duration>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Duration, read_iso)
{
  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/std.yaml");
  std_msgs::Duration msg = node["duration_string"].as<std_msgs::Duration>();
  EXPECT_EQ(30,msg.data.toSec());

  msg = node["duration_string2"].as<std_msgs::Duration>();
  EXPECT_EQ(3600,msg.data.toSec());
}

TEST(Time, write)
{
  std_msgs::Time msg;
  msg.data = ros::Time(20);

  YAML::Node node;
  node["msg"] = msg;

  std_msgs::Time msg2 = node["msg"].as<std_msgs::Time>();
  EXPECT_EQ(msg.data,msg2.data);
}

TEST(Time, read_iso)
{
  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/std.yaml");
  std_msgs::Time msg = node["timestamp_iso"].as<std_msgs::Time>();
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}