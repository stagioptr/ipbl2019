from datetime import datetime
import random
from devices import BaseDevice

class Temperature(BaseDevice.BaseDevice):
  def __init__(self, uuid, range_min, range_max, broker_info):
    super(Temperature, self).__init__(uuid, range_min, range_max)
    super().configure(broker_info)

  def format_message(self, kwargs):
    return {
      'deviceid': self.uuid,
      'time': datetime.today().strftime('%Y%m%d%H%M%S%f'),
      'value': kwargs['value']
    }

  def publish(self):
    value = super().get_value()
    super().publish(value, self.format_message)