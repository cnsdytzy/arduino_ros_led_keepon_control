#!/usr/bin/env python
import roslib; roslib.load_manifest('led_keepon')
import rospy
from led_keepon.msg import *
from keepon_manager import KeeponManager
from led_manager import LEDManager


keepon_mgr = None
led_mgr = None

def val_constrain(val, low, high):
  if val < low:
    return low
  if val > high:
    return high
  return val

def val_map(val, fromLow, fromHigh, toLow, toHigh, asFloat=False):
  val = val_constrain(val, fromLow, fromHigh)
  return (int)((val - fromLow)/1.0/(fromHigh - fromLow)*(toHigh - toLow) + toLow)

def handle_trigger(scenario_trigger):
  rospy.loginfo(rospy.get_name() + ": I heard %s" % scenario_trigger.scenario)
  handle_trigger_keepon(scenario_trigger)
  handle_trigger_led(scenario_trigger)

def handle_trigger_led(scenario_trigger):
  GREEN = (0,127,0)
  ORANGE = (127,15,0)
  YELLOW = (127,127,0)
  DIM_YELLOW = (30,30,0)
  NONE = (0,0,0)
  WHITE = (127,127,127)
  if scenario_trigger.scenario == "None":
    led_mgr.publishMessage(led_state=1, color1=GREEN)
  elif scenario_trigger.scenario == "Turn Corner":
    led_mgr.publishMessage(led_state=2, led_param1=val_constrain(scenario_trigger.param, -180, 180), color1=ORANGE)
  elif scenario_trigger.scenario == "Obstacle":
    led_mgr.publishMessage(led_state=3, led_param1= val_constrain(scenario_trigger.param, -180, 180), color1=ORANGE, color2=DIM_YELLOW)
  elif scenario_trigger.scenario == "Back Up":
    led_mgr.publishMessage(led_state=4, color1=WHITE, color2=DIM_YELLOW)
  elif scenario_trigger.scenario == "Brake":
    led_mgr.publishMessage(led_state=5, color1=ORANGE)
  print "Published LED Message"

def handle_trigger_keepon(scenario_trigger):
  keepon_mgr.stop_movement()
  if scenario_trigger.scenario == "None":
    keepon_mgr.turn_to_center()
  elif scenario_trigger.scenario == "Turn Corner":
    if scenario_trigger.param > 0:
      keepon_mgr.move_pan(50)
    else:
      keepon_mgr.move_pan(-50)
  elif scenario_trigger.scenario == "Obstacle":
    panTo = val_map(val_constrain(scenario_trigger.param, -180, 180), -180, 180, -100, 100)
    keepon_mgr.move_pan(panTo)
    keepon_mgr.move_side_cycle()
  elif scenario_trigger.scenario == "Back Up":
    keepon_mgr.move_pan(-90)
    keepon_mgr.move_side_right()
  elif scenario_trigger.scenario == "Brake":
    keepon_mgr.move_tilt(-100)


def listen_for_triggers():
  rospy.init_node('qcbot_scenario_trigger_listener', anonymous=True)
  rospy.Subscriber('qcbot_scenario_triggers', ScenarioTrigger, handle_trigger)
  rospy.spin()

if __name__ == '__main__':
  keepon_mgr = KeeponManager(rospy.Publisher("qcbot_keepon_commands", KeeponMessage))
  led_mgr = LEDManager(rospy.Publisher("qcbot_led_commands",LEDMessage))
  listen_for_triggers()
