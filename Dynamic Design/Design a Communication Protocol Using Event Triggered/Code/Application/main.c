

#include "../Mcal/Dio/Dio.h"
#include "../Mcal/timer/timer.h"
#include "../Mcal/uart/UART.h"
#include "avr/interrupt.h"
#include "../Mcal/Interrupt/interrupt.h"
#include "../Hal/LCD/lcd.h"
#include "../Hal/PWM/PWM.h"
#include "../Hal/Motor/Motor.h"
#include "../Infrastructure/AVR_Reg.h"
#include "../Service/BCM/BCM.h"


void system_Init(void){
	
	BCM_Init();
}

int main(void){  
	uint8_t arrayT[4]={1,2,3,4};
	uint8_t arrayR[6];	
	system_Init();
	BCM_Send(arrayT,4);
	BCM_Setup_RxBuffer(arrayR,6);
	
	while(1){
		
		BCM_RxDispatcher();
		BCM_TxDispatcher();
		}
}