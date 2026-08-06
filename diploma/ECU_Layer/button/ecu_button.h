/* 
 * File:   ecu_button.h
 * Author: aliel
 *
 * Created on 25. Oktober 2023, 18:26
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section: Includes */
#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */
typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_State;
    button_active_t button_connection;
}button_t;

/* Section: Macro Functions */

/* Section: Data Type Declarations */

/* Section: Functions */

/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

