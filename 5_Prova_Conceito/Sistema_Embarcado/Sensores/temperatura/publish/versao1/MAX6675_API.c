/** @file MAX6675_API.c
 *
 * @author Vítor Cruz
 *
 * @brief MAX6675 K-Thermocouple library.
 */

#include "MAX6675_API_port.h"
#include "MAX6675_API.h"

typedef union {
	struct {
#if (MAX6675_BIG_ENDIAN == 1)
		uint8_t LowSB:5;
		uint8_t MiddleSB:3;
		uint8_t HighSB:4;
#else
		uint8_t HighSB:4;
		uint8_t :4;
		uint8_t LowSB:5;
		uint8_t MiddleSB:3;
#endif
	}byte;
	uint16_t word;
}MAX6675_dataConvert_t;

#define MAX6675_DATA_CONVERSION(VARIAVEL)		((MAX6675_dataConvert_t*)VARIAVEL)

typedef struct {
	uint8_t temperatureReadingMiddle:3;
	uint8_t temperatureReadingHigh:4;
	uint8_t dummySignBit:1;
	uint8_t state:1;
	uint8_t deviceID:1;
	uint8_t thermocoupleInput:1;
	uint8_t temperatureReadingLow:5;
}MAX6675_dataStruct_t;

#define MAX6675_DATA_ACCESS(VARIAVEL)		((MAX6675_dataStruct_t*)VARIAVEL)

MAX6675_state_t MAX6675_Init ( void ) {
	if( !MAX6675_SPI_Init_port() )
		return MAX6675_STATE_FAIL_INIT;

	return MAX6675_STATE_SUCCESS;
}

MAX6675_state_t MAX6675_readValue ( uint16_t* valuePointer ) {
	uint8_t buffer[2];

	MAX6675_writeChipSelectPin( 0 );

	if( !MAX6675_SPI_TransferBlocking( buffer, 2 ) )
		return MAX6675_STATE_FAIL_SPI;

	MAX6675_writeChipSelectPin( 1 );

	if( MAX6675_DATA_ACCESS(buffer)->state )
		return MAX6675_STATE_SENSOR_OPENED;

	MAX6675_DATA_CONVERSION(valuePointer)->byte.HighSB = MAX6675_DATA_ACCESS(buffer)->temperatureReadingHigh;
	MAX6675_DATA_CONVERSION(valuePointer)->byte.MiddleSB = MAX6675_DATA_ACCESS(buffer)->temperatureReadingMiddle;
	MAX6675_DATA_CONVERSION(valuePointer)->byte.LowSB = MAX6675_DATA_ACCESS(buffer)->temperatureReadingLow;

	return MAX6675_STATE_SUCCESS;
}

float MAX6675_convertValueToCelsiusDegree ( uint16_t value ) {

	return (float)((float)value)*((float)0.25);
}
