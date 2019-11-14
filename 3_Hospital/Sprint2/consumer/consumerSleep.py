from utils import insert_data
from pymongo import MongoClient
from kafka import KafkaConsumer

# mongo =====
## Connect
cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')

## Selecionando um Banco
banco = cliente.stagioptr

## collection
album = banco.sleep

#kafka======
consumer = KafkaConsumer('sleep')

print('Iniciando Consumer Sleep!')

for message in consumer:
    insert_data(message, album, topic='sleep')