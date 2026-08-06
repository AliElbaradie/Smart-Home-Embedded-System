/* 
 * File:   ecu_relay.h
 * Author: aliel
 *
 * Created on 29. Oktober 2023, 12:24
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section: Includes */

#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */

#define RELAY_STATUS_ON 0x01U
#define RELAY_STATUS_OFF 0x00U

typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;

/* Section: Macro Functions */

/* Section: Data Type Declarations */

/* Section: Functions */

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t *relay);

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *relay);

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *relay);

#endif	/* ECU_RELAY_H */

