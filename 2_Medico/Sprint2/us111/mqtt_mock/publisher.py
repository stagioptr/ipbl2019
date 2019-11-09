import time
import uuid 
from devices.Humidity import Humidity as MockHumidity
from devices.Temperature import Temperature as MockTemperature

broker_info = {
  'topic': 'topico/teste',
  'broker': 'localhost',
  'port': 1883,
}

def start(sleep_interval):
  while True:
    for device in devices():
      device.publish()
    time.sleep(sleep_interval)

def devices():
  d = list()
  d.append(MockHumidity(generate_uuid('humidity'), 40, 80, broker_info))
  d.append(MockTemperature(generate_uuid('temperature'), 15, 35, broker_info))
  return d

def generate_uuid(preffix):
  id = uuid.uuid1()
  return f"{preffix}_{id}"

if __name__ == "__main__":
  start(5)