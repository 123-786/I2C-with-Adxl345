/*
 * GPIO_interrupt.h
 *
 *  Created on: Sep 8, 2024
 *      Author: anurag
 */

#ifndef GPIO_INTERRUPT_H_
#define GPIO_INTERRUPT_H_

#include <stdio.h>
#include "stm32f4xx_hal.h"
#define BTN_PORT	GPIOC
#define BTN_PIN		GPIO_PIN_13
#define LED_PORT	GPIOA
#define LED_PIN		GPIO_PIN_5
void gpio_pc13_interrupt_init(void);


#endif /* GPIO_INTERRUPT_H_ */
