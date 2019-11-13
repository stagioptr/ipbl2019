1. abrir a pasta `cd ipbl2019/2_Medico/us111`
2. ativar o virtualenv `source bin/activate`
3. subir dockerfile com o servidor mqtt `docker-compose up`
4. rodar os consumers, para popular os dados no kafka `python3 mqtt_consumers/consumer.py`
5. popular alguns dados no barramento `python3 mqtt_mock/publisher.py`

observações:
- é necessário que sejam criadas as partições para o kafka receber as mensagens postadas

opcionais:
- kafka magic: `docker run -d --rm -p 8080:80 digitsy/kafka-magic`
- mqttfx gui: `https://mqttfx.jensd.de/index.php`
- conduktor: `https://www.conduktor.io/download`