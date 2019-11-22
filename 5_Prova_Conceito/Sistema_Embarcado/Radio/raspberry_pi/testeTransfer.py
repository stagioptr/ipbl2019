from datetime import datetime
import random
from time import sleep
from json import dumps
from kafka import KafkaProducer# ser = serial.Serial(
# 	port='/dev/ttyACM0',
# 	baudrate = 115200,
# 	parity=serial.PARITY_NONE,
# 	stopbits=serial.STOPBITS_ONE,
# 	bytesize=serial.EIGHTBITS,
# 	timeout=None
# 	)
valor = [-3, -2, -1, 0, 1, 2, 3]#initialize kafka producer
producer = KafkaProducer(bootstrap_servers=['34.68.34.160:9092'],
	value_serializer=lambda x:
	dumps(x).encode('utf-8'))
deviceID = ("123.456.789-01")
while 1:
    # start=ser.readline().rstrip()
	start = "Start"
	temperature = (random.choice(valor))
	accelerometer = (random.choice(valor))
	gyro = (random.choice(valor))
	end = (random.choice(valor))
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
	sleep(1)
