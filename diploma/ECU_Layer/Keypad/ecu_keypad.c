/* 
 * File:   ecu_keypad.c
 * Author: aliel
 *
 * Created on 19. Dezember 2023, 15:17
 */

#include "ecu_keypad.h"


uint8 button_matrics[KEYPAD_ROWS_PINS][KEYPAD_COLOMN_PINS] =   {{'7','8','9','/'},
                                                                {'4','5','6','*'},
                                                                {'1','2','3','-'},
                                                                {'#','0','=','+'}};

/* Section: Functions */
/**
 * 
 * @param _keypad_object
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_object){
    Std_ReturnType ret = E_OK;
    uint8 l_row_counter = 0, l_colomn_counter = 0;
    if(NULL == _keypad_object){
        ret = E_NOT_OK;
    }else{
        for(l_row_counter = 0; l_row_counter < KEYPAD_ROWS_PINS; l_row_counter++){
            ret = gpio_pin_initialize(&(_keypad_object->keypad_row_pins[l_row_counter]));
        }
        for(l_colomn_counter = 0; l_colomn_counter < KEYPAD_COLOMN_PINS; l_colomn_counter++){
            ret = gpio_pin_initialize(&(_keypad_object->keypad_colomn_pins[l_colomn_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad_object
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_object, uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 l_row_counter = 0, l_colomn_counter = 0, l_counter = 0;
    logic_t pin_logic = LOW;
    if(NULL == _keypad_object || NULL == value){
        ret = E_NOT_OK;
    }else{
        for(l_row_counter = 0; l_row_counter<KEYPAD_ROWS_PINS ; l_row_counter++){
            for(l_counter = 0; l_counter<KEYPAD_ROWS_PINS ; l_counter++){
                ret = gpio_pin_write_logic(&(_keypad_object->keypad_row_pins[l_counter]), LOW);
            }
            ret = gpio_pin_write_logic(&(_keypad_object->keypad_row_pins[l_row_counter]), HIGH);
            for(l_colomn_counter = 0; l_colomn_counter < KEYPAD_COLOMN_PINS; l_colomn_counter++){                
                ret = gpio_pin_read_logic(&(_keypad_object->keypad_colomn_pins[l_colomn_counter]), &pin_logic);
                if(HIGH == pin_logic){
                    *value = button_matrics[l_row_counter][l_colomn_counter];
                }
            }
        }
    }
    return ret;

}