/* Send Struct over the radio nRF24L01 to be used in the STAGIOP-TR project 
 *
 * author: carlos lopes
 *
 * */

#include <cstdlib>
#include <RF24/RF24.h>

typedef struct {
	unsigned long time;
	float fVar1;
	char cVar1;
} myBuffer; 

using namespace std;

// CE Pin, CSN Pin, SPI Speed

// Setup for GPIO 22 CE and CE1 CSN with SPI Speed @ 1Mhz
RF24 radio(RPI_V2_GPIO_P1_22, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_1MHZ);

// Radio pipe addresses for the 2 nodes to communicate.
const uint8_t pipes[][6] = {"1Node","2Node"};
myBuffer buffer;

int main(int argc, char** argv){

	//unsigned long time = millis();
	buffer.time = millis();
	buffer.fVar1 = 7.33;
	buffer.cVar1 = 'a';

	// Print preamble:
	printf("RF24/examples/send_struct/\n");

	// Setup and configure rf radio
	radio.begin();
	// optionally, increase the delay between retries & # of retries
	radio.setRetries(15,15);
	// Dump the configuration of the rf unit for debugging
	radio.printDetails();
	// Open radio pipe for writing
	radio.openWritingPipe(pipes[0]);
	// Open radio pipe for reading
	radio.openReadingPipe(1,pipes[1]);
	// First, stop listening so we can talk.
	radio.stopListening();
	 
	while (1) 
	{
		buffer.time += 1;
		buffer.fVar1 += 1.7;
		buffer.cVar1 = (++buffer.cVar1 < 127) ? buffer.cVar1 : 48;

		bool ok = radio.write( &buffer, sizeof(buffer) );

		if (ok) 
		{
			printf("\n[INFO] Sent OK");
		}
		else
		{
			printf("\n[FAIL] Sent failed!");
		}

		// Wait 
		sleep(3);
	}
}

