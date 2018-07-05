/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_stm32l4
 * @{
 *
 * @file
 * @brief           CPU specific definitions for internal peripheral handling
 *
 * @author          Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 */

#ifndef PERIPH_CPU_H
#define PERIPH_CPU_H

#include "periph_cpu_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Starting address of the CPU ID
 */
#define CPUID_ADDR          (0x1fff7590)

/**
 * @brief   Available ports
 */
enum {
    PORT_A = 0,             /**< port A */
    PORT_B = 1,             /**< port B */
    PORT_C = 2,             /**< port C */
    PORT_D = 3,             /**< port D */
    PORT_E = 4,             /**< port E */
    PORT_F = 5,             /**< port F */
    PORT_G = 6,             /**< port G */
    PORT_H = 7,             /**< port H */
};

#ifndef DOXYGEN
/**
 * @brief   Override ADC resolution values
 * @{
 */
#define HAVE_ADC_RES_T
typedef enum {
    ADC_RES_6BIT  = (0x3 << 3),     /**< ADC resolution: 6 bit */
    ADC_RES_8BIT  = (0x2 << 3),     /**< ADC resolution: 8 bit */
    ADC_RES_10BIT = (0x1 << 3),     /**< ADC resolution: 10 bit */
    ADC_RES_12BIT = (0x0 << 3),     /**< ADC resolution: 12 bit */
    ADC_RES_14BIT = (0xfe),         /**< not applicable */
    ADC_RES_16BIT = (0xff)          /**< not applicable */
} adc_res_t;
/** @} */
#endif /* ndef DOXYGEN */


/* ADC channels 0 and 17 are not connected to any GPIO */
#define ADC_VREF_CHANNEL            0
#define ADC_TEMPERATURE_CHANNEL     17
#define ADC_VBAT_CHANNEL            18

/**
 * @brief   ADC line configuration values
 */
typedef struct {
    gpio_t pin;             /**< pin to use */
    uint8_t chan;           /**< internal channel the pin is connected to */
} adc_conf_t;



/**
 * @brief   I2C configuration data structure
 */
typedef struct {
    I2C_TypeDef *dev;       /**< i2c device */
    gpio_t scl;             /**< scl pin number */
    gpio_t sda;             /**< sda pin number */
    gpio_mode_t pin_mode;   /**< with or without pull resistor */
    gpio_af_t af;           /**< I2C alternate function value */
    uint8_t er_irqn;        /**< error IRQ */
    uint8_t ev_irqn;        /**< event IRQ */
} i2c_conf_t;

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CPU_H */
/** @} */
