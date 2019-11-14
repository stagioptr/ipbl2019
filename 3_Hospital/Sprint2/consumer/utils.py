from datetime import datetime
import json
import requests
from copy import deepcopy

def save_in_blockchain(message, topic):
    msg = deepcopy(message)
    if 'dataHoraObj' in msg:
        del msg['dataHoraObj']
    if '_id' in msg:
        del msg['_id']
    data = {
        "topic": topic,
        "message": json.dumps(msg),
        "datetime": msg['dataHora']
    }
    url = 'http://34.68.34.160:3002/api/br.ita.stagioptr.SaveReadTransaction'
    try:
        r = requests.post(url, json=data)
        print(r.json())
    except Exception as e:
        print('ERRO BLOCKCHAIN')
        print(str(e))


def insert_data(message, album, fields_to_convert=[], topic=''):
    assert isinstance(message, object)
    mjson = json.loads(message.value)
    if type(mjson) is dict:
        if "id" in mjson:
            print("id ok")
            if "dataHora" in mjson:
                print("dataHora ok")
                print(mjson)
                try:
                    mjson['dataHoraObj'] = datetime.strptime(
                        mjson['dataHora'], '%d/%m/%Y %H:%M:%S'
                    )
                    if fields_to_convert:
                        for field in fields_to_convert:
                            if field in mjson:
                                mjson[field] = float(mjson[field].replace(',', '.'))
                    documento_id = album.insert_one(mjson).inserted_id

                    save_in_blockchain(mjson, topic)

                except Exception as e:
                    print(str(e))
