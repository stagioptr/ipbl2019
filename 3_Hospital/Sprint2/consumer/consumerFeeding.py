from utils import insert_data
from pymongo import MongoClient
from kafka import KafkaConsumer

# mongo =====
## Connect
cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')

## Selecionando um Banco
banco = cliente.stagioptr

## collection
album = banco.feeding

#kafka======
consumer = KafkaConsumer('feeding')

print('Iniciando Consumer Feeding!')

for message in consumer:
    insert_data(message, album)