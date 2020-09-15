/*
 * dio.c
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#include "Dio.h"


/*______________________________________________________________________________________________*/
/*Description: Set PORT Direction (INPUT or OUTPUT)
 * Input     : Copy_u8PortNB (PORT Number) ,  Copy_u8Dir (PORT Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PORT(uint8_t Copy_u8PortNB,uint8_t Copy_u8Dir)
{
	
	if(Copy_u8PortNB==DIO_PORT_NO_3){ 
		DIRECTION_PORT3=Copy_u8Dir;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_2){ 
		DIRECTION_PORT2=Copy_u8Dir;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_1){ 
		DIRECTION_PORT1=Copy_u8Dir;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_0){ 
		DIRECTION_PORT0=Copy_u8Dir;
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/

/*Description: Set PIN Direction (INPUT or OUTPUT)
 * Input     :Copy_u8PinNB (PIN Number) ,  Copy_u8Dir (PIN Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PIN(uint8_t Copy_u8PinN,uint8_t Copy_u8Dir)
{
	uint8_t pin=Copy_u8PinN%8;
	uint8_t port=Copy_u8PinN/8;
	
	if(!((Copy_u8Dir==DIO_OUTPUT)||(Copy_u8Dir==DIO_INPUT))) return ERROR;
	
	if(port==DIO_PORT_NO_3){ 
		
		if(Copy_u8Dir==DIO_OUTPUT){
			SET_BIT(DIRECTION_PORT3,pin);
		} 
		else{
			
			CLEAR_BIT(DIRECTION_PORT3,pin);
		}
		
	}
	else if(port==DIO_PORT_NO_2){ 
		
		if(Copy_u8Dir==DIO_OUTPUT){
			
			SET_BIT(DIRECTION_PORT2,pin);
		} 
		else{
			
			CLEAR_BIT(DIRECTION_PORT2,pin);
		}
	}
	else if(port==DIO_PORT_NO_1){ 
		
		if(Copy_u8Dir==DIO_OUTPUT){
			
			SET_BIT(DIRECTION_PORT1,pin);
		} 
		else{
			
			CLEAR_BIT(DIRECTION_PORT1,pin);
		}
	}
	else if(port==DIO_PORT_NO_0){ 
		
		if(Copy_u8Dir==DIO_OUTPUT){
			
			SET_BIT(DIRECTION_PORT0,pin);
		} 
		else{
			
			CLEAR_BIT(DIRECTION_PORT0,pin);
		}
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/

/*Description: Set PORT Value (from 0 to 255)
 * Input     : Copy_u8PortNB (PORT Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortNB,uint8_t Copy_u8Value)
{
	if(Copy_u8PortNB==DIO_PORT_NO_3){ 
		VALUE_PORT3=Copy_u8Value;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_2){ 
		VALUE_PORT2=Copy_u8Value;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_1){ 
		VALUE_PORT1=Copy_u8Value;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_0){ 
		VALUE_PORT0=Copy_u8Value;
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Set PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinNB (PIN Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinN,uint8_t Copy_u8Value)
{
	uint8_t pin=Copy_u8PinN%8;
	uint8_t port=Copy_u8PinN/8;
	if(!((Copy_u8Value==DIO_HIGH)||(Copy_u8Value==DIO_LOW))) return ERROR;
	if(port==DIO_PORT_NO_3){ 
		if(Copy_u8Value==DIO_HIGH){
			SET_BIT(VALUE_PORT3,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT3,pin);
		}
		
	}
	else if(port==DIO_PORT_NO_2){ 
		if(Copy_u8Value==DIO_HIGH){
			SET_BIT(VALUE_PORT2,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT2,pin);
		}
	}
	else if(port==DIO_PORT_NO_1){ 
		if(Copy_u8Value==DIO_HIGH){
			SET_BIT(VALUE_PORT1,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT1,pin);
		}
	}
	else if(port==DIO_PORT_NO_0){ 
		if(Copy_u8Value==DIO_HIGH){
			SET_BIT(VALUE_PORT0,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT0,pin);
		}
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Get PORT Value
 * Input     :  Copy_u8PortNB (PORT Number),*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPortValue(uint8_t Copy_u8PortNB,uint8_t *Copy_u8Value)
{
	if(Copy_u8Value==NULL) return ERROR;
	
		if(Copy_u8PortNB==DIO_PORT_NO_3){ 
		*Copy_u8Value=READ_PORT3;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_2){ 
		*Copy_u8Value=READ_PORT2;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_1){ 
		*Copy_u8Value=READ_PORT1;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_0){ 
		*Copy_u8Value=READ_PORT0;
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Get PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinN (PIN Number) ,*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPinValue(uint8_t Copy_u8PinN,uint8_t *Copy_u8Value)
{
	uint8_t pin=Copy_u8PinN%8;
	uint8_t port=Copy_u8PinN/8;
	if(Copy_u8Value==NULL) return ERROR;
	if(port==DIO_PORT_NO_3){ 
		*Copy_u8Value=GET_BIT(READ_PORT3,pin);		
	}
	else if(port==DIO_PORT_NO_2){ 
		*Copy_u8Value=GET_BIT(READ_PORT2,pin);	
	}
	else if(port==DIO_PORT_NO_1){ 
		*Copy_u8Value=GET_BIT(READ_PORT1,pin);	
	}
	else if(port==DIO_PORT_NO_0){ 
		*Copy_u8Value=GET_BIT(READ_PORT0,pin);	
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     :  Copy_u8PortNB (PORT Number),Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortInputType(uint8_t Copy_u8PortNB,uint8_t Copy_u8InputType)
{
	
	if(Copy_u8PortNB==DIO_PORT_NO_3){ 
		if(DIRECTION_PORT3==~Copy_u8InputType) return ERROR;
		VALUE_PORT3=Copy_u8InputType;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_2){ 
		if(DIRECTION_PORT2==~Copy_u8InputType) return ERROR;
		VALUE_PORT2=Copy_u8InputType;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_1){ 
		if(DIRECTION_PORT1==~Copy_u8InputType) return ERROR;
		VALUE_PORT1=Copy_u8InputType;
	}
	else if(Copy_u8PortNB==DIO_PORT_NO_0){ 
		if(DIRECTION_PORT0==~Copy_u8InputType) return ERROR;
		VALUE_PORT0=Copy_u8InputType;
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     : Copy_u8PinN(PIN NO) ,Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinInputType(uint8_t Copy_u8PinN,uint8_t Copy_u8InputType)
{
	uint8_t pin=Copy_u8PinN%8;
	uint8_t port=Copy_u8PinN/8;
	if(!((Copy_u8InputType==DIO_HIGH)||(Copy_u8InputType==DIO_LOW))) return ERROR;
	if(port==DIO_PORT_NO_3){ 
		
		if(Copy_u8InputType==DIO_HIGH){
			if(BIT_IS_CLEAR(DIRECTION_PORT3,pin)) return ERROR;
			SET_BIT(VALUE_PORT3,pin);
			
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT3,pin);
		}
		
	}
	else if(port==DIO_PORT_NO_2){ 
		if(Copy_u8InputType==DIO_HIGH){
			if(BIT_IS_CLEAR(DIRECTION_PORT2,pin)) return ERROR;
			SET_BIT(VALUE_PORT2,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT2,pin);
		}
	}
	else if(port==DIO_PORT_NO_1){ 
		if(Copy_u8InputType==DIO_HIGH){
			if(BIT_IS_CLEAR(DIRECTION_PORT1,pin)) return ERROR;
			SET_BIT(VALUE_PORT1,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT1,pin);
		}
	}
	else if(port==DIO_PORT_NO_0){ 
		if(Copy_u8InputType==DIO_HIGH){
			if(BIT_IS_CLEAR(DIRECTION_PORT0,pin)) return ERROR;
			SET_BIT(VALUE_PORT0,pin);
		} 
		else{
			
			CLEAR_BIT(VALUE_PORT0,pin);
		}
	}
	else{
		return ERROR;
	}
	return NO_ERROR;
}
