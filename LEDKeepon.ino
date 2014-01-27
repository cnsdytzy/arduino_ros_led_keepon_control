/*
  Author: Harihar Subramanyam
*/

/* Imports */

#include <ros.h>
#include <led_keepon/KeeponMessage.h>
#include <led_keepon/LEDMessage.h>
#include <std_msgs/String.h>
#include <Wire.h>
#include "LPD8806.h"
#include "SPI.h"
#include "TimedAction.h"

/* Defines */

#define LED_NUM_LEDS 32 // TODO - turn this to appropriate number
#define LED_DATA_PIN 3
#define LED_CLOCK_PIN 4
#define LED_ZERO_OFFSET 0
#define LED_SPOT_RADIUS 1

#define LED_STATE_NONE 1
#define LED_STATE_TURNCORNER 2
#define LED_STATE_OBSTACLE 3
#define LED_STATE_BACKUP 4
#define LED_STATE_BRAKE 5


#define LED_COLOR_NONE strip.Color(0,0,0)

#define LED_PIN 13
#define MK_FREQ 49600L

#define LOG(X) log_msg.data = X; log_pub.publish(&log_msg);

LPD8806 strip = LPD8806(LED_NUM_LEDS, LED_DATA_PIN, LED_CLOCK_PIN);

ros::NodeHandle nh;

byte device;
byte cmd[2];

int led_state_as_int;

int led_state_param1;
int led_state_param2;
uint32_t led_state_color1;
uint32_t led_state_color2;
int led_state_freq;

TimedAction taLEDAction = TimedAction(100, led_act);

std_msgs::String log_msg;
ros::Publisher log_pub("arduino_logs", &log_msg);

void keepon_message_cb(const led_keepon::KeeponMessage& msg);
void led_message_cb(const led_keepon::LEDMessage& msg);
ros::Subscriber<led_keepon::KeeponMessage> keepon_sub("qcbot_keepon_commands",&keepon_message_cb);
ros::Subscriber<led_keepon::LEDMessage> led_sub("qcbot_led_commands",&led_message_cb);

/* LED Stuff */

// Turn State
boolean led_state_turnCorner_blinkerOn;
int led_state_turnCorner_blinkerIndex;

// None State
boolean led_state_none_countingUp;
int led_state_none_colorCounter;
int led_state_none_r;
int led_state_none_g;
int led_state_none_b;

// Obstacle State
int led_state_obstacle_angle;
int led_state_obstacle_index;

// Backup State
boolean led_state_backup_blinkerOn;


/* ROS Callback */

void keepon_message_cb(const led_keepon::KeeponMessage& msg){
  device = (byte)msg.device;
  cmd[0] = (byte)msg.cmd0;
  cmd[1] = (byte)msg.cmd1;
  keepon_transmit();
}

void led_message_cb(const led_keepon::LEDMessage& msg){
  LOG("Received state...");
  led_state_param1 = msg.led_param1;
  led_state_param2 = msg.led_param2;
  led_state_color1 = strip.Color(msg.color1[0], msg.color1[1], msg.color1[2]);
  led_state_color2 = strip.Color(msg.color2[0], msg.color2[1], msg.color2[2]);
  led_state_freq = msg.freq;
  led_state_as_int = msg.led_state;
  led_state_changed();
}


void setup(){
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);
  
  nh.subscribe(keepon_sub);
  nh.subscribe(led_sub);
  nh.advertise(log_pub);
  nh.initNode();
  keepon_setup();
  pinMode(LED_PIN, OUTPUT);
  led_setup();
}

void loop(){
  taLEDAction.check();
  nh.spinOnce();
  delay(1);
}

/* Keepon Stuff */
void keepon_setup(){
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);
  while(analogRead(0) < 512);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  Wire.begin();
  TWBR = ((F_CPU / MK_FREQ) - 16) / 2;
}

void keepon_transmit(){
  while(analogRead(0) < 512);
  int result = 1;
  int attempts = 0;
  while(result != 0 && attempts++ < 50){
    Wire.beginTransmission(device);
    Wire.write((byte)cmd[0]);
    Wire.write((byte)cmd[1]);
    result = (int)Wire.endTransmission();
  }
}


void led_setup(){
  strip.begin();
  strip.show();
  led_state_as_int = LED_STATE_NONE;
  led_state_color1 = strip.Color(0,127,0);
  led_state_changed();
}

void led_act(){
  switch(led_state_as_int){
    case LED_STATE_TURNCORNER: led_act_turncorner(); break;
    case LED_STATE_OBSTACLE: led_act_obstacle(); break;
    case LED_STATE_BACKUP: led_act_backup(); break;
    case LED_STATE_BRAKE: break;
    case LED_STATE_NONE: led_act_none(); break;
    default: break;
  }
}

