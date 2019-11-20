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

        from api.paciente_resource import PacienteController, PacienteAllController
        from api.paciente_online import PacienteOnlineController

        api.add_resource(PacienteController, '/paciente')
        api.add_resource(PacienteAllController, '/ids-paciente')
        api.add_resource(PacienteOnlineController, '/online')

        @app.route('/dash/paciente')
        def index():
            content = render_template('paciente.html')
            return Response(content, mimetype="text/html")

        return app
