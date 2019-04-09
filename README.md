# Generator yaml-cpp

Generates yaml-cpp convert Templates for ros Messages


## Usage

Build genyamlcpp before your messages. 
Then simply include pkg/yaml/message.h to use the convert templates.

You may have to link against yaml-cpp: 

```
target_link_libraries(<target> yaml-cpp)
```

### Builtins

genyamlcpp includes converter for ros time and duration (e.g. include ros/yaml/[time|duration].h)

```yaml
timestamp_iso: 20190101T100001

duration_string: 00:00:30

both:
    nsec: 0
    sec: 60
```

### Example

Reading yaml file
```yaml
point_1:
    x: 1
    y: 1
    z: 1
```	

```cpp
#include <geometry_msgs/yaml/Point.h>
void read_point() {
  YAML::Node node = YAML::LoadFile("points.yaml");
  geometry_msgs::Point p = node["point_1"].as<geometry_msgs::Point>();
}
```

Writing to a file
```cpp
void write_point() {
  geometry_msgs::Point p;
  p.x = 1;
  p.y = 2.2;
  p.z = -3.3;

  YAML::Node node;
  node["p"] = p;
  std::ofstream fout("file.yaml");
  fout << node;
}
```

### Batch generation

Generate messages for all packages with the genyamlcpp_message_artifacts script

```
source /workspace/install
rosrun genyamlcpp genyamlcpp_message_artifacts -o /workspace/install
```

