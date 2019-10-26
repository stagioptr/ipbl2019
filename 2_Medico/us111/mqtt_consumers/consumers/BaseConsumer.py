import paho.mqtt.client as mqtt

class BaseConsumer():
  def __init__(self, topic_in, topic_out, timeout=1, broker='localhost',
               port=1883, clean_session=True):
    self.topic_in = topic_in
    self.topic_out = topic_out
    self.timeout = timeout
    self.broker = broker
    self.port = port
    self.CLIENT = mqtt.Client(clean_session=True)

  def get_client(self):
    return self.CLIENT

  def listen(self):
    self.CLIENT.connect(self.broker)
    self.CLIENT.subscribe(self.topic_in)
    self.CLIENT.loop_start()
    # self.CLIENT.loop_forever(timeout=self.timeout, max_packets=1,
    #                          retry_first_connection=False)

  # def send(self):
  #   if not self.validate_message(message):
  #     print(f'Message invalid ({message})')
  #     return
  #   pass

  def validate_message(self, message):
    expected_keys = ['deviceid', 'time', 'value', 'unit']
    results = [expected_key in message for expected_key in expected_keys]
    return False not in results