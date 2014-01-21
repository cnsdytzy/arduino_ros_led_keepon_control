FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/led_keepon/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/LEDMessage.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_LEDMessage.lisp"
  "../msg_gen/lisp/ScenarioTrigger.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_ScenarioTrigger.lisp"
  "../msg_gen/lisp/KeeponMessage.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_KeeponMessage.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
