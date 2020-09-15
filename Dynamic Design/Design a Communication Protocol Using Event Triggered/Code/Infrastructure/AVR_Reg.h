/*
 * AVR_Reg.h
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#ifndef DIO_DRIVER_AVR_REG_H_
#define DIO_DRIVER_AVR_REG_H_

#define PORTA *((volatile uint8_t*) 0x3B)
#define PORTB *((volatile uint8_t*) 0x38)
#define PORTC *((volatile uint8_t*) 0x35)
#define PORTD *((volatile uint8_t*) 0x32)

#define PINA *((volatile uint8_t*) 0x39)
#define PINB *((volatile uint8_t*) 0x36)
#define PINC *((volatile uint8_t*) 0x33)
#define PIND *((volatile uint8_t*) 0x30)

#define DDRA *((volatile uint8_t*) 0x3A)
#define DDRB *((volatile uint8_t*) 0x37)
#define DDRC *((volatile uint8_t*) 0x34)
#define DDRD *((volatile uint8_t*) 0x31)

#define SREG *((volatile uint8_t*) 0x5F)

#define TIMER0_TCCR0 *((volatile uint8_t *)0x53)
#define TIMER0_TCNT0 *((volatile uint8_t *)0x52)
#define TIMER0_TIMSK *((volatile uint8_t *)0x59)
#define TIMER0_TIFR  *((volatile uint8_t *)0x58)
#define TIMER0_OCR0  *((volatile uint8_t *)0x5C)

#define UART_UDR     *((volatile uint8_t*) 0x2C)
#define UART_UCSRA   *((volatile uint8_t*) 0x2B)
#define UART_UCSRB   *((volatile uint8_t*) 0x2A)
#define UART_UBRRL   *((volatile uint8_t*) 0x29)
#define UART_UCSRC   *((volatile uint8_t*) 0x40)
#define UART_UBRRH   *((volatile uint8_t*) 0x40)

#define UART_UBRRH   *((volatile uint8_t*) 0x40)

#define NULL (volatile void*) 0
#endif /* DIO_DRIVER_AVR_REG_H_ */

