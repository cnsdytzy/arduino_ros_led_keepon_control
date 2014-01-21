; Auto-generated. Do not edit!


(cl:in-package led_keepon-msg)


;//! \htmlinclude KeeponMessage.msg.html

(cl:defclass <KeeponMessage> (roslisp-msg-protocol:ros-message)
  ((device
    :reader device
    :initarg :device
    :type cl:integer
    :initform 0)
   (cmd1
    :reader cmd1
    :initarg :cmd1
    :type cl:integer
    :initform 0)
   (cmd0
    :reader cmd0
    :initarg :cmd0
    :type cl:integer
    :initform 0))
)

(cl:defclass KeeponMessage (<KeeponMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KeeponMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KeeponMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name led_keepon-msg:<KeeponMessage> is deprecated: use led_keepon-msg:KeeponMessage instead.")))

(cl:ensure-generic-function 'device-val :lambda-list '(m))
(cl:defmethod device-val ((m <KeeponMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:device-val is deprecated.  Use led_keepon-msg:device instead.")
  (device m))

(cl:ensure-generic-function 'cmd1-val :lambda-list '(m))
(cl:defmethod cmd1-val ((m <KeeponMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:cmd1-val is deprecated.  Use led_keepon-msg:cmd1 instead.")
  (cmd1 m))

(cl:ensure-generic-function 'cmd0-val :lambda-list '(m))
(cl:defmethod cmd0-val ((m <KeeponMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:cmd0-val is deprecated.  Use led_keepon-msg:cmd0 instead.")
  (cmd0 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KeeponMessage>) ostream)
  "Serializes a message object of type '<KeeponMessage>"
  (cl:let* ((signed (cl:slot-value msg 'device)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'cmd1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'cmd0)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KeeponMessage>) istream)
  "Deserializes a message object of type '<KeeponMessage>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'device) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd0) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KeeponMessage>)))
  "Returns string type for a message object of type '<KeeponMessage>"
  "led_keepon/KeeponMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KeeponMessage)))
  "Returns string type for a message object of type 'KeeponMessage"
  "led_keepon/KeeponMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KeeponMessage>)))
  "Returns md5sum for a message object of type '<KeeponMessage>"
  "2101c2ea4b2b158a443252950557dd65")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KeeponMessage)))
  "Returns md5sum for a message object of type 'KeeponMessage"
  "2101c2ea4b2b158a443252950557dd65")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KeeponMessage>)))
  "Returns full string definition for message of type '<KeeponMessage>"
  (cl:format cl:nil "int32 device~%int32 cmd1~%int32 cmd0~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KeeponMessage)))
  "Returns full string definition for message of type 'KeeponMessage"
  (cl:format cl:nil "int32 device~%int32 cmd1~%int32 cmd0~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KeeponMessage>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KeeponMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'KeeponMessage
    (cl:cons ':device (device msg))
    (cl:cons ':cmd1 (cmd1 msg))
    (cl:cons ':cmd0 (cmd0 msg))
))
