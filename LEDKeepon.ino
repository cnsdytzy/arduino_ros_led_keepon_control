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

#define LED_DATA_PIN 2
#define LED_CLOCK_PIN 3


#define LED_SPOT_RADIUS 0

#define LED_STATE_NONE 1
#define LED_STATE_TURNCORNER 2
#define LED_STATE_OBSTACLE 3
#define LED_STATE_BACKUP 4
#define LED_STATE_BRAKE 5

#define LED_COLOR_NONE strip.Color(0,0,0)

#define LED_PIN 13
#define MK_FREQ 49600L

#define LOG(X) log_msg.data = X; log_pub.publish(&log_msg);


const int LED_NUM_LEDS = 12;
const boolean ENABLE_KEEPON = false;
const boolean ENABLE_LEDS = true;

const float LED_SCALE = ((float)LED_NUM_LEDS)/12.0f;
const float F_A = 45.0f/2.0f;
const float T_A = 45.0f;
const int LED_ZERO_OFFSET = (int)(LED_SCALE * 10);
const int LED_N = ((int)(LED_SCALE*0))%LED_NUM_LEDS;
const int LED_FR = ((int)(LED_SCALE*1))%LED_NUM_LEDS;
const int LED_NE = ((int)(LED_SCALE*2-LED_SPOT_RADIUS-1))%LED_NUM_LEDS;
const int LED_E = ((int)(LED_SCALE*3))%LED_NUM_LEDS;
const int LED_SE = ((int)(LED_SCALE*4))%LED_NUM_LEDS;
const int LED_BR = ((int)(LED_SCALE*5))%LED_NUM_LEDS;
const int LED_S = ((int)(LED_SCALE*6))%LED_NUM_LEDS;
const int LED_BL = ((int)(LED_SCALE*7))%LED_NUM_LEDS;
const int LED_SW = ((int)(LED_SCALE*8))%LED_NUM_LEDS;
const int LED_W = ((int)(LED_SCALE*9))%LED_NUM_LEDS;
const int LED_NW = ((int)(LED_SCALE*10))%LED_NUM_LEDS;
const int LED_FL = ((int)(LED_SCALE*11))%LED_NUM_LEDS;

void keepon_message_cb(const led_keepon::KeeponMessage& msg);
void led_message_cb(const led_keepon::LEDMessage& msg);
void led_act();
void keepon_transmit();
void led_state_changed();
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
  led_state_param1 = msg.led_param1;
  led_state_param2 = msg.led_param2;
  led_state_color1 = strip.Color(msg.color1[0], msg.color1[1], msg.color1[2]);
  led_state_color2 = strip.Color(msg.color2[0], msg.color2[1], msg.color2[2]);
  led_state_freq = msg.freq;
  led_state_as_int = msg.led_state;
  led_state_changed();
}


void setup(){
  if(ENABLE_KEEPON){
    pinMode(SDA, OUTPUT);
    pinMode(SCL, OUTPUT);
    nh.subscribe(keepon_sub);
  }
  
  if(ENABLE_LEDS){
    nh.subscribe(led_sub);
  }
  
  nh.advertise(log_pub);
  nh.initNode();
  
  if(ENABLE_KEEPON){
    keepon_setup();
  }
  pinMode(LED_PIN, OUTPUT);
  
  if(ENABLE_LEDS){
    led_setup();
  }
}

void loop(){
  if(ENABLE_LEDS){
    taLEDAction.check();
  }
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
  led_draw_spot(LED_BL,led_state_color1);
  led_draw_spot(LED_BR,led_state_color1);
  led_state_backup_blinkerOn = !led_state_backup_blinkerOn;
  strip.show();
}

void led_state_changed(){
  led_color_strip(LED_COLOR_NONE);
  if(led_state_as_int == LED_STATE_TURNCORNER){
    led_state_turnCorner_blinkerOn = false;
    if(constrain(led_state_param1, -180, 180) >= 0){
      LOG("Right Turn");
      led_state_turnCorner_blinkerIndex = LED_FR;//(strip.numPixels()/8+LED_ZERO_OFFSET)%strip.numPixels();
    }else{
      LOG("Left Turn");
      led_state_turnCorner_blinkerIndex = LED_FL;//(strip.numPixels()*7/8+LED_ZERO_OFFSET)%strip.numPixels();
    }
    taLEDAction.setInterval(500);
  }else if(led_state_as_int == LED_STATE_OBSTACLE){
    // led_state_obstacle_angle = (int)map(constrain(led_state_param1, -180, 180), -180, 180, 0, strip.numPixels());
    led_state_obstacle_angle = constrain(led_state_param1, -180, 180);
    if(led_state_obstacle_angle < 0){
      led_state_obstacle_angle += 360;
    }
    led_state_obstacle_angle = led_obstacle_direction_for_angle(led_state_obstacle_angle);
    led_state_obstacle_index = 0;
    taLEDAction.setInterval(1000/strip.numPixels());
  }else if(led_state_as_int == LED_STATE_BRAKE){
    LOG("Brake");
    int leftTailBlinkerIndex = (strip.numPixels()*3/8 + LED_ZERO_OFFSET)%strip.numPixels();
    int rightTailBlinkerIndex = (strip.numPixels()*5/8 + LED_ZERO_OFFSET)%strip.numPixels();
    led_draw_spot(LED_BR, led_state_color1);
    led_draw_spot(LED_BL, led_state_color1);
    strip.show();
  }else if(led_state_as_int == LED_STATE_BACKUP){
    LOG("Back Up");
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

int led_obstacle_direction_for_angle(int angle){
  if(angle >= F_A && angle < F_A + T_A){
    LOG("Obstacle NE");
    return LED_NE;
  }else if(angle >= F_A + T_A && angle < F_A + 2*T_A){
    LOG("Obstacle E");
    return LED_E;
  }else if(angle >= F_A + 2*T_A && angle < F_A + 3*T_A){
    LOG("Obstacle SE");
    return LED_SE;
  }else if(angle >= F_A + 3*T_A && angle < F_A + 4*T_A){
    LOG("Obstacle S");
    return LED_S;
  }else if(angle >= F_A + 4*T_A && angle < F_A + 5*T_A){
    LOG("Obstacle SW");
    return LED_SW;
  }else if(angle >= F_A + 5*T_A && angle < F_A + 6*T_A){
    LOG("Obstacle W");
    return LED_W;
  }else if(angle >= F_A + 6*T_A && angle < F_A + 7*T_A){
    LOG("Obstacle NW");
    return LED_NW;
  }else if((angle >= F_A + 7*T_A && angle < F_A + 8*T_A) || (angle >= 0 && angle < F_A)){
    LOG("Obstacle N");
    return LED_N;
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
