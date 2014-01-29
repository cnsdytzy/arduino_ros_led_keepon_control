import rospy
import roslib; roslib.load_manifest('led_keepon')
from led_keepon.msg import *

class KeeponManager:
  def __init__(self, publisher):
    self.publisher = publisher
  def publishMessage(self, cmd0, cmd1, device):
    msg = KeeponMessage()
    msg.cmd1 = cmd1
    msg.cmd0 = cmd0
    msg.device = device
    self.publisher.publish(msg)
  def sound_play(self, soundNum):
    self.publishMessage(0x01, 0b10000000 | (63 & soundNum), 0b11111111 & 0x52)
  def sound_repeat(self, soundNum):
    self.publishMessage(0x01, 0b11000000 | (63 & soundNum), 0b11111111 & 0x52) 
  def sound_delay(self, msec):
    self.publishMessage(0x03, 0b11111111 & soundNum, 0b11111111 & 0x52)
  def sound_stop(self):
    self.publishMessage(0x01, 0b00000000, 0b11111111 & 0x52)
  def speed_pan(self, speed):
    self.publishMessage(5, 0b11111111 & speed, 0b11111111 & 0x55)
  def speed_tilt(self, speed):
    self.publishMessage(3, 0b11111111 & speed, 0b11111111 & 0x55)
  def speed_ponside(self, speed):
    self.publishMessage(1, 0b11111111 & speed, 0b11111111 & 0x55)
  def move_pan(self, angle):
    self.publishMessage(4, 0b11111111 & (angle + 127), 0b11111111 & 0x55)
  def move_tilt(self, angle):
    self.publishMessage(2, 0b11111111 & (angle + 127), 0b11111111 & 0x55)
  def move_side_cycle(self):
    self.publishMessage(0,0, 0b11111111 & 0x55)
  def move_side_centerfromleft(self):
    self.publishMessage(0,1, 0b11111111 & 0x55)
  def move_side_right(self):
    self.publishMessage(0,2, 0b11111111 & 0x55)
  def move_side_centerfromright(self):
    self.publishMessage(0,3, 0b11111111 & 0x55)
  def move_side_left(self):
    self.publishMessage(0,4, 0b11111111 & 0x55)
  def move_pon_up(self):
    self.publishMessage(0,-1, 0b11111111 & 0x55)
  def move_pon_halfdown(self):
    self.publishMessage(0,-2, 0b11111111 & 0x55)
  def move_pon_down(self):
    self.publishMessage(0,-3, 0b11111111 & 0x55)
  def move_pon_halfup(self):
    self.publishMessage(0,-4, 0b11111111 & 0x55)
  def move_stop(self):
    self.publishMessage(6,16, 0b11111111 & 0x55)
  def mode_dance(self):
    self.publishMessage(6,0, 0b11111111 & 0x55)
  def mode_touch(self):
    self.publishMessage(6,1, 0b11111111 & 0x55)
  def move_tempo(self):
    self.publishMessage(6,2, 0b11111111 & 0x55)
  def mode_sleep(self):
    self.publishMessage(6,240, 0b11111111 & 0x55)
  def stop_movement(self):
    self.move_side_centerfromright()
    self.move_tilt(30)
  def turn_to_center(self):
    self.move_pan(0)


