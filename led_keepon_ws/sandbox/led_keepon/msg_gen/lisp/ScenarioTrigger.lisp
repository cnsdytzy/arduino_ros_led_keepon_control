; Auto-generated. Do not edit!


(cl:in-package led_keepon-msg)


;//! \htmlinclude ScenarioTrigger.msg.html

(cl:defclass <ScenarioTrigger> (roslisp-msg-protocol:ros-message)
  ((scenario
    :reader scenario
    :initarg :scenario
    :type cl:string
    :initform "")
   (param
    :reader param
    :initarg :param
    :type cl:integer
    :initform 0))
)

(cl:defclass ScenarioTrigger (<ScenarioTrigger>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ScenarioTrigger>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ScenarioTrigger)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name led_keepon-msg:<ScenarioTrigger> is deprecated: use led_keepon-msg:ScenarioTrigger instead.")))

(cl:ensure-generic-function 'scenario-val :lambda-list '(m))
(cl:defmethod scenario-val ((m <ScenarioTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:scenario-val is deprecated.  Use led_keepon-msg:scenario instead.")
  (scenario m))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <ScenarioTrigger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:param-val is deprecated.  Use led_keepon-msg:param instead.")
  (param m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ScenarioTrigger>) ostream)
  "Serializes a message object of type '<ScenarioTrigger>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'scenario))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'scenario))
  (cl:let* ((signed (cl:slot-value msg 'param)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ScenarioTrigger>) istream)
  "Deserializes a message object of type '<ScenarioTrigger>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'scenario) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'scenario) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'param) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ScenarioTrigger>)))
  "Returns string type for a message object of type '<ScenarioTrigger>"
  "led_keepon/ScenarioTrigger")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ScenarioTrigger)))
  "Returns string type for a message object of type 'ScenarioTrigger"
  "led_keepon/ScenarioTrigger")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ScenarioTrigger>)))
  "Returns md5sum for a message object of type '<ScenarioTrigger>"
  "e7645c66f3cdaa3638affc6441ae0686")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ScenarioTrigger)))
  "Returns md5sum for a message object of type 'ScenarioTrigger"
  "e7645c66f3cdaa3638affc6441ae0686")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ScenarioTrigger>)))
  "Returns full string definition for message of type '<ScenarioTrigger>"
  (cl:format cl:nil "string scenario~%int32 param~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ScenarioTrigger)))
  "Returns full string definition for message of type 'ScenarioTrigger"
  (cl:format cl:nil "string scenario~%int32 param~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ScenarioTrigger>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'scenario))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ScenarioTrigger>))
  "Converts a ROS message object to a list"
  (cl:list 'ScenarioTrigger
    (cl:cons ':scenario (scenario msg))
    (cl:cons ':param (param msg))
))
