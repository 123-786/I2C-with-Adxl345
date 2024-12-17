/*
 * uart.h
 *
 *  Created on: Sep 7, 2024
 *      Author: anurag
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx_hal.h"
#include<stdio.h>
void uart_init(void);
int __io_putchar(int ch);
#endif /* UART_H_ */
