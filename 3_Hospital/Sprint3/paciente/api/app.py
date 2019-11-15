import os
from flask import Flask, Response, render_template
from flask_compress import Compress
from flask_cors import CORS
from flask_restful import Api

compress = Compress()


def create_app(environment=None):
    app = Flask(__name__)
    with app.app_context():
        api = Api(app)

        CORS(app, resources=r'/*', origins='*')

        compress.init_app(app)

        app.wsgi_app

        from api.paciente_resource import PacienteController

        api.add_resource(PacienteController, '/paciente')

        return app
