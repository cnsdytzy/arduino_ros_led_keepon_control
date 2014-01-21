; Auto-generated. Do not edit!


(cl:in-package led_keepon-msg)


;//! \htmlinclude LEDMessage.msg.html

(cl:defclass <LEDMessage> (roslisp-msg-protocol:ros-message)
  ((led_state
    :reader led_state
    :initarg :led_state
    :type cl:string
    :initform "")
   (freq
    :reader freq
    :initarg :freq
    :type cl:integer
    :initform 0)
   (led_param1
    :reader led_param1
    :initarg :led_param1
    :type cl:integer
    :initform 0)
   (color1
    :reader color1
    :initarg :color1
    :type (cl:vector cl:integer)
   :initform (cl:make-array 3 :element-type 'cl:integer :initial-element 0))
   (led_param2
    :reader led_param2
    :initarg :led_param2
    :type cl:integer
    :initform 0)
   (color2
    :reader color2
    :initarg :color2
    :type (cl:vector cl:integer)
   :initform (cl:make-array 3 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass LEDMessage (<LEDMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LEDMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LEDMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name led_keepon-msg:<LEDMessage> is deprecated: use led_keepon-msg:LEDMessage instead.")))

(cl:ensure-generic-function 'led_state-val :lambda-list '(m))
(cl:defmethod led_state-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:led_state-val is deprecated.  Use led_keepon-msg:led_state instead.")
  (led_state m))

(cl:ensure-generic-function 'freq-val :lambda-list '(m))
(cl:defmethod freq-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:freq-val is deprecated.  Use led_keepon-msg:freq instead.")
  (freq m))

(cl:ensure-generic-function 'led_param1-val :lambda-list '(m))
(cl:defmethod led_param1-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:led_param1-val is deprecated.  Use led_keepon-msg:led_param1 instead.")
  (led_param1 m))

(cl:ensure-generic-function 'color1-val :lambda-list '(m))
(cl:defmethod color1-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:color1-val is deprecated.  Use led_keepon-msg:color1 instead.")
  (color1 m))

(cl:ensure-generic-function 'led_param2-val :lambda-list '(m))
(cl:defmethod led_param2-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:led_param2-val is deprecated.  Use led_keepon-msg:led_param2 instead.")
  (led_param2 m))

(cl:ensure-generic-function 'color2-val :lambda-list '(m))
(cl:defmethod color2-val ((m <LEDMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader led_keepon-msg:color2-val is deprecated.  Use led_keepon-msg:color2 instead.")
  (color2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LEDMessage>) ostream)
  "Serializes a message object of type '<LEDMessage>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'led_state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'led_state))
  (cl:let* ((signed (cl:slot-value msg 'freq)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'led_param1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'color1))
  (cl:let* ((signed (cl:slot-value msg 'led_param2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'color2))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LEDMessage>) istream)
  "Deserializes a message object of type '<LEDMessage>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'led_state) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'led_state) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'freq) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'led_param1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'color1) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'color1)))
    (cl:dotimes (i 3)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'led_param2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'color2) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'color2)))
    (cl:dotimes (i 3)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LEDMessage>)))
  "Returns string type for a message object of type '<LEDMessage>"
  "led_keepon/LEDMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LEDMessage)))
  "Returns string type for a message object of type 'LEDMessage"
  "led_keepon/LEDMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LEDMessage>)))
  "Returns md5sum for a message object of type '<LEDMessage>"
  "0b4e62f07a3469f99fb7a12a5da4108c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LEDMessage)))
  "Returns md5sum for a message object of type 'LEDMessage"
  "0b4e62f07a3469f99fb7a12a5da4108c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LEDMessage>)))
  "Returns full string definition for message of type '<LEDMessage>"
  (cl:format cl:nil "string led_state~%int32 freq~%int32 led_param1~%int32[3] color1~%int32 led_param2~%int32[3] color2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LEDMessage)))
  "Returns full string definition for message of type 'LEDMessage"
  (cl:format cl:nil "string led_state~%int32 freq~%int32 led_param1~%int32[3] color1~%int32 led_param2~%int32[3] color2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LEDMessage>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'led_state))
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'color1) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'color2) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LEDMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'LEDMessage
    (cl:cons ':led_state (led_state msg))
    (cl:cons ':freq (freq msg))
    (cl:cons ':led_param1 (led_param1 msg))
    (cl:cons ':color1 (color1 msg))
    (cl:cons ':led_param2 (led_param2 msg))
    (cl:cons ':color2 (color2 msg))
))
