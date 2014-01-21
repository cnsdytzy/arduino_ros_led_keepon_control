
(cl:in-package :asdf)

(defsystem "led_keepon-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "LEDMessage" :depends-on ("_package_LEDMessage"))
    (:file "_package_LEDMessage" :depends-on ("_package"))
    (:file "ScenarioTrigger" :depends-on ("_package_ScenarioTrigger"))
    (:file "_package_ScenarioTrigger" :depends-on ("_package"))
    (:file "KeeponMessage" :depends-on ("_package_KeeponMessage"))
    (:file "_package_KeeponMessage" :depends-on ("_package"))
  ))