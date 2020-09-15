/*
 * UART.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef UART_DRIVER_UART_H_
#define UART_DRIVER_UART_H_

#include "../../Infrastructure/AVR_Reg.h"
#include "../../Infrastructure/Common_Macros.h"
#include "../../Infrastructure/Std_Types.h"
#include "UART_cfg.h"
#include "avr/interrupt.h"

typedef struct
{
 uint32_t u32_BaudRate;
 uint8_t u8_DataBits;  /* (5~9) bits */
 uint8_t u8_FlagAction;  /***interrupt or polling***/
}str_UartConfg_t;


typedef uint8_t UART_Error_t;


void (*callBackR)(void);
void (*callBackT)(void);

/*- FUNCTION-LIKE MACROS -----------------------------------*/

#define DISABLE       0U
#define ENABLE        1U

#define UART_ONE_STOP_BIT  0U
#define UART_TWO_STOP_BITS 1U


#define UART_POLLING 0U
#define UART_INTERRUPT 1U

#define ERROR_OK     0
#define ERROR_NOK    1

#define UART_FLAG_ACTION 4U
#define UART_ALL_INTERRUPT_DISABLED 5U

#define UART_PARITY_EVEN 0U
#define UART_PARITY_ODD 1U
#define UART_NO_PARITY  2U

#define UART_5_BIT_MODE 0
#define UART_6_BIT_MODE 1
#define UART_7_BIT_MODE 2
#define UART_8_BIT_MODE 3
#define UART_9_BIT_MODE 7


/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : poiter to uart configuration struct
* Output    : Error Status
* */
extern UART_Error_t UART_init(str_UartConfg_t * uart_config);

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
extern UART_Error_t UART_sendByte(const uint8_t u8_Data);

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
extern UART_Error_t UART_recieveByte(uint8_t *u8_Data);



extern void UART_GetPollingFlag(uint8_t *u8_Data);

/*************************************************************
*Description: Call Back for function to send to ISR
* Input     : pointer to function
* Output    : ERROR Status
* */
extern UART_Error_t UART_TX_SetCallBack(void (*Copy_FunctionAddress)(void));
/*
*Description: Call Back for function to Receive Data
* Input     : pointer to function
* Output    : ERROR Status
* */
extern UART_Error_t UART_RX_SetCallBack(void (*Copy_FunctionAddress)(void));

#endif /* UART_DRIVER_UART_H_ */
