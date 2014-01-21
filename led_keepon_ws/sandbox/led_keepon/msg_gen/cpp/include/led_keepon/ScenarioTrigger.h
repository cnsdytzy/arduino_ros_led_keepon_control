/* Auto-generated by genmsg_cpp for file /net/home4/harihar.subramanyam/sketchbook/LEDKeepon/led_keepon_ws/sandbox/led_keepon/msg/ScenarioTrigger.msg */
#ifndef LED_KEEPON_MESSAGE_SCENARIOTRIGGER_H
#define LED_KEEPON_MESSAGE_SCENARIOTRIGGER_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace led_keepon
{
template <class ContainerAllocator>
struct ScenarioTrigger_ {
  typedef ScenarioTrigger_<ContainerAllocator> Type;

  ScenarioTrigger_()
  : scenario()
  , param(0)
  {
  }

  ScenarioTrigger_(const ContainerAllocator& _alloc)
  : scenario(_alloc)
  , param(0)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _scenario_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  scenario;

  typedef int32_t _param_type;
  int32_t param;


  typedef boost::shared_ptr< ::led_keepon::ScenarioTrigger_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::led_keepon::ScenarioTrigger_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ScenarioTrigger
typedef  ::led_keepon::ScenarioTrigger_<std::allocator<void> > ScenarioTrigger;

typedef boost::shared_ptr< ::led_keepon::ScenarioTrigger> ScenarioTriggerPtr;
typedef boost::shared_ptr< ::led_keepon::ScenarioTrigger const> ScenarioTriggerConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::led_keepon::ScenarioTrigger_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::led_keepon::ScenarioTrigger_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace led_keepon

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::led_keepon::ScenarioTrigger_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::led_keepon::ScenarioTrigger_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::led_keepon::ScenarioTrigger_<ContainerAllocator> > {
  static const char* value() 
  {
    return "e7645c66f3cdaa3638affc6441ae0686";
  }

  static const char* value(const  ::led_keepon::ScenarioTrigger_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xe7645c66f3cdaa36ULL;
  static const uint64_t static_value2 = 0x38affc6441ae0686ULL;
};

template<class ContainerAllocator>
struct DataType< ::led_keepon::ScenarioTrigger_<ContainerAllocator> > {
  static const char* value() 
  {
    return "led_keepon/ScenarioTrigger";
  }

  static const char* value(const  ::led_keepon::ScenarioTrigger_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::led_keepon::ScenarioTrigger_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string scenario\n\
int32 param\n\
\n\
";
  }

  static const char* value(const  ::led_keepon::ScenarioTrigger_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::led_keepon::ScenarioTrigger_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.scenario);
    stream.next(m.param);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ScenarioTrigger_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::led_keepon::ScenarioTrigger_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::led_keepon::ScenarioTrigger_<ContainerAllocator> & v) 
  {
    s << indent << "scenario: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.scenario);
    s << indent << "param: ";
    Printer<int32_t>::stream(s, indent + "  ", v.param);
  }
};


} // namespace message_operations
} // namespace ros

#endif // LED_KEEPON_MESSAGE_SCENARIOTRIGGER_H
