from pymongo import MongoClient, DESCENDING
import os
from flask import request
from flask_restful import Resource
from datetime import datetime, timedelta

MONGO_URI = 'mongodb://stagioptr:ipbl2019@34.68.34.160:27017/'


class PacienteOnlineController(Resource):

    def get(self):
        user = request.args.get('user', None)
        if not user:
            return {
                'message': 'Necessário informar o paciente'
            }, 400

        mongo = MongoClient(MONGO_URI)

        data = list(mongo.stagioptr.sensor.find(
            {"id": user}).sort("_id", -1).limit(1)
        )

        mongo.close()
        if data:
            return {
                "dataHoraObj": data[0]['dataHoraObj'],
                "temperatura": data[0]['temperatura'],
                "umidade": data[0]['umidade'],
                "batimento": data[0]['batimento']
            }, 200
        return {}, 200
