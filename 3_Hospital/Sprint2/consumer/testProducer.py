# imports
from datetime import datetime
from json import dumps
from random import randint
from time import sleep
from kafka import KafkaProducer

# initialize kafka producer
producer = KafkaProducer(bootstrap_servers=['34.68.34.160:9092'],
                         value_serializer = lambda x:
                         dumps(x).encode('utf-8'))
topicName = 'sensor'

#print('Início do teste')

paciente = "Video"


for i in range(10):
    now = datetime.now()
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    documento = {
        'id' : paciente,
        'dataHora' : dt_string,
        'temperatura' : '37,1',
        'umidade' : '50',
        'acelerometro' : '0',
        'giroscopio' : '0'
    }
    print (i)
    print(documento)
    producer.send(topicName, documento)
    sleep(1)

print('Fim do teste.')