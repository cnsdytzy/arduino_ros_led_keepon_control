FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/led_keepon/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/led_keepon/msg/__init__.py"
  "../src/led_keepon/msg/_LEDMessage.py"
  "../src/led_keepon/msg/_ScenarioTrigger.py"
  "../src/led_keepon/msg/_KeeponMessage.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
