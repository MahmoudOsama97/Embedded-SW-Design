/*
 * timer.c
 *
 *  Created on: Aug 31, 2020
 *      Author: H
 */
#include "timer.h"

/////////////////////////////////////////////local buffer ///////////////////////////////////////////////////////
static uint8_t prescale[NO_OF_CHANNELS];
static uint8_t interrupt[NO_OF_CHANNELS];
 

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Initialization
 * Input     : Timer_Configuration_S* Confg_S (Struct contain : Timer Channel, Prescaler , Mode as described in Struct)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Init(Str_TimerConfiguration_t* Confg_S)
{
	if(Confg_S==NULL) return ERROR_NOK;
	if(Confg_S->Timer_Channel==TIMER0){
		TIMER0_COUNTER_REGISTER=TIMER_RESET;
		interrupt[TIMER0]=Confg_S->Interrupt_Mode;
		prescale[TIMER0]=Confg_S->Timer_Psc;
		SET_BIT(TIMER0_CONTROL_REGISTER,7);
		if(Confg_S->Timer_Mode==TIMER_MODE){
		CLEAR_BIT(TIMER0_CONTROL_REGISTER,TIMER0_CONTROL_WAVEGENERATION_0);
		CLEAR_BIT(TIMER0_CONTROL_REGISTER,TIMER0_CONTROL_WAVEGENERATION_1); 
		}
		else if(Confg_S->Timer_Mode==COUNTER_MODE){
			CLEAR_BIT(TIMER0_CONTROL_REGISTER,TIMER0_CONTROL_WAVEGENERATION_0);
			SET_BIT(TIMER0_CONTROL_REGISTER,TIMER0_CONTROL_WAVEGENERATION_1); 
			TIMER0_OUTPUT_COMPARE_MATCH=COMPARE_VALUE;
		}			
		CLEAR_BIT(TIMER0_CONTROL_REGISTER,4);
		CLEAR_BIT(TIMER0_CONTROL_REGISTER,5); 	
	}
	
	return ERROR_OK;
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Start
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), Tick Counting (Counts given by user)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Start(uint8_t Copy_uint8_TimerChannel,uint32_t Copy_uint32_TickCounts)
{
	if(Copy_uint8_TimerChannel>=NO_OF_CHANNELS) return ERROR_NOK;
	if(Copy_uint8_TimerChannel==TIMER0){
		CLEAR_BIT(STATUS_REGISTER,GLOBAL_INTERRUPT_BIT);
		TIMER0_COUNTER_REGISTER=Copy_uint32_TickCounts;
		TIMER0_INTERRUPT_MASK_REGISTER|=interrupt[TIMER0];
		TIMER0_INTERRUPT_MASK_REGISTER|=interrupt[TIMER0]<<1;
		TIMER0_CONTROL_REGISTER|=prescale[TIMER0];
		SET_BIT(STATUS_REGISTER,GLOBAL_INTERRUPT_BIT);
	}
	return ERROR_OK;	
}
/*_______________________________________________________________________________________________________________________________*/


/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer/Counter Stop
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
extern uint8_t Timer_Stop(uint8_t Copy_uint8_TimerChannel)
{
	if(Copy_uint8_TimerChannel>=NO_OF_CHANNELS) return ERROR_NOK;
	if(Copy_uint8_TimerChannel==TIMER0){
		TIMER0_CONTROL_REGISTER&=CLR_PRE_SCALLER;
		}
		return ERROR_OK;
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Timer Reset
 * Input     :  Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Reset(uint8_t Copy_uint8_TimerChannel)
{
	if(Copy_uint8_TimerChannel>=NO_OF_CHANNELS) return ERROR_NOK;
	if(Copy_uint8_TimerChannel==TIMER0){
		TIMER0_COUNTER_REGISTER=TIMER_RESET;
	}
	return ERROR_OK;	
}
/*_______________________________________________________________________________________________________________________________*/

/*_______________________________________________________________________________________________________________________________*/
/*Description: Get Timer Tick Time value to use it by user
 * Input     : Timer Channel(Timer Channel (Timer0 or Timer1 or Timer2), *Timer_Time (Pointer to return Value)
 * Output    : Error Checking
 *_______________________________________________________________________________________________________________________________*/
uint8_t Timer_Get_TickTime(uint8_t Copy_uint8_TimerChannel, uint32_t *Copy_uint8Ptr_TimerTickTime)
{
	if((Copy_uint8Ptr_TimerTickTime==NULL)||(Copy_uint8_TimerChannel>=NO_OF_CHANNELS)) return ERROR_NOK;
	if(Copy_uint8_TimerChannel==TIMER0){
		switch(prescale[0]){
			case 0:
			return ERROR_NOK;
			break;
			case 1:
			*Copy_uint8Ptr_TimerTickTime=TICKTIME_SYSTEM_CLOCK_US;
			break;
			case 2:
			*Copy_uint8Ptr_TimerTickTime=TICKTIME_8_US;
			break;
			case 3:
			*Copy_uint8Ptr_TimerTickTime=TICKTIME_64_US;
			break;
			case 4:
			*Copy_uint8Ptr_TimerTickTime=TICKTIME_256_US;
			break;
			case 5:
			*Copy_uint8Ptr_TimerTickTime=TICKTIME_1024_US;
			break;
			default:
			return ERROR_NOK;
			break;
		}
	}
	return ERROR_OK;	
}
/*_______________________________________________________________________________________________________________________________*/