void led_act_none(){
  //led_color_strip(strip.Color(constrain(led_state_none_r - led_state_none_colorCounter,0,127),constrain(led_state_none_g - led_state_none_colorCounter,0,127), constrain(led_state_none_b - led_state_none_colorCounter,0,127)));
  led_color_strip(strip.Color(constrain(constrain(led_state_none_r,0,127)- led_state_none_colorCounter,0,127),constrain(constrain(led_state_none_g,0,127) - led_state_none_colorCounter, 0, 127), constrain(constrain(led_state_none_b,0,127)- led_state_none_colorCounter,0,127)));
  strip.show();
  if(led_state_none_countingUp){
    led_state_none_colorCounter++;
    if(led_state_none_colorCounter >= 127){
      led_state_none_colorCounter--;
      led_state_none_countingUp = false;
    }
  }else{
    led_state_none_colorCounter--;
    if(led_state_none_colorCounter <= -1){
      led_state_none_colorCounter++;
      led_state_none_countingUp = true;
    }
  }
}

void led_act_turncorner(){
   if(led_state_turnCorner_blinkerOn){
     led_draw_spot(led_state_turnCorner_blinkerIndex, led_state_color1);
   }else{
     led_color_strip(LED_COLOR_NONE);
   }
   strip.show();
   led_state_turnCorner_blinkerOn = !led_state_turnCorner_blinkerOn;
}

void led_act_obstacle(){
  led_color_strip(LED_COLOR_NONE);
  led_draw_spot(led_state_obstacle_angle, led_state_color2);
  if(led_state_obstacle_index >= strip.numPixels()/2 -1){
    led_state_obstacle_index = 0;
  }
  
  strip.setPixelColor((LED_ZERO_OFFSET + (led_state_obstacle_angle + strip.numPixels()/2) + led_state_obstacle_index)%strip.numPixels(), led_state_color1);
  strip.setPixelColor((LED_ZERO_OFFSET + (led_state_obstacle_angle + strip.numPixels()/2) - led_state_obstacle_index)%strip.numPixels(), led_state_color1);
  strip.setPixelColor((LED_ZERO_OFFSET + (led_state_obstacle_angle + strip.numPixels()/2) + led_state_obstacle_index - 1)%strip.numPixels(), led_state_color1);
  strip.setPixelColor((LED_ZERO_OFFSET + (led_state_obstacle_angle + strip.numPixels()/2) - led_state_obstacle_index + 1)%strip.numPixels(), led_state_color1);
  led_state_obstacle_index++;
  strip.show();
}

void led_act_backup(){
  int i;
  
  int leftTailBlinkerIndex = (strip.numPixels()*3/8 + LED_ZERO_OFFSET)%strip.numPixels();
  int rightTailBlinkerIndex = (strip.numPixels()*5/8 + LED_ZERO_OFFSET)%strip.numPixels();
  
  led_color_strip((led_state_backup_blinkerOn) ? led_state_color2 : LED_COLOR_NONE);
  led_draw_spot(leftTailBlinkerIndex,led_state_color1);
  led_draw_spot(rightTailBlinkerIndex,led_state_color1);
  led_state_backup_blinkerOn = !led_state_backup_blinkerOn;
  strip.show();
}

void led_state_changed(){
  led_color_strip(LED_COLOR_NONE);
  if(led_state_as_int == LED_STATE_TURNCORNER){
    led_state_turnCorner_blinkerOn = false;
    if(constrain(led_state_param1, -180, 180) >= 0){
      led_state_turnCorner_blinkerIndex = (strip.numPixels()/8+LED_ZERO_OFFSET)%strip.numPixels();
    }else{
      led_state_turnCorner_blinkerIndex = (strip.numPixels()*7/8+LED_ZERO_OFFSET)%strip.numPixels();
    }
    taLEDAction.setInterval(500);
  }else if(led_state_as_int == LED_STATE_OBSTACLE){
    led_state_obstacle_angle = (int)map(constrain(led_state_param1, -180, 180), -180, 180, 0, strip.numPixels());
    led_state_obstacle_index = 0;
    taLEDAction.setInterval(1000/strip.numPixels());
  }else if(led_state_as_int == LED_STATE_BRAKE){
    int leftTailBlinkerIndex = (strip.numPixels()*3/8 + LED_ZERO_OFFSET)%strip.numPixels();
    int rightTailBlinkerIndex = (strip.numPixels()*5/8 + LED_ZERO_OFFSET)%strip.numPixels();
    led_draw_spot(leftTailBlinkerIndex, led_state_color1);
    led_draw_spot(rightTailBlinkerIndex, led_state_color1);
    strip.show();
  }else if(led_state_as_int == LED_STATE_BACKUP){
    led_state_backup_blinkerOn = false;
    taLEDAction.setInterval(500);
  }else if(led_state_as_int == LED_STATE_NONE){
    led_state_none_countingUp = true;
    led_state_none_colorCounter = 0;
    led_state_none_g = (led_state_color1 >> 16) | 0x80;
    led_state_none_r = (led_state_color1 >> 8) | 0x80;
    led_state_none_b = led_state_color1 | 0x80;
    taLEDAction.setInterval(500/127);
  }
}

void led_color_strip(uint32_t color){
  int i;
  for(i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, color);
  }
}

void led_draw_spot(int index, uint32_t color){
  int i;
  for(i = -1*LED_SPOT_RADIUS; i <= LED_SPOT_RADIUS; i++){
    strip.setPixelColor((i+index+LED_ZERO_OFFSET)%strip.numPixels(), color);
  }
}
