

#ifndef UART_H_
#define UART_H_
#include <stdint.h>

#include "stm32f4xx.h"

void uart2_tx_init(void);
char uart2_read(void);
void uart2_rxtx_init(void);
#define line13 (1U<<13)

#endif /* UART_H_ */
