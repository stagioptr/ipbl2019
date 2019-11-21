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
        tmp = {}
        if data:
            data = data[0]
            fields = ['dataHora', 'temperatura', 'umidade', 'batimento']
            for item in fields:
                tmp[item] = None
                if item in data:
                    tmp[item] = data[item]
            return tmp, 200
        return tmp, 200
