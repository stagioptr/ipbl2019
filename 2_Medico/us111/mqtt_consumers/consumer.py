from consumers.AccelerometerConsumer import AccelerometerConsumer
from consumers.HumidityConsumer import HumidityConsumer

consumers = [
  AccelerometerConsumer('devices/accelerometer', 'accelerometer'),
  HumidityConsumer('devices/humidity', 'humidity')
]

for consumer in consumers:
  consumer.connect()

while True:
  for consumer in consumers:
    consumer.start()
