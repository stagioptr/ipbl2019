import argparse
from base import MiBand2
import time
from datetime import datetime

parser = argparse.ArgumentParser()
parser.add_argument('-m', '--mac', required=True, help='Mac address of the device')
parser.add_argument('-k', '--kafka', required=True, help='Kafka server where the data will be send')
parser.add_argument('-i', '--interval', help='Interval for reading and sending data', default=30)
parser.add_argument('-f', '--forever', help='Keep reading data until stop script manually', action='store_true')
args = parser.parse_args()


def init(mac, kafka, interval):
  band = MiBand2(mac, debug=True)
  band.setSecurityLevel(level="medium")
  band.authenticate()
  while True:
    message = getHeartRate(band)
    sendMessage(kafka, message)
    time.sleep(interval)


def getHeartRate(band):
  data = {
    time: datetime.now().strftime("%Y%m%dT%H%M%S"),
    value: band.get_heart_rate_one_time()
  }
  return data


def sendMessage(kafka, message):
  pass


if __name__ == '__main__':
  init(args.mac, args.kafka, args.interval)