/* 
 * File:   hal_adc_cfg.h
 * Author: aliel
 *
 * Created on 20. März 2024, 00:06
 */

#ifndef HAL_ADC_CFG_H
#define	HAL_ADC_CFG_H

/* Section: Includes */

/* Section: Macros */

#define ADC_ENABLE  0x01
#define ADC_DISABLE 0x00

#define ADC_CONVERSION_START  0x01
#define ADC_IDLE              0x00

#define ADC_RIGHT_FORMAT  0x01
#define ADC_LEFT_FORMAT   0x00

#define VOLTAGE_REF_ENABLE  0x01
#define VOLTAGE_REF_DISABLE 0x00

/* Section: Macro Functions */

/* Section: Data Type Declarations */

typedef uint16 adc_results_t;

/* Section: Functions */

#endif	/* HAL_ADC_CFG_H */

