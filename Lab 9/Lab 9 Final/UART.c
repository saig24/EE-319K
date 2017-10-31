// UART1.c
// Runs on LM4F120/TM4C123
// Use UART1 to implement bidirectional data transfer to and from 
// another microcontroller in Lab 9.  This time, interrupts and FIFOs
// are used.
// Daniel Valvano
// November 17, 2014
// Modified by EE345L students Charlie Gough && Matt Hawk
// Modified by EE345M students Agustinus Darmawan && Mingjie Qiu

/* Lab solution, Do not post
 http://users.ece.utexas.edu/~valvano/
*/

// U1Rx (VCP receive) connected to PC4
// U1Tx (VCP transmit) connected to PC5
#include <stdint.h>
#include "FiFo.h"
#include "UART.h"
#include "tm4c123gh6pm.h"
#define PF3       (*((volatile uint32_t *)0x40025020))

uint32_t DataLost = 0; 
uint32_t RxCounter = 0;
// Initialize UART1
// Baud rate is 115200 bits/sec
// Make sure to turn ON UART1 Receiver Interrupt (Interrupt 6 in NVIC)
// Write UART1_Handler
void UART_Init(void){
   // --UUU-- complete with your code
	FiFo_Init();//fifo init
	SYSCTL_RCGC1_R |= 0x00000002;//active uart1
	SYSCTL_RCGC2_R |= 0x00000004;//ACTIVATE portc
	UART1_CTL_R &= ~0x00000001;//disable uart
	UART1_IBRD_R = 43;//DIVIDER INTEGER = 115200 BauD RATE
	UART1_FBRD_R = 26; //REMAINDER
	UART1_LCRH_R = 0x00000070;//8 bit, no parity bits, one stop, FIFOs
	UART1_CTL_R |= 0x00000001;//ENABLE UART
	GPIO_PORTC_AFSEL_R |= 0x30;//PC5 AND PC4 alt funct
	GPIO_PORTC_DEN_R |= 0x30;//enable pc5-4
	GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF) +0x00220000;
	GPIO_PORTC_AMSEL_R &= ~0x30;// disable analog on pc5-4
	
}

// input ASCII character from UART
// spin if RxFifo is empty
char UART_InChar(void){
	while((UART1_FR_R&0x0010) != 0){};//WAIT UNTIL RXFE is 0
  return ((char)(UART1_DR_R&0xFF)); // --UUU-- remove this, replace with real code
}
//------------UART1_OutChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART_OutChar(char data){
  // --UUU-- complete with your code
	while((UART1_FR_R&0x0020) != 0){};//wait until TXFF is 0
	UART1_DR_R = data;
}

// hardware RX FIFO goes from 7 to 8 or more items
// UART receiver Interrupt is triggered; This is the ISR
void UART1_Handler(void){
	PF3 ^= 0x08;
	PF3 ^= 0x08;
	while((UART1_FR_R & 0x0010) == 0){
		for(int i = 0; i<8; i++){
			if (FiFo_Put(UART1_DR_R & 0xFF) ==0){
				DataLost ++;
			}
		}
	}
	RxCounter ++;
	UART1_ICR_R = 0x10;//cclears bit in RIS register; acknowledg flag
	PF3 ^= 0x08;
	return;
}
