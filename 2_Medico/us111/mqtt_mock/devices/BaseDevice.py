from pprint import pprint
import paho.mqtt.publish as publish
import random

class BaseDevice():
  def __init__(self, uuid, range_min, range_max, ue):
    self.uuid = uuid
    self.range_min = range_min
    self.range_max = range_max
    self.ue = ue

  def configure(self, broker_info):
    """Attach the broker info to this device instance

    Arguments:
        broker_info {dict} -- dict with all broker information
    """
    self.broker_info = broker_info

  def get_value(self):
    """Get the value from sensor now

    Returns:
        int -- The value read now from the sensor
    """
    return random.randrange(self.range_min, self.range_max)

  def get_uuid(self):
    """Return the device

    Returns:
        string -- this device id
    """
    return self.uuid

  def publish(self, value, formatter_func):
    """Prepare the value read from the device, and send it to the MQTT broker

    Arguments:
        value {numeric} -- Value read from the device
        formatter_func {function} -- Function to put the data in its final form
    """
    import json
    topic = self.broker_info['topic']
    broker = self.broker_info['broker']
    port = self.broker_info['port']
    kwargs = {'value': value, 'ue': self.ue}
    msg = json.dumps(formatter_func(kwargs))
    print(f"Sending {value}({self.ue}) from {self.uuid} to {broker}:{port}/{topic}")
    publish.single(topic, str(msg), hostname=broker)