## sources
> https://medium.com/machine-learning-world/how-i-hacked-xiaomi-miband-2-to-control-it-from-linux-a5bd2f36d3ad



## como obter o mac address da miband
1. Identificar o MAC address da Miband `sudo hcitool lescan`
2. Abrir a pasta do script `ipbl2019/2_Medico/Sprint1/us301`
3. Caso seja nova instalação, instalar as dependências `pip3 install -r requirements.txt`
4. Copiar o MAC address exibido e inserir na execução do script `python3 execute --mac {MACADDRESS} --broker {BROKER:PORT} [--interval {READINTERVAL}] [-retry {RETRYCOUNT}]`
