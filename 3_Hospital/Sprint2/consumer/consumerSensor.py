from utils import insert_data
from pymongo import MongoClient
from kafka import KafkaConsumer
from datetime import datetime

# mongo =====
# Connect
cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')

# Selecionando um Banco
banco = cliente.stagioptr

# collection
album = banco.sensor

# kafka======
consumer = KafkaConsumer('sensor')

print('Iniciando Consumer Sensor!')

for message in consumer:
    insert_data(
        message, album, [
            "temperatura",
            "giroscopio",
            "umidade",
            "acelerometro"
        ], topic='sensor'
    )
