from consumers import BaseConsumer

class HumidityConsumer(BaseConsumer.BaseConsumer):
  def __init__(self, topic_in, topic_out, timeout=1, broker='localhost',
               port=1883, clean_session=True):
    super(HumidityConsumer, self).__init__(topic_in, topic_out, timeout,
                                           broker, port, clean_session)

  def start(self):
    super().listen()
