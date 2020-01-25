#pragma once

#include <realtime_tools/realtime_publisher.h>
#include <uwrt_mars_rover_hw/uwrt_mars_rover_hw_science.h>
#include <uwrt_mars_rover_msgs/ScienceHWState.h>

namespace uwrt_mars_rover_hw {

class UWRTRoverHWScienceReal : public UWRTRoverHWScience {
 public:
  bool init(ros::NodeHandle& root_nh, ros::NodeHandle& robot_hw_nh) override;
  void read(const ros::Time& time, const ros::Duration& period) override;
  void write(const ros::Time& time, const ros::Duration& period) override;

  inline void setPublishRate(double rate) {
    publish_period_ = ros::Duration(1.0 / rate);
  }

 private:
  // publisher for science hw state
  ros::Duration publish_period_;
  realtime_tools::RealtimePublisher<uwrt_mars_rover_msgs::ScienceHWState> science_state_pub_;
};

}  // namespace uwrt_mars_rover_hw