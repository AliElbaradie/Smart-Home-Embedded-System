/* 
 * File:   hal_mssp_spi.c
 * Author: aliel
 *
 * Created on 4. September 2024, 12:29
 */

#include "hal_mssp_spi.h"

static void (*SPI_InterruptHandler_Callbak)(void) = NULL;

//
/* Initialize SPI Object */
//
Std_ReturnType SPI_initialize(const spi_object_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }else{
        
        MSSP_MODULE_DISABLE();
        
        ret = gpio_pin_initialize(&(_spi->clock_pin));
        ret = gpio_pin_initialize(&(_spi->SDO_pin));
        ret = gpio_pin_initialize(&(_spi->SS_pin));
        ret = gpio_pin_initialize(&(_spi->slave_1_choose_pin));
        
        /* Clock Line Idle State */
        if(SPI_CLOCK_POLARITY_IDLE_HIGH == _spi->SPI_clock_polarity_select){
            SPI_SET_CLOCK_POLARITY_IDLE_HIGH();
        }else if(SPI_CLOCK_POLARITY_IDLE_LOW == _spi->SPI_clock_polarity_select){
            SPI_SET_CLOCK_POLARITY_IDLE_LOW();
        }else{
            /*Nothing*/
        }
        
        /* Transmit when Idle to Active or Active to Idle */
        if(SPI_ACTIVE_TO_IDLE == _spi->SPI_output_data_clock_edge){
            SPI_TRANSMIT_ACTIVE_TO_IDLE();
        }else if(SPI_IDLE_TO_ACTIVE == _spi->SPI_output_data_clock_edge){
            SPI_TRANSMIT_IDLE_TO_ACTIVE();
        }else{
            /*Nothing*/
        }
        
        /* Sample data at End or Middle */
        if(SPI_SAMPLE_AT_END == _spi->SPI_input_data_sample){
            SPI_DATA_SAMPLE_AT_END();
        }else if(SPI_SAMPLE_AT_MIDDLE == _spi->SPI_input_data_sample){
            SPI_DATA_SAMPLE_AT_MIDDLE();
        }else{
            /*Nothing*/
        }
        
        SPI_SELECT_MODE(_spi->spi_selected_mode);
        
        SPI_InterruptHandler_Callbak = _spi->SPI_InterruptHandler;
        SPI_InterruptFlagClear();
        SPI_InterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        
        MSSP_MODULE_ENABLE();
        
    }
    return ret;
}

//
/* SPI Read Data */
//
Std_ReturnType SPI_Read_Byte(uint8 *_data_hold){
    while(!(SSPSTATbits.BF));
    *_data_hold = SSPBUF;
}

//
/* SPI Start Transmitting */
//
Std_ReturnType SPI_Write_Byte(const spi_object_t *_spi, uint8 _data){
    Std_ReturnType ret = E_OK;
    
    ret = gpio_pin_write_logic(&(_spi->slave_1_choose_pin), LOW);
    if(1 == SSPSTATbits.BF){
        uint8 dummy_read = SSPBUF;
        SSPBUF = _data;
    }else{
        SSPBUF = _data;
    }
    ret = gpio_pin_write_logic(&(_spi->slave_1_choose_pin), HIGH);
    
    return ret;
}

void SPI_ISR(void){
    SPI_InterruptFlagClear();
    SPI_InterruptHandler_Callbak();
}