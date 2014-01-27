#ifndef ros_led_keepon_LEDMessage_h
#define ros_led_keepon_LEDMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../ros/msg.h"

namespace led_keepon
{

  class LEDMessage : public ros::Msg
  {
    public:
      long led_state;
      long freq;
      long led_param1;
      long color1[3];
      long led_param2;
      long color2[3];

    virtual int serialize(unsigned char *outbuffer)
    {
      int offset = 0;
      union {
        long real;
        unsigned long base;
      } u_led_state;
      u_led_state.real = this->led_state;
      *(outbuffer + offset + 0) = (u_led_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_state);
      union {
        long real;
        unsigned long base;
      } u_freq;
      u_freq.real = this->freq;
      *(outbuffer + offset + 0) = (u_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->freq);
      union {
        long real;
        unsigned long base;
      } u_led_param1;
      u_led_param1.real = this->led_param1;
      *(outbuffer + offset + 0) = (u_led_param1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led_param1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led_param1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led_param1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_param1);
      unsigned char * color1_val = (unsigned char *) this->color1;
      for( unsigned char i = 0; i < 3; i++){
      union {
        long real;
        unsigned long base;
      } u_color1i;
      u_color1i.real = this->color1[i];
      *(outbuffer + offset + 0) = (u_color1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_color1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_color1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_color1i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->color1[i]);
      }
      union {
        long real;
        unsigned long base;
      } u_led_param2;
      u_led_param2.real = this->led_param2;
      *(outbuffer + offset + 0) = (u_led_param2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led_param2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led_param2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led_param2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_param2);
      unsigned char * color2_val = (unsigned char *) this->color2;
      for( unsigned char i = 0; i < 3; i++){
      union {
        long real;
        unsigned long base;
      } u_color2i;
      u_color2i.real = this->color2[i];
      *(outbuffer + offset + 0) = (u_color2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_color2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_color2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_color2i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->color2[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        long real;
        unsigned long base;
      } u_led_state;
      u_led_state.base = 0;
      u_led_state.base |= ((typeof(u_led_state.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led_state.base |= ((typeof(u_led_state.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led_state.base |= ((typeof(u_led_state.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led_state.base |= ((typeof(u_led_state.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led_state = u_led_state.real;
      offset += sizeof(this->led_state);
      union {
        long real;
        unsigned long base;
      } u_freq;
      u_freq.base = 0;
      u_freq.base |= ((typeof(u_freq.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_freq.base |= ((typeof(u_freq.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_freq.base |= ((typeof(u_freq.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_freq.base |= ((typeof(u_freq.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->freq = u_freq.real;
      offset += sizeof(this->freq);
      union {
        long real;
        unsigned long base;
      } u_led_param1;
      u_led_param1.base = 0;
      u_led_param1.base |= ((typeof(u_led_param1.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led_param1.base |= ((typeof(u_led_param1.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led_param1.base |= ((typeof(u_led_param1.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led_param1.base |= ((typeof(u_led_param1.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led_param1 = u_led_param1.real;
      offset += sizeof(this->led_param1);
      unsigned char * color1_val = (unsigned char *) this->color1;
      for( unsigned char i = 0; i < 3; i++){
      union {
        long real;
        unsigned long base;
      } u_color1i;
      u_color1i.base = 0;
      u_color1i.base |= ((typeof(u_color1i.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_color1i.base |= ((typeof(u_color1i.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_color1i.base |= ((typeof(u_color1i.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_color1i.base |= ((typeof(u_color1i.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->color1[i] = u_color1i.real;
      offset += sizeof(this->color1[i]);
      }
      union {
        long real;
        unsigned long base;
      } u_led_param2;
      u_led_param2.base = 0;
      u_led_param2.base |= ((typeof(u_led_param2.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led_param2.base |= ((typeof(u_led_param2.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led_param2.base |= ((typeof(u_led_param2.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led_param2.base |= ((typeof(u_led_param2.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led_param2 = u_led_param2.real;
      offset += sizeof(this->led_param2);
      unsigned char * color2_val = (unsigned char *) this->color2;
      for( unsigned char i = 0; i < 3; i++){
      union {
        long real;
        unsigned long base;
      } u_color2i;
      u_color2i.base = 0;
      u_color2i.base |= ((typeof(u_color2i.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_color2i.base |= ((typeof(u_color2i.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_color2i.base |= ((typeof(u_color2i.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_color2i.base |= ((typeof(u_color2i.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->color2[i] = u_color2i.real;
      offset += sizeof(this->color2[i]);
      }
     return offset;
    }

    const char * getType(){ return "led_keepon/LEDMessage"; };

  };

}
#endif