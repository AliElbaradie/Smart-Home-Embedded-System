/* 
 * File:   hal_mssp_spi.h
 * Author: aliel
 *
 * Created on 4. September 2024, 12:29
 */

#ifndef HAL_MSSP_SPI_H
#define	HAL_MSSP_SPI_H

/* ----------------- Includes -----------------*/
#include "mssp_spi_cfg.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/* ----------------- Macro Declarations -----------------*/
#define MSSP_ENABLE  1
#define MSSP_DISABLE 0

#define SPI_MASTER_MODE 1
#define SPI_SLAVE_MODE  0

#define SPI_SAMPLE_AT_END    1
#define SPI_SAMPLE_AT_MIDDLE 0

#define SPI_ACTIVE_TO_IDLE 1
#define SPI_IDLE_TO_ACTIVE 0

#define SPI_RECIEVE_COMPLETE     1
#define SPI_RECIEVE_NOT_COMPLETE 0

#define SPI_COLLISION_DETECTED 1
#define SPI_CLEAR_COLLISION    0

#define SPI_OVERFLOW_DETECTED 1
#define SPI_CLEAR_OVERFLOW    0

#define SPI_CLOCK_POLARITY_IDLE_HIGH 1
#define SPI_CLOCK_POLARITY_IDLE_LOW  0

/* ----------------- Macro Functions Declarations -----------------*/

#define SPI_IS_RECIEVING_DATA_COMPLETED() (SSPSTATbits.BF)

#define SPI_CLEAR_DETECTED_COLLISION() (SSPCON1bits.WCOL = SPI_CLEAR_COLLISION)

#define SPI_CLEAR_OVERFLOW() (SSPCON1bits.SSPOV = SPI_CLEAR_OVERFLOW)

#define SPI_READ_BUFFER_REGISTER(_DATA) (_DATA =  SSPBUF) /*Read even transmitting, to avoid Data Overflow*/

#define MSSP_MODULE_ENABLE()  (SSPCON1bits.SSPEN = MSSP_ENABLE)
#define MSSP_MODULE_DISABLE() (SSPCON1bits.SSPEN = MSSP_DISABLE)

#define SPI_SET_CLOCK_POLARITY_IDLE_HIGH() (SSPCON1bits.CKP = SPI_CLOCK_POLARITY_IDLE_HIGH)
#define SPI_SET_CLOCK_POLARITY_IDLE_LOW() (SSPCON1bits.CKP = SPI_CLOCK_POLARITY_IDLE_LOW)

#define SPI_DATA_SAMPLE_AT_END() (SSPSTATbits.SMP = SPI_SAMPLE_AT_END)   
#define SPI_DATA_SAMPLE_AT_MIDDLE() (SSPSTATbits.SMP = SPI_SAMPLE_AT_MIDDLE) 

#define SPI_TRANSMIT_ACTIVE_TO_IDLE() (SSPSTATbits.CKE = SPI_ACTIVE_TO_IDLE) 
#define SPI_TRANSMIT_IDLE_TO_ACTIVE() (SSPSTATbits.CKE = SPI_IDLE_TO_ACTIVE)

#define SPI_SELECT_MODE(_MODE) (SSPCON1bits.SSPM = _MODE)

/* ----------------- Data Type Declarations -----------------*/

typedef enum {
    SPI_MASTER_MODE_FOSC_DIVIDED_BY_4 = 0,
    SPI_MASTER_MODE_FOSC_DIVIDED_BY_16,
    SPI_MASTER_MODE_FOSC_DIVIDED_BY_64,
    SPI_MASTER_MODE_TIMER2_DIVIDED_BY_2,
    SPI_SLAVE_MODE_SS_PIN_ENABLED,
    SPI_SLAVE_MODE_SS_PIN_DISABLED
}spi_select_mode_t;

typedef struct {
    void (*SPI_InterruptHandler)(void);
    pin_config_t slave_1_choose_pin;                 /*Write Logic Low to Start Communication*/
    pin_config_t SDO_pin;                            /*SDO must be configuered OUTPUT (RC5)*/
    pin_config_t SS_pin;                             /*SDO must be configuered INPUT (RA5)*/
    pin_config_t clock_pin;                          /*If Master, then SCK = OUTPUT. If Slave, then SCK = INPUT. (RC3)*/
    spi_select_mode_t spi_selected_mode;             /*SPI Working Mode*/
    uint8 SPI_Master_or_Slave : 1;                   /*SCK Pin is Input or Output*/
    uint8 SPI_clock_polarity_select : 1;             /*Idle High or Low*/
    uint8 SPI_output_data_clock_edge : 1;            /*Idle to Active or Active to Idle*/
    uint8 SPI_input_data_sample : 1;                 /*Middle or End*/
    uint8 reserved : 4;
}spi_object_t;

/* ----------------- Software Interfaces Declarations -----------------*/

Std_ReturnType SPI_initialize(const spi_object_t *_spi);
Std_ReturnType SPI_Write_Byte(const spi_object_t *_spi, uint8 _data);
Std_ReturnType SPI_Read_Byte(uint8 *_data_hold);

// Function to Start Communication with a specifi Slave
// Function to Stop Communication

#endif	/* HAL_MSSP_SPI_H */

