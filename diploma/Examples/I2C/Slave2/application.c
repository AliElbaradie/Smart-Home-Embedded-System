/* 
 * File:   application.c
 * Author: aliel
 *
 * Created on 17. September 2023, 20:41
 */


#include "application.h"

mssp_i2c_t i2c_obj;
uint8 slave_ack;
uint8 master_rec_data;
volatile uint8 i2c_slave1_counter;

#define SLAVE_1 0x60
#define SLAVE_2 0x62

/* Address = 0x30 + W Bit (0) => 0x60 */
#define SLAVE_1_Write 0x60
/* Address = 0x30 + R Bit (1) => 0x61 */
#define SLAVE_1_Read  0x61

void I2C_DefaultInterrupt_Handler(void){
    i2c_slave1_counter++;
}

void MSSP_I2C_Read_1_Byte(uint8 slave_add, uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    ret = MSSP_I2C_Master_Send_Start(&i2c_obj);
    ret = MSSP_I2C_Master_Write_Blocking(&i2c_obj, slave_add, &slave_ack);
    ret = MSSP_I2C_Master_Read_Blocking(&i2c_obj, I2C_MASTER_SEND_NACK, _data);
    ret = MSSP_I2C_Master_Send_Stop(&i2c_obj);
}


int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    i2c_obj.i2c_cfg.i2c_mode = I2C_MSSP_SLAVE_MODE;
    i2c_obj.i2c_cfg.i2c_slave_address = 0x62;
    i2c_obj.i2c_cfg.i2c_mode_cfg = I2C_SLAVE_MODE_7BIT_ADDRESS;
    i2c_obj.i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE;
    i2c_obj.i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE;
    i2c_obj.i2c_cfg.i2c_general_call = I2C_GENERAL_CALL_DISABLE;
    i2c_obj.I2C_DefaultInterruptHandler = I2C_DefaultInterrupt_Handler;

    ret = MSSP_I2C_Init(&i2c_obj);
    
    application_intialize();
    

    while(1){   
        
        
        __delay_ms(250);
//        MSSP_I2C_Read_1_Byte(SLAVE_1_Read, &master_rec_data);
//        __delay_ms(250);
//        MSSP_I2C_Read_1_Byte(SLAVE_1_Read, &master_rec_data);
//        __delay_ms(250);
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
}