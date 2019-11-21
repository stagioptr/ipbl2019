from datetime import datetime
from time import sleep
from json import dumps
from kafka import KafkaProducer

import time
import serial


ser = serial.Serial(
	port='/dev/ttyACM0',
	baudrate = 115200,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=None
	)

#initialize kafka producer
producer = KafkaProducer(bootstrap_servers=['34.68.34.160:9092'],
	value_serializer=lambda x:
	dumps(x).encode('utf-8'))

while 1:
	start=ser.readline().rstrip()
	if (start == "Start"):
		deviceID = ser.readline().rstrip()
		temperature = ser.readline().rstrip()
		accelerometer = ser.readline().rstrip()
		gyro = ser.readline().rstrip()
		end = ser.readline().rstrip()
		if(end == "End"):
			now = datetime.now()
			dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
			documento = {
				'id' : deviceID,
				'dataHora' : dt_string,
				'temperatura' : temperature,
				'umidade' : 0,
				'acelerometro' : accelerometer,
				'giroscopio' : gyro
			}
			producer.send('sensor', documento)
			print(documento)
