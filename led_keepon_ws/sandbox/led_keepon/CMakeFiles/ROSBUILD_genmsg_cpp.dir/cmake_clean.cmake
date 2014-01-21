FILE(REMOVE_RECURSE
  "msg_gen"
  "src/led_keepon/msg"
  "msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "msg_gen/cpp/include/led_keepon/LEDMessage.h"
  "msg_gen/cpp/include/led_keepon/KeeponMessage.h"
  "msg_gen/cpp/include/led_keepon/ScenarioTrigger.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
