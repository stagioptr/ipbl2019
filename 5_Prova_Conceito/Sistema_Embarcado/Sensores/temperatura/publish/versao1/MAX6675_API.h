/** @file MAX6675_API.h
 *
 * @author Vítor Cruz
 *
 * @brief MAX6675 K-Thermocouple library.
 */

typedef enum {
	MAX6675_STATE_SUCCESS 									= 0,
	MAX6675_STATE_FAIL_INIT 								= 1,
	MAX6675_STATE_FAIL_SPI	 								= 2,
	MAX6675_STATE_SENSOR_OPENED							= 3,
} MAX6675_state_t;

MAX6675_state_t MAX6675_Init ( void );
MAX6675_state_t MAX6675_readValue ( uint16_t* valuePointer );
float MAX6675_convertValueToCelsiusDegree ( uint16_t value );
