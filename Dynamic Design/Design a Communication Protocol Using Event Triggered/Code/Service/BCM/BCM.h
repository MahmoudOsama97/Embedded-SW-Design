/*
 * BCM.h
 *
 * Created: 15/09/2020 05:37:03 م
 *  Author: user
 */ 


#ifndef BCM_H_
#define BCM_H_

#include "../../Infrastructure/AVR_Reg.h"
#include "../../Infrastructure/Common_Macros.h"
#include "../../Infrastructure/std_Types.h"
#include "util/delay.h"
#include "../../Mcal/uart/UART.h"


uint8_t BCM_Init();
uint8_t BCM_Send();
uint8_t BCM_Setup_RxBuffer();
uint8_t BCM_RxDispatcher();
uint8_t BCM_TxDispatcher();





#endif /* BCM_H_ */