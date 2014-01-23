#ifndef ros_led_keepon_KeeponMessage_h
#define ros_led_keepon_KeeponMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../ros/msg.h"

namespace led_keepon
{

  class KeeponMessage : public ros::Msg
  {
    public:
      long device;
      long cmd1;
      long cmd0;

    virtual int serialize(unsigned char *outbuffer)
    {
      int offset = 0;
      union {
        long real;
        unsigned long base;
      } u_device;
      u_device.real = this->device;
      *(outbuffer + offset + 0) = (u_device.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_device.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_device.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device);
      union {
        long real;
        unsigned long base;
      } u_cmd1;
      u_cmd1.real = this->cmd1;
      *(outbuffer + offset + 0) = (u_cmd1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmd1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cmd1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cmd1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd1);
      union {
        long real;
        unsigned long base;
      } u_cmd0;
      u_cmd0.real = this->cmd0;
      *(outbuffer + offset + 0) = (u_cmd0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmd0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cmd0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cmd0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd0);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        long real;
        unsigned long base;
      } u_device;
      u_device.base = 0;
      u_device.base |= ((typeof(u_device.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device.base |= ((typeof(u_device.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_device.base |= ((typeof(u_device.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_device.base |= ((typeof(u_device.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->device = u_device.real;
      offset += sizeof(this->device);
      union {
        long real;
        unsigned long base;
      } u_cmd1;
      u_cmd1.base = 0;
      u_cmd1.base |= ((typeof(u_cmd1.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmd1.base |= ((typeof(u_cmd1.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cmd1.base |= ((typeof(u_cmd1.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cmd1.base |= ((typeof(u_cmd1.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cmd1 = u_cmd1.real;
      offset += sizeof(this->cmd1);
      union {
        long real;
        unsigned long base;
      } u_cmd0;
      u_cmd0.base = 0;
      u_cmd0.base |= ((typeof(u_cmd0.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmd0.base |= ((typeof(u_cmd0.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cmd0.base |= ((typeof(u_cmd0.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cmd0.base |= ((typeof(u_cmd0.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cmd0 = u_cmd0.real;
      offset += sizeof(this->cmd0);
     return offset;
    }

    const char * getType(){ return "led_keepon/KeeponMessage"; };

  };

}
#endif