#include "resources/config.h"
#include <gtest/gtest.h>

#include <geometry_msgs/yaml/Point.h>
#include <geometry_msgs/yaml/Pose2D.h>

TEST(PointTest, read)
{

  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/geometry.yaml");
  geometry_msgs::Point p = node["point"].as<geometry_msgs::Point>();

  EXPECT_EQ(1,p.x);
  EXPECT_EQ(1,p.y);
  EXPECT_EQ(1,p.z);
}

TEST(PointTest, read_underspec)
{

  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/geometry.yaml");
  geometry_msgs::Point p = node["pointxy"].as<geometry_msgs::Point>();

  EXPECT_EQ(2,p.x);
  EXPECT_EQ(3,p.y);
  EXPECT_EQ(0,p.z);
}

TEST(PointTest, write)
{
  geometry_msgs::Point p;
  p.x = 1;
  p.y = 2.2;
  p.z = -3.3;

  YAML::Node point;
  point["p"] = p;

  geometry_msgs::Point p2 = point["p"].as<geometry_msgs::Point>();
  EXPECT_EQ(p2.x,p.x);
  EXPECT_EQ(p2.y,p.y);
  EXPECT_EQ(p2.z,p.z);
}

TEST(Pose2DTest, read)
{

  YAML::Node node = YAML::LoadFile(std::string(TEST_RESOURCES_DIR) + "/geometry.yaml");
  geometry_msgs::Pose2D p = node["pose_2d"].as<geometry_msgs::Pose2D>();
  
  EXPECT_EQ(2,p.x);
  EXPECT_EQ(3,p.y);
  EXPECT_EQ(4,p.theta);

  p = node["pointxy"].as<geometry_msgs::Pose2D>();
  EXPECT_EQ(2,p.x);
  EXPECT_EQ(3,p.y);
  EXPECT_EQ(0,p.theta);

}

TEST(Pose2DTest, write)
{
  geometry_msgs::Pose2D p;
  p.x = 1;
  p.y = 2.2;
  p.theta = -3.3;

  YAML::Node pose;
  pose["p"] = p;

  geometry_msgs::Pose2D p2 = pose["p"].as<geometry_msgs::Pose2D>();
  EXPECT_EQ(p2.x,p.x);
  EXPECT_EQ(p2.y,p.y);
  EXPECT_EQ(p2.theta,p.theta);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}