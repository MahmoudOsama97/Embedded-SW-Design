#include "interrupt.h"

void (*int0_callback)(void) ;
void (*int1_callback)(void) ;

ISR(INT0_vect)
{
	int0_callback();
}

ISR(INT1_vect)
{
	int1_callback();
}



extern uint8_t interrupt0_init(uint8_t type, void (*callBack)(void)){
	
	if(callBack==NULL) return ERROR_NOK;
	if(type>2) return ERROR_NOK;
	int0_callback = callBack;
	SREG  &= ~(1<<INT_BIT);                                           // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));										// Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);											// Enable external interrupt pin INT0
	if(type != BOTH) {MCUCR |= (type<<ISC00) | (1<<ISC01);}     // Trigger INT0 with the rising/falling edge
	else {MCUCR |= (1<<ISC00);	}								// Trigger INT0 with the both edges
	SREG = SREG | (1<<INT_BIT);									// Enable interrupts by setting I-bit
	return ERROR_OK;										
}

extern uint8_t interrupt1_init(uint8_t type, void (*callBack)(void)){
	
	if(callBack==NULL) return ERROR_NOK;
	if(type>2) return ERROR_NOK;
	int1_callback = callBack;
	SREG  &= ~(1<<INT_BIT);                                           // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD3));										// Configure INT0/PD2 as input pin
	GICR  |= (1<<INT1);											// Enable external interrupt pin INT0
	if(type != BOTH) {MCUCR |= (type<<ISC10) | (1<<ISC11);}     // Trigger INT0 with the rising/falling edge
	else {MCUCR |= (1<<ISC10);	}								// Trigger INT0 with the both edges
	SREG = SREG | (1<<INT_BIT);									// Enable interrupts by setting I-bit
	return ERROR_OK;									
}


