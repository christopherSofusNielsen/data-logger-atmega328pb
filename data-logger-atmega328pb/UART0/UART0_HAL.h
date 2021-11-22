/*
 * UART0_HAL.h
 *
 * Created: 04-10-2021 14:23:21
 *  Author: Mainframe
 */ 


#ifndef UART0_HAL_H_
#define UART0_HAL_H_

#include <xc.h>
#include <stdbool.h>

#define UART0_TX_BUFF_LENGTH 200
#define UART0_RX_BUFF_LENGTH 100
#define UART0_END_CHAR_1 '\n'
#define UART0_END_CHAR_2 '\r'


void uart0_hal_init();
void uart0_hal_send_message(uint8_t msg[], uint8_t length);
bool uart0_hal_message_ready();
uint8_t uart0_hal_read_message(uint8_t msg[]);
uint8_t uart0_hal_read_message_as_str(uint8_t msg[]);
void uart0_hal_clear_rx_buffer();
void uart0_hal_send_break(uint8_t followUpByte);


#endif /* UART0_HAL_H_ */