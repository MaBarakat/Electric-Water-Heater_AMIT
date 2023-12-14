/*
 * DIO_priv.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_
/*
*PORTX ---> OUTPUT PORTX adrrees
*DDRX  ---> DIRICTION PORTX adrrees(Enable)
*PINX  ---> INPUT PORTX adrrees
*/

// Register A addresses  
#define PORTA_REG	 ((volatile uint8 *)0X3B)
#define DDRA_REG     ((volatile uint8 *)0X3A)
#define PINA_REG     ((volatile uint8 *)0X39)

// Register B addresses  
#define PORTB_REG    ((volatile uint8 *)0x38)
#define DDRB_REG     ((volatile uint8 *)0x37)
#define PINB_REG     ((volatile uint8 *)0x36)

// Register C addresses  
#define PORTC_REG    ((volatile uint8 *)0x35)
#define DDRC_REG     ((volatile uint8 *)0x34)
#define PINC_REG     ((volatile uint8 *)0x33)

// Register D addresses  
#define PORTD_REG    ((volatile uint8 *)0x32)
#define DDRD_REG     ((volatile uint8 *)0x31)
#define PIND_REG     ((volatile uint8 *)0x30)



#endif /* DIO_PRIV_H_ */