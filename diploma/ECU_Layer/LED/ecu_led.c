/* 
 * File:   ecu_led
 * Author: aliel
 *
 * Created on 17. September 2023, 20:41
 */

#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led){
    Std_ReturnType ret = E_OK;   
    if(NULL == led){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t pin = {.port = led->port, .pin = led->pin, 
                        .direction = OUTPUT, .logic = led->logic};
 
        ret = gpio_pin_initialize(&pin);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t pin = {.port = led->port, .pin = led->pin, 
                        .direction = OUTPUT, .logic = led->logic};
 
        gpio_pin_write_logic(&pin, HIGH);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(NULL == led){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t pin = {.port = led->port, .pin = led->pin, 
                        .direction = OUTPUT, .logic = led->logic};
 
        gpio_pin_write_logic(&pin, LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;

    if(NULL == led){
        Std_ReturnType ret = E_NOT_OK;
    }else{
        pin_config_t pin = {.port = led->port, .pin = led->pin, 
                        .direction = OUTPUT, .logic = led->logic};
 
        gpio_pin_toggle_logic(&pin);
    }
    return ret;
}