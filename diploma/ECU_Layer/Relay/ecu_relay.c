/* 
 * File:   ecu_relay.c
 * Author: aliel
 *
 * Created on 29. Oktober 2023, 12:24
 */

#include "ecu_relay.h"

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t *relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t relay_pin = {.port = relay->relay_port,
                                    .pin = relay->relay_pin,
                                    .direction = OUTPUT,
                                    .logic = relay->relay_status};
        gpio_pin_initialize(&relay_pin);
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t relay_pin = {.port = relay->relay_port,
                                    .pin = relay->relay_pin,
                                    .direction = OUTPUT,
                                    .logic = relay->relay_status};
        gpio_pin_write_logic(&relay_pin, HIGH);
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *relay){
    Std_ReturnType ret = E_OK;
    if(NULL == relay){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t relay_pin = {.port = relay->relay_port,
                                    .pin = relay->relay_pin,
                                    .direction = OUTPUT,
                                    .logic = relay->relay_status};
        gpio_pin_write_logic(&relay_pin, LOW);
    }
    return ret;
}
