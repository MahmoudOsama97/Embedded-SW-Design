/*
 * CProgram1.c
 *
 * Created: 15/09/2020 05:36:38 م
 *  Author: user
 */ 
#include "BCM.h"


str_UartConfg_t uartConfig ={9600,8,1};
uint8_t *ptBuffer;
uint8_t internalBuffer[10];	
uint32_t tSize;	
uint32_t tPostion=0;
uint32_t rSize;
uint32_t rPostion=0;
void functionTx(void){
	
	UART_sendByte(ptBuffer[tPostion]);
	tPostion++;
}

void functionRx(void){
	UART_recieveByte(&internalBuffer[rPostion]);
	rPostion++;
}



uint8_t BCM_Init(){
	
	UART_init(&uartConfig);
	UART_TX_SetCallBack(functionTx);
	UART_RX_SetCallBack(functionRx);
	return 1;
}



uint8_t BCM_Send(uint8_t * arr,uint32_t size){
	
	ptBuffer=arr;
	tSize=size;
	UART_sendByte(ptBuffer[tPostion]);
	tPostion++;
	return 1;
}
uint8_t BCM_Setup_RxBuffer(uint8_t * arr,uint32_t size){
	
	rSize=size;
	arr=internalBuffer;
	
}


uint8_t BCM_RxDispatcher(){
	if(rPostion==rSize-1) return 1;
	else return 0;
	
}
uint8_t BCM_TxDispatcher(){
	
	if(tPostion==tSize-1) return 1;
	else return 0;
}