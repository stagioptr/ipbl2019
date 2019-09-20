import json
from pymongo import MongoClient
from kafka import KafkaConsumer

# mongo =====
## Conect
cliente = MongoClient('localhost', 27017)

## Selecionando um Banco
banco = cliente.ita

## collection
album = banco.stagioptr

#kafka======
consumer = KafkaConsumer('SPRINT01')

print('Iniciando Consumer!')

for message in consumer:
    assert isinstance(message, object)
    mjson = json.loads(message.value)
    print(mjson)
    documento_id = album.insert_one(mjson).inserted_id