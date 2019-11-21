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

	//unsigned long got_time = 0;

	// Setup and configure rf radio
	radio.begin();
	// optionally, increase the delay between retries & # of retries
	radio.setRetries(15,15);
	// Dump the configuration of the rf unit for debugging
	radio.printDetails();
	// Open radio pipe for writing
	radio.openWritingPipe(pipes[1]);
	// Open radio pipe for reading
	radio.openReadingPipe(1,pipes[0]);
	// First, start listening so we can receive data.
	radio.startListening();
	 
	while (1) 
	{
		// if there is data ready
		if ( radio.available() )
		{
			// Fetch the payload, and see if this was the last one.
			radio.read( &buffer, sizeof(buffer) );
			printf("\n[INFO] Data received -> time: %ul, fVar1: %3.2f, cVar1: %c", buffer.time, buffer.fVar1, buffer.cVar1);
		}
		sleep(1);
	}
}

