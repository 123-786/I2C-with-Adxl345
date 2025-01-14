/*
 * uart.c
 *
 *  Created on: Sep 7, 2024
 *      Author: anurag
 */
#include "stm32f4xx_hal.h"
#include<stdio.h>
#include "uart.h"
UART_HandleTypeDef huart2;


int __io_putchar(int ch)
	  {
	  	HAL_UART_Transmit(&huart2,(uint8_t*)&ch,1,10);
	  	return ch;
	  }
void uart_init(void)
{

	 GPIO_InitTypeDef GPIO_InitStruct = {0};

    //Enable UART pins clock access
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Enable UART module clock access
    __HAL_RCC_USART2_CLK_ENABLE();


	//Configure pins to act as alternate func pins(UART)

     GPIO_InitStruct.Pin  = GPIO_PIN_2|GPIO_PIN_3;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
     GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
     GPIO_InitStruct.Pull =  GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

     HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

     //Configure UART TX module
     huart2.Instance = USART2;
     huart2.Init.BaudRate = 115200;
     huart2.Init.WordLength = UART_WORDLENGTH_8B;
     huart2.Init.StopBits = UART_STOPBITS_1;
     huart2.Init.Parity = UART_PARITY_NONE;
     huart2.Init.Mode = UART_MODE_TX;
     huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
     huart2.Init.OverSampling = UART_OVERSAMPLING_16;

     HAL_UART_Init(&huart2);

     //Configure UART RX module
          /*huart2.Instance = USART2;
          huart2.Init.BaudRate = 115200;
          huart2.Init.WordLength = UART_WORDLENGTH_8B;
          huart2.Init.StopBits = UART_STOPBITS_1;
          huart2.Init.Parity = UART_PARITY_NONE;
          huart2.Init.Mode = UART_MODE_TX_RX;
          huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
          huart2.Init.OverSampling = UART_OVERSAMPLING_16;

          HAL_UART_Init(&huart2);*/


}
