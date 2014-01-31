arduino_ros_led_keepon_control
==============================

Vecna extern project - using ROS and Arduino to control LED strip and Keepon robot

# Contents

This repo contains the following:

1) **LEDKeepon.ino** - this is the sketch you should upload to the arduino. It allows control of the Keepon and the LED strip. In order to use, make sure you set the correct number of leds and enable the keepon and led.

`const int LED_NUM_LEDS = 65;`

`const boolean ENABLE_KEEPON = true;`

`const boolean ENABLE_LEDS = true;`

2) **led_keepon_ws**: This is the ROS fuerte workspace that contains the nodes we need. The key item here is the `ScenarioProcessor.py` script in the `led_keepon` package.

##### MAKE SURE THAT YOU HAVE THE ROS PACKAGES `rosserial` and `rosbridge-suite`

3) **web_interface**: There are three important files here:

`publisher.html`: This is a web page that triggers the scenarios
`subscriber.html`: This the web page which is displayed on the screen of the QCBot
`scenario_publisher.py`: This is a script which triggers the scenarios (if you don't want to use `publisher.html`)

4) **ros_lib**: Contains the ROS libraries you should put into your Arduino library folder

5) **TimedAction**: Contains libraries which is used to concurrently control Keepon and LEDs, you should put it into your Arduino library folder

# Usage

1) Include the `TimedAction` and `ros_lib` libraries and upload the sketch and connect LED and Keepon

2) Use files in `led_keepon_ws` to set up a ROS fuerte package

3) Launch ROS core - `roscore`

4) Launch ROS API - `rosrun rosapi rosapi.py`

5) Launch ROS bridge - `roslaunch rosbridge_server rosbridge_websocket.launch` (if it doesn't work, you may not need to use `rosrun rosapi rosapi.py`)

6) Launch ROS serial - `rosrun rosserial_python serial_node.py /dev/ttyUSB0` (change according to the port Arduino is plugged into)

7) Open `web_interface/subscriber.html` in your browser

8) Trigger scenarios either with `web_interface/publisher.html` or `web_interface/scenario_publisher.py`


