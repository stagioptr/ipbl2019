from utilsblock import save_in_blockchain
from pymongo import MongoClient
from kafka import KafkaConsumer
from datetime import datetime
import json

# # mongo =====
# # Connect
# cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')
#
# # Selecionando um Banco
# banco = cliente.stagioptr
#
# # collection
# album = banco.sensor

# kafka======
consumer = KafkaConsumer('sensor')

print('Iniciando Consumer Sensor para BlockChain!')

# for message in consumer:
#     insert_data(
#         message, [
#             "temperatura",
#             "giroscopio",
#             "umidade",
#             "acelerometro"
#         ], topic='sensor'
#     )

for message in consumer:
    assert isinstance(message, object)
    mjson = json.loads(message.value)
    if type(mjson) is dict:
        print("dict ok")
        if "id" in mjson:
            print("id ok")
            if "dataHora" in mjson:
                print("dataHora ok")
                print(mjson)
                save_in_blockchain(mjson)
