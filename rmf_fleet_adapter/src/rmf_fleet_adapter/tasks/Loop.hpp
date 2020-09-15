/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef SRC__RMF_FLEET_ADAPTER__TASKS__LOOP_HPP
#define SRC__RMF_FLEET_ADAPTER__TASKS__LOOP_HPP

#include "../Task.hpp"
#include "../agv/RobotContext.hpp"

#include <rmf_utils/optional.hpp>
#include <rmf_traffic/agv/Planner.hpp>
#include <rmf_fleet_adapter/agv/FleetUpdateHandle.hpp>

#include <rmf_task_msgs/msg/loop.hpp>

namespace rmf_fleet_adapter {
namespace tasks {

struct LoopEstimate
{
  rmf_traffic::Time time = rmf_traffic::Time::max();
  RobotContextPtr robot = nullptr;
  rmf_utils::optional<rmf_traffic::agv::Plan::Start> init_start;
  rmf_utils::optional<rmf_traffic::agv::Plan::Start> loop_start;
  rmf_utils::optional<rmf_traffic::agv::Plan::Start> loop_end;
};

rmf_utils::optional<LoopEstimate> estimate_loop(
    const rmf_task_msgs::msg::Loop& request,
    const std::shared_ptr<agv::FleetUpdateHandle>& fleet);

//==============================================================================
std::shared_ptr<Task> make_loop(const rmf_task_msgs::msg::Loop& request,
    const agv::RobotContextPtr& context,
    rmf_utils::optional<rmf_traffic::agv::Plan::Start> init_start,
    rmf_traffic::agv::Plan::Start loop_start,
    rmf_utils::optional<rmf_traffic::agv::Plan::Start> loop_end);

} // namespace tasks
} // namespace rmf_fleet_adapter

#endif // SRC__RMF_FLEET_ADAPTER__TASKS__LOOP_HPP
