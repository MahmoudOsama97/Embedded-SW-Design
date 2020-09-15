/*
 * timer.h
 *
 *  Created on: Aug 31, 2020
 *      Author: H
 */

#ifndef TIMER_DRIVER_TIMER_H_
#define TIMER_DRIVER_TIMER_H_

#include "../../Infrastructure/AVR_Reg.h"
#include "../../Infrastructure/Common_Macros.h"
#include "../../Infrastructure/Std_Types.h"
#include "timer_cfg.h"
#include "avr/interrupt.h"
typedef struct
{
  uint8_t Timer_Channel; /*Timer Channel (Timer0 or Timer1 or Timer2*/
  uint8_t Timer_Psc;     /*Timer Prescaler Based on DataSheet No prescaler or /8 or /64 or .....*/
  uint8_t Timer_Mode;    /*Timer Mode Timer or Counter*/
  uint8_t Interrupt_Mode; /*Timer Overflow Mode Interrupt or polling*/
}Str_TimerConfiguration_t;

/*_______________________________________________________________________________________________________________________________*/
/*________________________________________________________________*/
/******************************************************************/
/*                        MACROS                                  */
/******************************************************************/
#define NO_OF_CHANNELS 3

/*________________________________________________________________*/
/******************************************************************/
/*                        TIMER_CHANNELS                          */
/******************************************************************/
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
/*________________________________________________________________*/
/******************************************************************/
/*                        TIMER_CHANNELS OverFlow                 */
/******************************************************************/
#define TIMER0_OVERFLOW 255
#define TIMER1_OVERFLOW 65536
#define TIMER2_OVERFLOW 255
/*________________________________________________________________*/
/******************************************************************/
/*                        TIMER_MODE                              */
/******************************************************************/
#define TIMER_MODE 0
#define COUNTER_MODE 1

/*________________________________________________________________*/
/******************************************************************/
/*                        PreScaler                               */
/******************************************************************/

/*________Timer0__________________________________*/
#define NO_CLOCK_TIMER_0     					0
#define F_CPU_CLOCK_TIMER_0   					1
#define F_CPU_CLOCK_8_TIMER_0 					2
#define F_CPU_CLOCK_64_TIMER_0					3
#define F_CPU_CLOCK_256_TIMER_0					4
#define F_CPU_CLOCK_1024_TIMER_0				5
#define F_EXTERNAL_CLOCK_FALLING_TIMER_0		6
#define F_EXTERNAL_CLOCK_RISING_TIMER_0			7

/*________Timer1__________________________________*/
#define NO_CLOCK_TIMER_1     					0
#define F_CPU_CLOCK_TIMER_1   					1
#define F_CPU_CLOCK_8_TIMER_1 					2
#define F_CPU_CLOCK_64_TIMER_1					3
#define F_CPU_CLOCK_256_TIMER_1					4
#define F_CPU_CLOCK_1024_TIMER_1				5
#define F_EXTERNAL_CLOCK_FALLING_TIMER_1		6
#define F_EXTERNAL_CLOCK_RISING_TIMER_1			7

/*________Timer2__________________________________*/
#define NO_CLOCK_TIMER_2     					0
#define F_CPU_CLOCK_TIMER_2   					1
#define F_CPU_CLOCK_8_TIMER_2 					2
#define F_CPU_CLOCK_32_TIMER_2					3
#define F_CPU_CLOCK_64_TIMER_2					4
#define F_CPU_CLOCK_128_TIMER_2					5
#define F_CPU_CLOCK_256_TIMER_2		 			6
#define F_CPU_CLOCK_1024_TIMER_2				7

/*________________________________________________________________*/
/******************************************************************/
/*                        OverFlow Mode                           */
/******************************************************************/

#define POLLING      0
#define INTERRUPT    1

/*________________________________________________________________*/
/******************************************************************/
/*                        ERROR STATUS                            */
/******************************************************************/
#define ERROR_OK     0
#define ERROR_NOK    1
/*______________________________________________________________________________________________________________________________*/

#define  STATUS_REGISTER SREG
#define  GLOBAL_INTERRUPT_BIT 7

#define TIMER0_COUNTER_REGISTER TIMER0_TCNT0
#define TIMER0_CONTROL_REGISTER TIMER0_TCCR0
#define TIMER0_CONTROL_WAVEGENERATION_0 6
#define TIMER0_CONTROL_WAVEGENERATION_1 3
#define TIMER0_OUTPUT_COMPARE_MATCH TIMER0_OCR0
#define TIMER0_INTERRUPT_MASK_REGISTER TIMER0_TIMSK
#define TIMER0_INTERRUPT_OVERFLOW_ENABLE_BIT TIMER0_TIMSK_TOIE0
#define TIMER0_INTERRUPT_COMPARE_MATCH_ENABLE_BIT TIMER0_TIMSK_OCIE0
#define TIMER0_INTERRUPT_FLAG_REGISTER TIMER0_TIFR
#define TIMER0_INTERRUPT_OVERFLOW_FLAG_BIT 0
#define TIMER0_INTERRUPT_COMPARE_MATCH_FLAG_BIT 1


#define TIMER1_COUNTER_REGISTER TIMER1_TCNT1
#define TIMER1_CONTROL_REGISTER_B TIMER1_TCCR1B
#define TIMER1_CONTROL_REGISTER_A TIMER1_TCCR1A
#define TIMER1_INTERRUPT_FLAG_REGISTER TIMER1_TIFR
#define TIMER1_INTERRUPT_OVERFLOW_FLAG_BIT TIMER1_TIFR_TOV1
#define TIMER1_INTERRUPT_MASK_REGISTER TIMER1_TIMSK
#define TIMER1_INTERRUPT_OVERFLOW_ENABLE_BIT TIMER1_TIMSK_TOIE1

#define TIMER_RESET      0
#define CLR_PRE_SCALLER 0xf8  

#define SYSTEM_CLOCK 1
#define TICKTIME_SYSTEM_CLOCK_US 0   
#define TICKTIME_8_US            8 
#define TICKTIME_64_US           64
#define TICKTIME_256_US          256
#define TICKTIME_1024_US         1024
/*________________________________________________________________*/
/******************************************************************/
/*                        FUNCTIONS PROTOTYPES                    */
/******************************************************************/



/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler, Timer mode , Mode as described in Struct)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Init(Str_TimerConfiguration_t* Confg_S);
/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Start
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), Tick Counting (Counts given by user)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Start(uint8_t Copy_uint8_TimerChannel,uint32_t Copy_uint32_TickCounts);
/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Stop
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Stop(uint8_t Copy_uint8_TimerChannel);
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer Reset
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Reset(uint8_t Copy_uint8_TimerChannel);
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Get Timer Tick Time value to use it by user
 * Input     : Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), *Timer_Time (Pointer to return Value)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Get_TickTime(uint8_t Copy_uint8_TimerChannel, uint32_t *Copy_uint8Ptr_TimerTickTime);
/*_______________________________________________________________________________________________________________________________*/




#endif /* TIMER_DRIVER_TIMER_H_ */
