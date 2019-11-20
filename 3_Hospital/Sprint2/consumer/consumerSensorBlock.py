from utils import insert_data
from pymongo import MongoClient
from kafka import KafkaConsumer
from datetime import datetime

# kafka======
consumer = KafkaConsumer('sensor')

print('Iniciando Consumer Sensor para BlockChain!')

for message in consumer:
    insert_data(
        message, album, [
            "temperatura",
            "giroscopio",
            "umidade",
            "acelerometro"
        ], topic='sensor'
    )
