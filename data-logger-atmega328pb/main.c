/*
 * main.c
 *
 * Created: 11/22/2021 10:07:55 AM
 *  Author: ccons
 */ 

#include <xc.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "./UART0/UART0_HAL.h"
#include "bit_operators.h"

//Functions
void ADC_init();
void TC1_init();
void TC1_start();


//Vars
char data[5];
uint16_t cnt=0;


int main(void)
{
	uart0_hal_init();
	char msg[]="Running ";
	uart0_hal_send_message((uint8_t *) msg, strlen(msg));
	TC1_init();
	ADC_init();
	set_bit(DDRE, 0);
	set_bit(PORTE, 0);
	
	TC1_start();
	
	
    while(1)
    {
		
		_delay_ms(2000);
        //TODO:: Please write your application code 
    }
}


void ADC_init(){
	//https://www.arnabkumardas.com/arduino-tutorial/adc-register-description/
	ADMUX=0b01000100; //AREF=VCC, ADC4
	ADCSRA=0b10111110;
	ADCSRB=0b00000101; //TC1 Compare B
}

void TC1_init(){
	TCCR1A=0x00; //CTC
	TCCR1B=0b00001000;//CTC, 0 prescale
	TIMSK1=0b00000100;
	sei();
}

void TC1_start(){
	TCNT1=0x00;//Move to start
	OCR1A=1000;//500 Hz -> 1000 interrupts -> measurements
	OCR1B=1000;//500 Hz -> 1000 interrupts -> measurements
	TCCR1B|=0b00000010; //8 prescale
}


//ADC done vect
ISR(ADC_vect){
	uint16_t val=ADC;
	sprintf(data, "%u\n", val);
	uart0_hal_send_message((uint8_t *) data, strlen(data));
	//cnt++;
	//if(cnt>100){
		//cnt=0;
		//sprintf(data, "S\n");
		//uart0_hal_send_message((uint8_t *) data, strlen(data));
	//}
}

//TC1 vect
ISR(TIMER1_COMPB_vect){
	toggle_bit(PORTE, 0);
}
