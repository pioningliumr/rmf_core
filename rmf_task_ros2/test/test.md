# Test Instructions
Brief instruction to test dispatcher component

## Unit Test
```bash
./build/rmf_task_ros2/test_rmf_task_ros2
```

## Dispatcher Node Test
```bash
# Terminal 1
ros2 run rmf_task_ros2 rmf_task_dispatcher

# Terminal 2
ros2 run rmf_task_ros2 rmf_bidder_node server1
```

```bash
# Submit Task
ros2 service call /submit_task rmf_task_msgs/SubmitTask \
"{type:{value: 3}, params: [{ name: 'zone', value: 'area51' }] }"

# Get Task
ros2 service call /get_task rmf_task_msgs/GetTask \ "{ task_id: []}"

# Cancel Task
ros2 service call /cancel_task rmf_task_msgs/CancelTask \
"{ task_id: 'test1' }"
```

## Docker usage
```bash
docker build -t tanyouliang95/rmf_core:task-dispatcher  .
docker run -it tanyouliang95/rmf_core:task-dispatcher ros2 run rmf_task_ros2 rmf_task_dispatcher
```

## Sample dispatcher with mongo
 - https://github.com/tanyouliang95/rmf_web_server