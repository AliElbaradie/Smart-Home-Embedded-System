/* 
 * File:   ecu_button.c
 * Author: aliel
 *
 * Created on 25. Oktober 2023, 18:26
 */

#include "ecu_button.h"

/**
 * 
 * @param btn
 * @return 
 */
Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;   
    if(NULL == btn){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        ret = gpio_pin_direction_initialize(&(btn->button_pin));
    }
    return ret;
}

/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state){
    Std_ReturnType ret = E_OK; 
    logic_t pin_logic = LOW;
    if((NULL == btn) || (NULL == btn_state)){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        ret = gpio_pin_read_logic(&(btn->button_pin), &pin_logic);
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(HIGH == pin_logic){
                *btn_state = BUTTON_PRESSED;
            }else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(HIGH == pin_logic){
                *btn_state = BUTTON_RELEASED;
            }else{
                *btn_state = BUTTON_PRESSED;
            }
        }
    }
    return ret;
}