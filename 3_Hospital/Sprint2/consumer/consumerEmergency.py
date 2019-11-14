from pymongo import MongoClient
from kafka import KafkaConsumer
from utils import insert_data

# mongo =====
## Connect
cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')

## Selecionando um Banco
banco = cliente.stagioptr

## collection
album = banco.emergency

#kafka======
consumer = KafkaConsumer('emergency')

print('Iniciando Consumer Emergency!')

for message in consumer:
    insert_data(message, album, topic='emergency')