#!/usr/bin/env python


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
	valor=ser.readline()
	now = datetime.now()
	dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
	documento = {
		"sensor": "Temperatura",
		"hora": dt_string,
		"valor": valor
	}
	producer.send('SPRINT01', documento)
	print(documento)
# print(type(documento))
