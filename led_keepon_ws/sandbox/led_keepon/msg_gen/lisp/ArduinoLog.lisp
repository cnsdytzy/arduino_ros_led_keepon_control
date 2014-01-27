; Auto-generated. Do not edit!


(cl:in-package led_keepon-msg)


;//! \htmlinclude ArduinoLog.msg.html

(cl:defclass <ArduinoLog> (roslisp-msg-protocol:ros-message)
  ((log_msg
    :reader log_msg
    :initarg :log_msg
    :type cl:string
    :initform ""))
)

(cl:defclass ArduinoLog (<ArduinoLog>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ArduinoLog>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ArduinoLog)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name led_keepon-msg:<ArduinoLog> is deprecated: use led_keepon-msg:ArduinoLog instead.")))

(cl:ensure-generic-function 'log_msg-val :lambda-list '(m))
(cl:defmethod log_msg-val ((m <ArduinoLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:log_msg-val is deprecated.  Use led_keepon-msg:log_msg instead.")
  (log_msg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ArduinoLog>) ostream)
  "Serializes a message object of type '<ArduinoLog>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'log_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'log_msg))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ArduinoLog>) istream)
  "Deserializes a message object of type '<ArduinoLog>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'log_msg) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'log_msg) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ArduinoLog>)))
  "Returns string type for a message object of type '<ArduinoLog>"
  "led_keepon/ArduinoLog")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ArduinoLog)))
  "Returns string type for a message object of type 'ArduinoLog"
  "led_keepon/ArduinoLog")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ArduinoLog>)))
  "Returns md5sum for a message object of type '<ArduinoLog>"
  "641fe53977762a02122b8183e1de22f0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ArduinoLog)))
  "Returns md5sum for a message object of type 'ArduinoLog"
  "641fe53977762a02122b8183e1de22f0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ArduinoLog>)))
  "Returns full string definition for message of type '<ArduinoLog>"
  (cl:format cl:nil "string log_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ArduinoLog)))
  "Returns full string definition for message of type 'ArduinoLog"
  (cl:format cl:nil "string log_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ArduinoLog>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'log_msg))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ArduinoLog>))
  "Converts a ROS message object to a list"
  (cl:list 'ArduinoLog
    (cl:cons ':log_msg (log_msg msg))
))
