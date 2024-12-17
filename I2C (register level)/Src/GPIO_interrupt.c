/*
 * GPIO_interrupt.c
 *
 *  Created on: Jul 8, 2024
 *      Author: anurag
 */


#include "GPIO_interrupt.h"
#include "stm32f4xx.h"

#define GPIOCEN (1U<<2)
//pc13

void pc13_exti_init(void){

	__disable_irq();
	/*Enable push button*/

	RCC->AHB1RSTR|=GPIOCEN;
	GPIOC->MODER&=~(1U<<26);
	GPIOC->MODER&=~(1U<<27);

	/*enable clock access to syscnfg*/
	RCC->APB2ENR|=(1U<<14);

	/*enable exti13 line* unmasking / 	 */
	EXTI->IMR|=(1U<<13);

	/*enable port c in exti13 line*/
	SYSCFG->EXTICR[3]|=(1U<<5);

	/*enabling falling edge in exti13*/
	EXTI->FTSR|=(1U<<13);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();



}
