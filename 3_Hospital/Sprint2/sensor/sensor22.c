/* Projeto acadêmico STAGIOP-TR - Pós-graduação ITA/2019
 * Sensor de Temperatura e Humidade DHT22 monitorado pela Raspberry Pi 3
 * Utilizando a biblioteca WiringPi
 * Codigo inicial https://github.com/ccoong7/DHT22
 * Incluisões e alteração ocorridas em Outubro/19 - Por Remo C. Carnevalli, 
 *
 *
 * sensor22.c -  Versão: 2.0
 * Linha de compilação => gcc sensor22.c -o sensor22 -lwiringPi -lwiringPiDev
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <wiringPi.h>

static const unsigned short signal = 4;    // Fixando o pino 7 GPIO4 da Raspberry PI3
unsigned short data[5] = {0, 0, 0, 0, 0};


short readData()
{
	unsigned short val = 0x00;
	unsigned short signal_length = 0;
	unsigned short val_counter = 0;
	unsigned short loop_counter = 0;

	while (1)
	{
		// trabalhando somente HIGH signal
		while (digitalRead(signal) == HIGH)
		{
			signal_length++;

			// Se ocorrer queda no sinal transmitido, o fluxo de leitura será interrompido
			if (signal_length >= 200)
			{
				return -1;
			}

			delayMicroseconds(1);
		}

		// Teste do sinal em HIGH
		if (signal_length > 0)
		{
			loop_counter++;

			// O sensor DHT22 pode enviar sinais errados ou mesmo uma conexão instável
			// Para isto é melhor ampliar o intervalo de coleta/contagem.
			if (signal_length < 10)
			{
				// sinal instável
				val <<= 1;		// 0 bit. shift para a esquerda
			}

			else if (signal_length < 30)
			{
				// 26~28us => 0 bit
				val <<= 1;		// 0 bit. shift para a esquerda
			}

			else if (signal_length < 85)
			{
				// 70us => 1 bit
				// Shift para esquerda e entrada de 0x01 usando o operador OR
				val <<= 1;
				val |= 1;
			}

			else
			{
				// Sinal instável
				return -1;
			}

			signal_length = 0;	// Inicializa sinal para a próxima coleta
			val_counter++;		// somatória para um dado coletado de 8 bits
		}

		// O primeiro e o segundo sinal são de inicialização do sensor e podem ser desconsiderados.
		if (loop_counter < 3)
		{
			val = 0x00;
			val_counter = 0;
		}

		// Teste para verificar os 8 bits de entrada
		if (val_counter >= 8)
		{
			// 8 bits array
			data[(loop_counter / 8) - 1] = val;

			val = 0x00;
			val_counter = 0;
		}
	}
}


int main(void)
{
	float humidity;
	float celsius;
	float fahrenheit;
	short checksum;
	short maxtry;
	struct timespec start, end;
	double elapsedTime;
	//FILE *fs;

        FILE *dados;
        FILE *dadosweb;
 
        
	// Inicializando a GPIO da Raspberry PI3
	if (wiringPiSetupGpio() == -1)
	{
		fprintf( stderr, "ERRO: GPIO -> Falha na inicialização.\n");
		return -1;
	}
for (int j = 0; j < 200; j++ )
{


   
	clock_gettime(CLOCK_REALTIME, &start);

	
	while(1)
	{
		pinMode(signal, OUTPUT);

		// Enviando sinal de inicialização
		digitalWrite(signal, LOW);
		delay(20);			// tempo de espera necessário para sincronização (5~30 milliseconds)
		pinMode(signal, INPUT);		// 'INPUT' = 'HIGH' - Leitura da GPIO4

		readData();			// lendo o sensor DHT22

		// soma binário: '0001 0101 1010'.

		checksum = (data[0] + data[1] + data[2] + data[3]) & 0xFF;

		// Verificando soma (NOT 0x00) => Apresenta valores da leitura ( temperatura e Humidade )
		if (data[4] == checksum && checksum != 0x00)
		{ 

                       dados = fopen("/var/www/html/sensor/texto.txt","w");
                       dadosweb = fopen("/var/www/html/sensor/index.html","w");



			// finaliza tempo de coleta
			clock_gettime(CLOCK_REALTIME, &end);
			// calcula tempo de computação
			elapsedTime = (end.tv_sec - start.tv_sec);

			// * 256 is the same thing '<< 8' (shift).
			humidity = ((data[0] * 256) + data[1]) / 10.0;
			celsius = (((data[2] & 0x7F)*256) + data[3]) / 10.0;

			// If 'data[2]' data like 1000 0000, It means minus temperature
			if (data[2] == 0x80)
			{
				celsius *= -1;
			}


			char time_buff[100];
			time_t now = time (0);
			strftime (time_buff, 100, "%Y-%m-%d %H:%M:%S", localtime (&now));

                        fprintf(dadosweb,"%s %.2fC %.2f%\n ", time_buff, celsius, humidity);

                        fprintf(dados,"%s %.2fC %.2f%\n", time_buff, celsius, humidity);

                        printf("\n\nTempo decorrido (sec): %.4f\n Data: %s\n Temperatura(C)=%.2f\n Humidade(%)=%.2f\n\n", elapsedTime, time_buff, celsius, humidity);   


                        fclose(dados);
                        fclose(dadosweb); 
                       



		} else {
    		         printf("\n");

          }

		// Inicializando array para a próxima leitura
		for (unsigned char j = 0; j < 5; j++)
		{
			data[j] = 0;
		}
                         // Especificação do Sensor DHT22
		delay(2000);	// Intervalo necessário (2 segundos) para entrar em novo modo de leitura


     }
	printf("Ciclo de leitura do sensor finalizado.\n"); 

   } 

 
	return 0;
}
