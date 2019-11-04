import argparse
from base import MiBand2
import time
from datetime import datetime

parser = argparse.ArgumentParser()
parser.add_argument('-m', '--mac', required=True, help='Mac address of the device')
parser.add_argument('-k', '--kafka', required=True, help='Kafka server where the data will be send')
parser.add_argument('-i', '--interval', help='Interval for reading and sending data', default=30)
parser.add_argument('-r', '--retry', help='Number of retries if cannot connect to the smartband', default=1)
args = parser.parse_args()


def init(mac, kafka, interval, retry):
  band = connect(mac, retry)
  while True:
    message = getHeartRate(band)
    sendMessage(kafka, message)
    time.sleep(float(interval))


def connect(mac, retry):
  for (attempt in retry):
    try:
      band = MiBand2(mac, debug=True)
      band.setSecurityLevel(level="medium")
      band.authenticate()
      return band
    except:
      print("Oops!",sys.exc_info()[0],"occured."))


def getHeartRate(band):
  data = {
    'time': datetime.now().strftime("%Y%m%dT%H%M%S"),
    'value': band.get_heart_rate_one_time()
  }
  return data


def sendMessage(kafka, message):
  import json
  from pprint import pprint
  pprint(json.dumps(message))
  pass


if __name__ == '__main__':
  print(args)
  init(args.mac, args.kafka, args.interval, args.retry)