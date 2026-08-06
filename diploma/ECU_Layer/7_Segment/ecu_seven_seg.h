/* 
 * File:   ecu_seven_seg.h
 * Author: aliel
 *
 * Created on 22. November 2023, 17:19
 */

#ifndef ECU_SEVEN_SEG_H
#define	ECU_SEVEN_SEG_H

/* Section: Includes */

#include "ecu_seven_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macros */

#define SEVEN_SEG_PIN0 0
#define SEVEN_SEG_PIN1 1
#define SEVEN_SEG_PIN2 2
#define SEVEN_SEG_PIN3 3

/* Section: Macro Functions */

/* Section: Data Type Declarations */

typedef enum{
    SEVEN_SEG_COMMON_ANODE = 0,
    SEVEN_SEG_COMMON_CATHODE
}seven_seg_t;

typedef struct{
    pin_config_t seven_seg_pins[4];
    seven_seg_t seven_seg_types;
}seg_t;

/* Section: Functions */

/**
 * 
 * @param seg
 * @return 
 */
Std_ReturnType seven_segment_initialize(const seg_t *seg);

/**
 * 
 * @param seg
 * @param number
 * @return 
 */
Std_ReturnType seven_segment_write_number(const seg_t *seg, uint8 number);

#endif	/* ECU_SEVEN_SEG_H */

