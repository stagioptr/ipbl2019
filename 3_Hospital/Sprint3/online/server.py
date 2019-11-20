from api.app import create_app
import os

app = create_app()

if __name__ == '__main__':
    import os

    app.secret_key = os.urandom(32)
    HOST = os.environ.get('SERVER_HOST', 'localhost')
    try:
        PORT = int(os.environ.get('PORT', '5011'))
    except ValueError:
        PORT = 5011

    print("Server listening at " + str(PORT))
    app.run(HOST, PORT)
