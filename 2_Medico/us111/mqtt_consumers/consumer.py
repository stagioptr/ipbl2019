from consumers.AccelerometerConsumer import AccelerometerConsumer
from consumers.HumidityConsumer import HumidityConsumer

consumers = [
  AccelerometerConsumer('devices/accelerometer', ''),
  HumidityConsumer('devices/humidity', '')
]

while True:
  for consumer in consumers:
    consumer.start()

print('test')