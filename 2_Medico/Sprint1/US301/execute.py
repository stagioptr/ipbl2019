import argparse
from base import MiBand2
import time
from datetime import datetime
import paho.mqtt.publish as publish

parser = argparse.ArgumentParser()
parser.add_argument('-m', '--mac', required=True, help='Mac address of the device')
parser.add_argument('-b', '--broker', required=True, help='MQTT broker where the data will be send (example: 127.0.0.1:1883)')
parser.add_argument('-i', '--interval', help='Interval for reading and sending data', default=30)
parser.add_argument('-r', '--retry', help='Number of retries if cannot connect to the smartband', default=1)
args = parser.parse_args()


def init(mac, broker, interval, retry):
  band = connect(mac, retry)
  while True:
    message = getHeartRate(band)
    sendMessage(broker, message)
    time.sleep(float(interval))


def connect(mac, retry):
  for attempt in range(retry):
    try:
      band = MiBand2(mac, debug=True)
      band.setSecurityLevel(level="medium")
      band.authenticate()
      return band
    except:
      print("Oops!",sys.exc_info()[0],"occured.")


def getHeartRate(band):
  data = {
    'time': datetime.now().strftime("%Y%m%dT%H%M%S"),
    'value': band.get_heart_rate_one_time()
  }
  return data


def sendMessage(broker, message):
  import json
  from pprint import pprint
  pprint(json.dumps(message))
  pass


if __name__ == '__main__':
  print(args)
  init(args.mac, args.broker, args.interval, args.retry)