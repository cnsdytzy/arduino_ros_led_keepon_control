#ifndef ros_led_keepon_ScenarioTrigger_h
#define ros_led_keepon_ScenarioTrigger_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../ros/msg.h"

namespace led_keepon
{

  class ScenarioTrigger : public ros::Msg
  {
    public:
      char * scenario;
      long param;

    virtual int serialize(unsigned char *outbuffer)
    {
      int offset = 0;
      long * length_scenario = (long *)(outbuffer + offset);
      *length_scenario = strlen( (const char*) this->scenario);
      offset += 4;
      memcpy(outbuffer + offset, this->scenario, *length_scenario);
      offset += *length_scenario;
      union {
        long real;
        unsigned long base;
      } u_param;
      u_param.real = this->param;
      *(outbuffer + offset + 0) = (u_param.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_param.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_param.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_param.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->param);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_scenario = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_scenario; ++k){
          inbuffer[k-1]=inbuffer[k];
           }
      inbuffer[offset+length_scenario-1]=0;
      this->scenario = (char *)(inbuffer + offset-1);
      offset += length_scenario;
      union {
        long real;
        unsigned long base;
      } u_param;
      u_param.base = 0;
      u_param.base |= ((typeof(u_param.base)) (*(inbuffer + offset + 0))) << (8 * 0);
      u_param.base |= ((typeof(u_param.base)) (*(inbuffer + offset + 1))) << (8 * 1);
      u_param.base |= ((typeof(u_param.base)) (*(inbuffer + offset + 2))) << (8 * 2);
      u_param.base |= ((typeof(u_param.base)) (*(inbuffer + offset + 3))) << (8 * 3);
      this->param = u_param.real;
      offset += sizeof(this->param);
     return offset;
    }

    const char * getType(){ return "led_keepon/ScenarioTrigger"; };

  };

}
#endif