from influxdb import InfluxDBClient
import json
from pymongo import MongoClient
from datetime import datetime

cliente = MongoClient('mongodb://stagioptr:ipbl2019@localhost:27017/')
banco = cliente.stagioptr


def connect_influx():
    # influx -host localhost -username stagioptr -password stagioptr@2019 -database stagioptr

    host = 'localhost'
    port = 8087
    username = 'stagioptr'
    password = 'stagioptr@2019'
    db_name = 'stagioptr'

    try:
        return InfluxDBClient(host, port, username, password, db_name)
    except Exception as e:
        print("Erro ao conectar no INFLUX DB:")
        print(str(e))
        return None


def insert_db(measurement, data, data_time, db):
    try:
        body = [
            {
                "measurement": measurement,
                "time": data_time,
                "fields": data
            }
        ]
        db.write_points(body)
    except Exception as e:
        print("Erro ao inserir {} no banco:".format(measurement))
        print(str(e))


def get_save(collection, db):
    name = collection['name']
    campo_data = collection['data']

    album = banco[name]
    data = list(album.find())

    for item in data:
        if campo_data in item:
            if '_id' in item:
                del item['_id']
            insert_db(name, item, item[campo_data], db)


if __name__ == "__main__":
    db = connect_influx()
    if db:
        collections = [
            {
                'name': 'emergency',
                'data': 'dataHora'
            },
            {
                'name': 'emotional',
                'data': 'dataHora'
            },
            {
                'name': 'feeding',
                'data': 'dataHora'
            },
            {
                'name': 'sensor',
                'data': 'hora'
            },
            {
                'name': 'sleep',
                'data': 'dataHora'
            }
        ]
        for col in collections:
            try:
                get_save(col, db)
            except Exception as e:
                print('Erro na collection {}'.format(col))
                print(str(e))
