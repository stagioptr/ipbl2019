from pprint import pprint
import paho.mqtt.publish as publish
import random

class BaseDevice():
  def __init__(self, uuid, range_min, range_max):
    self.uuid = uuid
    self.range_min = range_min
    self.range_max = range_max

  def configure(self, broker_info):
    self.broker_info = broker_info

  def get_value(self):
    return random.randrange(self.range_min, self.range_max)

  def get_uuid(self):
    return self.uuid

  def publish(self, value, formatter_func):
    topic = self.broker_info['topic']
    broker = self.broker_info['broker']
    port = self.broker_info['port']
    kwargs = {"value": value}
    msg = formatter_func(kwargs)
    print(f"Sending {value} from {self.uuid} to {broker}:{port}/{topic}")
    publish.single(topic, str(msg), hostname=broker)