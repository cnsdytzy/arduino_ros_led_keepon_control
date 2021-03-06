"""autogenerated by genpy from led_keepon/LEDMessage.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class LEDMessage(genpy.Message):
  _md5sum = "55920192e5581cc9eac7865606e971e9"
  _type = "led_keepon/LEDMessage"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 led_state
int32 freq
int32 led_param1
int32[3] color1
int32 led_param2
int32[3] color2

"""
  __slots__ = ['led_state','freq','led_param1','color1','led_param2','color2']
  _slot_types = ['int32','int32','int32','int32[3]','int32','int32[3]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       led_state,freq,led_param1,color1,led_param2,color2

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LEDMessage, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.led_state is None:
        self.led_state = 0
      if self.freq is None:
        self.freq = 0
      if self.led_param1 is None:
        self.led_param1 = 0
      if self.color1 is None:
        self.color1 = [0,0,0]
      if self.led_param2 is None:
        self.led_param2 = 0
      if self.color2 is None:
        self.color2 = [0,0,0]
    else:
      self.led_state = 0
      self.freq = 0
      self.led_param1 = 0
      self.color1 = [0,0,0]
      self.led_param2 = 0
      self.color2 = [0,0,0]

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3i.pack(_x.led_state, _x.freq, _x.led_param1))
      buff.write(_struct_3i.pack(*self.color1))
      buff.write(_struct_i.pack(self.led_param2))
      buff.write(_struct_3i.pack(*self.color2))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 12
      (_x.led_state, _x.freq, _x.led_param1,) = _struct_3i.unpack(str[start:end])
      start = end
      end += 12
      self.color1 = _struct_3i.unpack(str[start:end])
      start = end
      end += 4
      (self.led_param2,) = _struct_i.unpack(str[start:end])
      start = end
      end += 12
      self.color2 = _struct_3i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3i.pack(_x.led_state, _x.freq, _x.led_param1))
      buff.write(self.color1.tostring())
      buff.write(_struct_i.pack(self.led_param2))
      buff.write(self.color2.tostring())
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 12
      (_x.led_state, _x.freq, _x.led_param1,) = _struct_3i.unpack(str[start:end])
      start = end
      end += 12
      self.color1 = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=3)
      start = end
      end += 4
      (self.led_param2,) = _struct_i.unpack(str[start:end])
      start = end
      end += 12
      self.color2 = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=3)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
_struct_3i = struct.Struct("<3i")
