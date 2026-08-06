/* 
 * File:   ecu_dc_motor.h
 * Author: aliel
 *
 * Created on 1. November 2023, 16:37
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section: Includes */

#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */

#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PINS_NUMBER 2

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U

/* Section: Macro Functions */

/* Section: Data Type Declarations */

typedef struct{
    pin_config_t dc_motor_pin[DC_MOTOR_PINS_NUMBER]; 
}dc_motor_t;

/* Section: Software Interfaces */

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor);

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_moto_move_right(const dc_motor_t *_dc_motor);

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_moto_move_left(const dc_motor_t *_dc_motor);

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

