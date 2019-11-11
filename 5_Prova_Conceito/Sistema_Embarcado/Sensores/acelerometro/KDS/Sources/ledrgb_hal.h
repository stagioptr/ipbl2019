/* ***************************************************************** */
/* File name:        ledrgb_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling RGB LED from the        */
/*                   FRDM-KL25Z board                                */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_LEDRGB_HAL_H_
#define SOURCES_LEDRGB_HAL_H_

/* FDRMKL25Z RGB LED pins defintion */
#define RED_LED_PIN     (uint32_t) 18u
#define GREEN_LED_PIN   (uint32_t) 19u
#define BLUE_LED_PIN    (uint32_t) 1u

/* ************************************************ */
/* Method name:        ledrgb_init                  */
/* Method description: Initialize the RGB LED device*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_init(void);


/* ************************************************ */
/* Method name:        ledrgb_clearRedLed           */
/* Method description: Clear the "red" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearRedLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setRedLed             */
/* Method description: Set the "red" led from RGB   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setRedLed(void);


/* ************************************************ */
/* Method name:        ledrgb_clearGreenLed         */
/* Method description: Clear  "green" led from RGB  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearGreenLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setGreenLed           */
/* Method description: Set the "green" led from RGB */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setGreenLed(void);


/* ************************************************ */
/* Method name:        ledrgb_clearBlueLed          */
/* Method description: Clear the "blue" led from RGB*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_clearBlueLed(void);


/* ************************************************ */
/* Method name:        ledrgb_setBlueLed            */
/* Method description: Set the "blud" led from RGB  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void ledrgb_setBlueLed(void);


#endif /* SOURCES_LEDRGB_HAL_H_ */

