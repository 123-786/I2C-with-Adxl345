/*
 * gpio_interrupt.c
 *
 *  Created on: Sep 8, 2024
 *      Author: anurag
 */

#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "GPIO_interrupt.h"
void gpio_pc13_interrupt_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();


	//Configure PC13

	GPIO_InitStruct.Pin  = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BTN_PORT,&GPIO_InitStruct);

	//Configure PA5

    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT,&GPIO_InitStruct);

    //Configure EXTI
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);


}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//Do something..
	HAL_GPIO_TogglePin(LED_PORT,LED_PIN);
	printf("Button pressed ! \n\r");
}


void EXTI15_10_IRQHandler(void){

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);

}
