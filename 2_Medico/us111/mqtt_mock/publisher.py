import time
import uuid 
from devices.Humidity import Humidity as MockHumidity
from devices.Temperature import Temperature as MockTemperature
from devices.HeartRate import HeartRate as MockHeartRate
from devices.Accelerometer import Accelerometer as MockAccelerometer

broker_info = {
  'broker': 'localhost',
  'port': 1883,
}

init_devices = list()

def start(sleep_interval, execution_count=-1):
  """Iterate endlessly through the devices
  
  Arguments:
      sleep_interval {int} -- time in seconds the script will wait for the devices to send data again
  
  Keyword Arguments:
      execution_count {int} -- how many times the devices will be iterated (default: {-1})
  """
  while True:
    for device in devices():
      device.publish()
    execution_count += -1 if execution_count > 0 else 0
    if execution_count == 0:
      break
    time.sleep(sleep_interval)

def devices():
  """Initialize devices to be used on the script execution
  
  Returns:
      list -- list containing all instantiated devices
  """
  if len(init_devices) == 0:
    init_devices.append(generate_device('humidity', (40, 90), 'HR'))
    init_devices.append(generate_device('temperature', (15, 35), 'C'))
    init_devices.append(generate_device('heartrate', (60, 110), 'bpm'))
    init_devices.append(generate_device('accelerometer', (0, 10), 'km/h'))
    init_devices.append(generate_device('accelerometer', (0, 10), 'km/h'))
  return init_devices

def generate_uuid(preffix):
  """Generates a random uuid and append the prefix to it
  
  Arguments:
      preffix {string} -- String to be added to the start of the generated id
  
  Returns:
      string -- random device id with its preffix
  """
  id = uuid.uuid4()
  return f"{preffix}_{id}"

def generate_device(device_type, range_tuple, ue):
  """Helps to instantiate new devices, according to its type and configuration
  
  Arguments:
      device_type {string} -- string to identify which device will be generated
      range_tuple {tuple(int)} -- tuple with the lower and higher values the device can generate
      ue {string} -- engineering unit of the generated value
  
  Returns:
      implementation of BaseDevice -- an instantiated device
  """
  switcher = {
    'humidity': MockHumidity,
    'temperature': MockTemperature,
    'heartrate': MockHeartRate,
    'accelerometer': MockAccelerometer,
  }
  uuid = generate_uuid(device_type)
  topic = generate_topic(f'devices/{device_type}')
  device = switcher[device_type](uuid,
                                 range_tuple[0],
                                 range_tuple[1],
                                 topic,
                                 ue)
  return device

def generate_topic(topic):
  """Builds the broker info dict, with the correct topic for the device
  
  Arguments:
      topic {string} -- name of the topic for where the device will send its data
  
  Returns:
      dict -- dict containing the broker address, port and topic
  """
  import copy
  new_info = copy.deepcopy(broker_info)
  new_info['topic'] = topic
  return new_info

if __name__ == "__main__":
  import sys
  if len(sys.argv) > 1:
    exec_times = int(sys.argv[1])
    start(5, exec_times)
  else:
    start(5)