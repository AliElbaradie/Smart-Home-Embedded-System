/* 
 * File:   ecu_seven_seg.c
 * Author: aliel
 *
 * Created on 22. November 2023, 17:19
 */

#include "ecu_seven_seg.h"

/**
 * 
 * @param seg
 * @return 
 */
Std_ReturnType seven_segment_initialize(const seg_t *seg){
    Std_ReturnType ret = E_OK;
    if(NULL == seg){
        ret = E_NOT_OK;
    }else{
        gpio_pin_initialize(&(seg->seven_seg_pins[SEVEN_SEG_PIN0]));
        gpio_pin_initialize(&(seg->seven_seg_pins[SEVEN_SEG_PIN1]));
        gpio_pin_initialize(&(seg->seven_seg_pins[SEVEN_SEG_PIN2]));
        gpio_pin_initialize(&(seg->seven_seg_pins[SEVEN_SEG_PIN3]));
        
    }
    return ret;
}

/**
 * 
 * @param seg
 * @param number
 * @return 
 */
Std_ReturnType seven_segment_write_number(const seg_t *seg, uint8 number){
    Std_ReturnType ret = E_OK;
    if((NULL == seg) || (9 < number)){
        ret = E_NOT_OK;
    }else{
        ret = gpio_pin_write_logic(&(seg->seven_seg_pins[0]), (number)&0x01);
        ret = gpio_pin_write_logic(&(seg->seven_seg_pins[1]), (number>>1)&0x01);
        ret = gpio_pin_write_logic(&(seg->seven_seg_pins[2]), (number>>2)&0x01);
        ret = gpio_pin_write_logic(&(seg->seven_seg_pins[3]), (number>>3)&0x01);
    }
    return ret;
}