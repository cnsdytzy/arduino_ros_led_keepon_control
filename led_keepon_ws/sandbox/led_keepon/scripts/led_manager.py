import rospy
import roslib; roslib.load_manifest('led_keepon')
from led_keepon.msg import *

class LEDManager:
  def __init__(self, publisher):
    self.publisher = publisher
  def publishMessage(self, led_state="Error", freq=1, led_param1=0, color1=(0,0,0), led_param2=0, color2=(0,0,0)):
    msg = LEDMessage()
    msg.led_state = led_state
    msg.freq = freq
    msg.led_param1 = led_param1
    msg.color1 = color1
    msg.led_param2 = led_param2
    msg.color2 = color2
    print msg
    self.publisher.publish(msg)
