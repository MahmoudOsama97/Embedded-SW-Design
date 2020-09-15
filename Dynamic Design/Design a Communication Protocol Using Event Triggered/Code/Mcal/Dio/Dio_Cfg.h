/*
 * Dio_Cfg.h
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */


/*_______________________________________________________________________

Define DIO Registers for ATMEGA32
________________________________________________________________________
*/
#ifndef MCAL_DIO_CONFIG_H_
#define MCAL_DIO_CONFIG_H_

#define NO_OF_PORTS  4                                //define no of ports
#define TOTAL_NO_OF_PINS  32                          //define no of pins in all ports
#define MINIMUM_PIN_NO 0                              //start of pin no
#define MAX_PIN_NO 31                                 //End of pin ni
//___________________________________________________________________________________________________
//____________DDR(DIRECTION)_________________________________________________________________________

#define DIRECTION_PORT0 DDRA              //define direction of first port
#define DIRECTION_PORT1 DDRB              //define direction of second port
#define DIRECTION_PORT2 DDRC              //define direction of third port
#define DIRECTION_PORT3 DDRD              //define direction of fourth port

//____________________________________________________________________________________________________

//____________________________________________________________________________________________________
//____________Value of Port___________________________________________________________________________

#define VALUE_PORT0 PORTA
#define VALUE_PORT1 PORTB
#define VALUE_PORT2 PORTC
#define VALUE_PORT3 PORTD
//____________________________________________________________________________________________________

//___________________________________________________________________________________________________
//__________Read Value from Port______________________________________________________________________
#define READ_PORT0 PINA                 //Read Value from Port A
#define READ_PORT1 PINB                 //Read Value from Port B
#define READ_PORT2 PINC                 //Read Value from Port C
#define READ_PORT3 PIND                 //Read Value from Port D
//_____________________________________________________________________________________________________


//____________________________________________________________________________________________________
//__________PIN No.___________________________________________________________________________________
#define DIO_PIN_NO_0  0
#define DIO_PIN_NO_1  1
#define DIO_PIN_NO_2  2
#define DIO_PIN_NO_3  3
#define DIO_PIN_NO_4  4
#define DIO_PIN_NO_5  5
#define DIO_PIN_NO_6  6
#define DIO_PIN_NO_7  7
#define DIO_PIN_NO_8  8
#define DIO_PIN_NO_9  9
#define DIO_PIN_NO_10 10
#define DIO_PIN_NO_11 11
#define DIO_PIN_NO_12 12
#define DIO_PIN_NO_13 13
#define DIO_PIN_NO_14 14
#define DIO_PIN_NO_15 15
#define DIO_PIN_NO_16 16
#define DIO_PIN_NO_17 17
#define DIO_PIN_NO_18 18
#define DIO_PIN_NO_19 19
#define DIO_PIN_NO_20 20
#define DIO_PIN_NO_21 21
#define DIO_PIN_NO_22 22
#define DIO_PIN_NO_23 23
#define DIO_PIN_NO_24 24
#define DIO_PIN_NO_25 25
#define DIO_PIN_NO_26 26
#define DIO_PIN_NO_27 27
#define DIO_PIN_NO_28 28
#define DIO_PIN_NO_29 29
#define DIO_PIN_NO_30 30
#define DIO_PIN_NO_31 31

//__________PORT No.___________________________________________________________________________________

#define DIO_PORT_NO_0 0
#define DIO_PORT_NO_1 1
#define DIO_PORT_NO_2 2
#define DIO_PORT_NO_3 3
#endif /* DIO_DRIVER_DIO_CFG_H_ */
