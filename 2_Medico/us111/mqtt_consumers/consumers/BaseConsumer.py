import json
import paho.mqtt.client as mqtt
from kafka import KafkaProducer
from kafka.errors import KafkaError

LOOP_INTERVAL = .1

class BaseConsumer():
  def __init__(self, topic_in, topic_out, timeout=1, broker='localhost',
               port=1883, clean_session=True, validator_func=None,
               sender_func=None):
    self.topic_in = topic_in
    self.topic_out = topic_out
    self.timeout = timeout
    self.broker = broker
    self.port = port
    self.CLIENT = mqtt.Client(clean_session=True)
    self.KAFKAPRODUCER = KafkaProducer(
      bootstrap_servers=['localhost:9092'],
      retries=5,
      value_serializer=lambda m: json.dumps(m).encode('utf-8')
    )
    self.validator_func = validator_func
    self.sender_func = sender_func

  def get_client(self):
    return self.CLIENT

  def connect(self):
    self.CLIENT.connect(self.broker)
    self.CLIENT.subscribe(self.topic_in)
    self.CLIENT.on_message = self.on_message

  def listen(self):
    self.CLIENT.loop(LOOP_INTERVAL)

  def validate_message(self, message):
    expected_keys = ['deviceid', 'time', 'value', 'unit']
    results = [expected_key in message for expected_key in expected_keys]
    return False not in results

  def on_message(self, client, userdata, message):
    payload = json.loads(message.payload.decode("utf-8"))
    if self.validator_func is None:
      self.validator_func = self.validate_message
    if not self.validator_func(payload):
      print(f'Message invalid ({payload})')
      return
    if self.sender_func is None:
      self.sender_func = self.send
    self.sender_func(message)

  def send(self, message):
    print("message received  ",str(message.payload.decode("utf-8")),\
          "topic",message.topic,"retained ",message.retain)
    self.KAFKAPRODUCER.send(self.topic_out, str(message.payload.decode("utf-8")))
