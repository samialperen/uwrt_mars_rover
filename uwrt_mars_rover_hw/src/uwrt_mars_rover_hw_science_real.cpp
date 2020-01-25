#include "uwrt_mars_rover_hw/uwrt_mars_rover_hw_science_real.h"

namespace uwrt_mars_rover_hw {
bool UWRTRoverHWScienceReal::init(ros::NodeHandle& root_nh, ros::NodeHandle& robot_hw_nh) {
  if (!UWRTRoverHWScience::init(root_nh, robot_hw_nh)) {
    return false;
  }

  // init state publisher
  double pub_freq;
  robot_hw_nh.param("uwrt_mars_rover_hw_science_pub_freq", pub_freq, 10.0);
  setPublishRate(pub_freq);

  science_state_pub_.init(root_nh, "uwrt_mars_rover_hw/science_state", 10);

  // TODO (wraftus) init socketcan

  return true;
}

void UWRTRoverHWScienceReal::read(const ros::Time& time, const ros::Duration& period) {
  // TODO (wraftus) read joint and sensor issue from science board, and update joint_state_
}
// TODO: Implement
void UWRTRoverHWScienceReal::write(const ros::Time& time, const ros::Duration& period) {
  // TODO (wraftus) send new commands from joint_cmds_ to the science board, and publish new science state
}

}  // namespace uwrt_mars_rover_hw