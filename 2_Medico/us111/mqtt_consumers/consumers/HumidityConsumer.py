from consumers import BaseConsumer

class HumidityConsumer(BaseConsumer.BaseConsumer):
  def __init__(self, topic_in, topic_out, timeout=1, broker='localhost',
               port=1883, clean_session=True):
    super(HumidityConsumer, self).__init__(topic_in, topic_out, timeout,
                                           broker, port, clean_session)
    self.configure()

  def configure(self):
    super().get_client().on_message = self.on_message

  def start(self):
    super().listen()

  def on_message(self, client, userdata, message):
    print("message received  ",str(message.payload.decode("utf-8")),\
          "topic",message.topic,"retained ",message.retain)
    if message.retain==1:
      print("This is a retained message")