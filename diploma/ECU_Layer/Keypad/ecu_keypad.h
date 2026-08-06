/* 
 * File:   ecu_keypad.h
 * Author: aliel
 *
 * Created on 19. Dezember 2023, 15:17
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section: Includes */
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */
#define KEYPAD_ROWS_PINS 4
#define KEYPAD_COLOMN_PINS 4

/* Section: Macro Functions */

/* Section: Data Type Declarations */
typedef struct{
    pin_config_t keypad_row_pins[KEYPAD_ROWS_PINS];
    pin_config_t keypad_colomn_pins[KEYPAD_COLOMN_PINS];
}keypad_t;

/* Section: Functions */
/**
 * 
 * @param _keypad_object
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_object);

/**
 * 
 * @param _keypad_object
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_object, uint8 *value);
#endif	/* ECU_KEYPAD_H */

