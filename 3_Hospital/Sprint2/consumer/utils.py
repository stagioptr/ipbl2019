from datetime import datetime
import json

def insert_data(message, album, fields_to_convert=[]):
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
                                mjson[field] = float(mjson[field])
                    documento_id = album.insert_one(mjson).inserted_id
                except Exception:
                    pass
