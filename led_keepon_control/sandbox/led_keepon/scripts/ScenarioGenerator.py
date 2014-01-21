#! /usr/bin/env python
import rospy
import roslib; roslib.load_manifest('led_keepon')
from led_keepon.msg import *

def generator():
  pub = rospy.Publisher('Scenarios', ScenarioTrigger)
  rospy.init_node('generator')
  while not rospy.is_shutdown():
    trigger = ScenarioTrigger()
    trigger.scenario = "Scenario " + str(rospy.get_time())
    trigger.param = 2
    rospy.loginfo("I published a " + trigger.scenario)
    pub.publish(trigger)
    rospy.sleep(1.0)

if __name__ == '__main__':
  try:
    generator()
  except rospy.ROSInterruptException:
    pass
