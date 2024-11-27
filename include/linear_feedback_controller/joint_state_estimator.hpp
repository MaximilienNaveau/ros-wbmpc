// Copyright (c) 2023, PAL Robotics
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LINEAR_FEEDBACK_CONTROLLER__JOINT_STATE_ESTIMATOR_HPP
#define LINEAR_FEEDBACK_CONTROLLER__JOINT_STATE_ESTIMATOR_HPP

// system
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "realtime_tools/realtime_buffer.h"
#include "std_msgs/msg/float64_multi_array.hpp"
// auto-generated by generate_parameter_library
#include "linear_feedback_controller/joint_state_estimator_generated_parameters.hpp"

/**
 * JointStateEstimator is a simple controller that exposes state interfaces
 * equal to the number of it's command interfaces. This controller simply
 * forwards the information from it's state interface to it's own command
 * interfaces. It may filter some of the states.
 */
namespace linear_feedback_controller {
using DataType = std_msgs::msg::Float64MultiArray;
class JointStateEstimator : public controller_interface::ControllerInterface {
 public:
  controller_interface::CallbackReturn on_init() final;

  controller_interface::InterfaceConfiguration command_interface_configuration()
      const final;

  controller_interface::InterfaceConfiguration state_interface_configuration()
      const final;

  controller_interface::CallbackReturn on_configure(
      const rclcpp_lifecycle::State& previous_state) final;

  controller_interface::CallbackReturn on_activate(
      const rclcpp_lifecycle::State& previous_state) final;

  controller_interface::CallbackReturn on_deactivate(
      const rclcpp_lifecycle::State& previous_state) final;

  controller_interface::return_type update(const rclcpp::Time& time,
                                           const rclcpp::Duration& period);

 protected:
  std::shared_ptr<joint_state_estimator::ParamListener> param_listener_;
  joint_state_estimator::Params params_;

  std::vector<std::string> state_interface_names_;
  std::vector<std::string> command_interface_names_;
};
}  // namespace linear_feedback_controller

#endif  // LINEAR_FEEDBACK_CONTROLLER__JOINT_STATE_ESTIMATOR_HPP