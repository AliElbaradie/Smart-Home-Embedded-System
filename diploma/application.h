/* 
 * File:   application.h
 * Author: aliel
 *
 * Created on 19. September 2023, 00:25
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section: Includes */
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/button/ecu_button.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/dc_motor/ecu_dc_motor.h"
#include "ECU_Layer/7_Segment/ecu_seven_seg.h"
#include "ECU_Layer/Keypad/ecu_keypad.h"
#include "ECU_Layer/Char_LCD/ecu_char_lcd.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h" 
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
#include "MCAL_Layer/ADC/hal_adc.h"
#include "MCAL_Layer/Timers/hal_timer0.h"
#include "MCAL_Layer/Timer1/hal_timer1.h"
#include "MCAL_Layer/Timer2/hal_timer2.h"
#include "MCAL_Layer/Timer3/hal_timer3.h"
#include "MCAL_Layer/CCP/hal_ccp.h"
#include "MCAL_Layer/USART/hal_usart.h"
#include "MCAL_Layer/MSSP_SPI/hal_mssp_spi.h"
#include "MCAL_Layer/mssp_i2c_m/hal_mssp_i2c_m.h"

/* Section: Macros */

#define _XTAL_FREQ 8000000UL

/* Section: Macro Functions */

/* Section: Data Type Declarations */

/* Section: Functions */
void application_intialize(void);

#endif	/* APPLICATION_H */

