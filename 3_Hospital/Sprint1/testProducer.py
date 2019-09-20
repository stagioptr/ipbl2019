# imports
from datetime import datetime
from time import sleep
from json import dumps
from kafka import KafkaProducer

#initialize kafka producer
producer = KafkaProducer(bootstrap_servers=['localhost:9092'],
                         value_serializer=lambda x:
                         dumps(x).encode('utf-8'))

for valor in range(600):
    now = datetime.now()
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    documento = {
        "sensor": "ACME01",
        "hora": dt_string,
        "valor": valor
    }
    producer.send('SPRINT01', documento)
    print(documento)
   # print(type(documento))
    sleep(1)

