#ifndef INTERRUPT_H_
#define INTERRUPT_H_
//TODO include & delete typedef

#include "../../Infrastructure/AVR_Reg.h"
#include "../../Infrastructure/Common_Macros.h"
#include "../../Infrastructure/Std_Types.h"
#include "avr/interrupt.h"

#define RISING 1
#define FALLING 0
#define BOTH 2

#define PD2      2
#define PD3      3
#define INT0     6
#define INT1     7
#define ISC00    0
#define ISC01    1
#define ISC10    2
#define ISC11    3
#define INT_BIT  7

#define ERROR_OK     0
#define ERROR_NOK    1

extern uint8_t interrupt0_init(uint8_t type, void (*callBack)(void));
extern uint8_t interrupt1_init(uint8_t type, void (*callBack)(void));



#endif /* INTERRUPT_H_ */
