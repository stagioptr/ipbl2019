from pymongo import MongoClient, ASCENDING
import os
from flask import request
from flask_restful import Resource
from datetime import datetime, timedelta

MONGO_URI = 'mongodb://stagioptr:ipbl2019@34.68.34.160:27017/'


class PacienteController(Resource):

    def get(self):
        user = request.args.get('user', None)
        if not user:
            return {
                'message': 'Necessário informar o paciente'
            }, 400
        start_date = request.args.get('start_date', None)
        end_date = request.args.get('end_date', None)

        if end_date:
            try:
                end_date = datetime.strptime(end_date, '%Y-%m-%d')
            except Exception:
                return {
                    'message': "Formato de data incorreto. O formato esperado é: yyyy-mm-dd"
                }
        else:
            end_date = datetime.now()

        if start_date:
            try:
                start_date = datetime.strptime(start_date, '%Y-%m-%d')
            except Exception:
                return {
                    'message': "Formato de data incorreto. O formato esperado é: yyyy-mm-dd"
                }
        else:
            start_date = datetime.now() - timedelta(days=4)

        mongo = MongoClient(MONGO_URI)

        data = list(mongo.stagioptr.sensor.find({
            'id': user,
            'dataHoraObj': {
                '$gte': start_date,
                '$lte': end_date
            }
        }).sort('dataHoraObj', ASCENDING))
        mongo.close()
        tmp = []
        for item in data:
            tmp.append({
                "temperatura": item['temperatura'],
                "giroscopio": item['giroscopio'],
                "umidade": item['umidade'],
                "acelerometro": item['acelerometro'],
                "data_hora": item['dataHora']
            })
        return tmp, 200
