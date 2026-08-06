/* 
 * File:   ecu_led.h
 * Author: aliel
 *
 * Created on 19. September 2023, 00:17
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/* Section: Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */

typedef enum{
    LED_ON,
    LED_OFF
}led_status;

typedef struct{
    uint8 port : 4;
    uint8 pin : 3;
    uint8 logic : 1;
}led_t;

/* Section: Macro Functions */

/* Section: Data Type Declarations */

/* Section: Functions Declarations */

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led);

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led);

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led);

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_toggle(const led_t *led);

#endif	/* ECU_LED_H */

