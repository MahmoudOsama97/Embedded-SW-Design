/*
 * UART.c
 *
 *  Created on: Sep 1, 2020
 *      Author: H
*/

#include "UART.h"


ISR(USART_RXC_vect){
	callBackR();
}




ISR(USART_TXC_vect){
	callBackT();
}

/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
* Output    : Error Status
* */
extern UART_Error_t UART_init(str_UartConfg_t * uart_config){
	
	if(uart_config==NULL) return ERROR_NOK;
	uint32_t BR =uart_config->u32_BaudRate;
	uint8_t datasize =uart_config->u8_DataBits;
	uint8_t flagInterrupt =uart_config->u8_FlagAction;
	
	CLEAR_BIT(SREG,7);
	UART_UBRRL=(FREQ/(16*BR))-1;
	UART_UBRRH=((FREQ/(16*BR))-1)>>8;
	uint8_t ds;
	
	if(datasize==8) ds=3;
	else if(datasize==7) ds=2;
	else if(datasize==6) ds=1;
	else if(datasize==5) ds=0;
	
	
	
	UART_UCSRC= 0x80|(ds<<1);
	UART_UCSRB= 0x18;
	if(flagInterrupt==1)
	UART_UCSRB|=0xC0;
	if(datasize==9)
	UART_UCSRB|=1<<2;
	SET_BIT(SREG,7);
	return ERROR_OK;
}

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
extern UART_Error_t UART_sendByte(const uint8_t u8_Data){
	
	while((UART_UCSRA&0x20)==0x00);
	UART_UDR=u8_Data;
	return ERROR_OK;
}

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
extern UART_Error_t UART_recieveByte(uint8_t *u8_Data){
	if(u8_Data==NULL) return ERROR_NOK;
	while((UART_UCSRA&0x80)==0x00) ;
	*u8_Data=UART_UDR;
	//UART_UCSRA&=~0x80;
	return ERROR_OK;
}


/*************************************************************
*Description: Receiving Flag used in Case of Polling
* Input     : pointer to u8Data
* Output    : No Return
* */
extern void UART_GetPollingFlag(uint8_t *u8_Data){
	
	while((UART_UCSRA&0x80)==0x00) ;
	*u8_Data=UART_UDR;
	//UART_UCSRA&=~0x80;
}


/*************************************************************
*Description: Call Back for function to send to ISR
* Input     : pointer to function
* Output    : ERROR Status
* */
extern UART_Error_t UART_TX_SetCallBack(void (*Copy_FunctionAddress)(void)){
	if(Copy_FunctionAddress==NULL) return ERROR_NOK;
	callBackT=Copy_FunctionAddress;
	return ERROR_OK;
}
/*
*Description: Call Back for function to Receive Data
* Input     : pointer to function
* Output    : ERROR Status
* */
extern UART_Error_t UART_RX_SetCallBack(void (*Copy_FunctionAddress)(void)){
	if(Copy_FunctionAddress==NULL) return ERROR_NOK;
	callBackR=Copy_FunctionAddress;
	return ERROR_OK;
}


