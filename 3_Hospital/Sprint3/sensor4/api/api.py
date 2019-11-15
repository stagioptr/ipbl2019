# coding: utf-8

from pymongo import MongoClient, ASCENDING
import os
from flask import Flask, request
from flask_compress import Compress
from flask_cors import CORS
from flask_restful import Api, Resource
from datetime import datetime, timedelta

compress = Compress()

MONGO_URI = 'mongodb://stagioptr:ipbl2019@localhost:27017/'


def create_app(environment=None):
    app = Flask(__name__)
    with app.app_context():
        api = Api(app)
        CORS(app, resources=r'/*', origins='*')
        compress.init_app(app)
        app.wsgi_app
        api.add_resource(PacienteController, '/paciente')
        return app


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
            end_date = datetime.strptime(end_date, '%Y-%m-%d')
        else:
            end_date = datetime.now()

        if start_date:
            start_date = datetime.strptime(start_date, '%Y-%m-%d')
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


if __name__ == '__main__':
    app = create_app('ProductionConfig')

    app.secret_key = os.urandom(32)
    HOST = os.environ.get('SERVER_HOST', 'localhost')
    try:
        PORT = int(os.environ.get('PORT', '5010'))
    except ValueError:
        PORT = 5010

    print("Server listening at " + str(PORT))

    app.run(HOST, PORT)
