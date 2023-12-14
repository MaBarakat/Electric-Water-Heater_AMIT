/*
 * TIMER0_priv.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_


#define TCCR0   *((volatile uint8 *)0x53)// use to determine the Waveform Generation Mode,Compare Match Output Mode,pre_scaler &clock source 
#define TCNT0   *((volatile uint8 *)0x52)// the counter register
#define OCR0    *((volatile uint8 *)0x5C)// use in CTC,PWM modes comparing value
#define TIMSK   *((volatile uint8 *)0x59)// use to INT Enable PIE
#define TIFR    *((volatile uint8 *)0x58)// use to read INT flag 
#define SREG    *((volatile uint8 *)0x5F)// use to GIE enable 
#define SFIOR   *((volatile uint8 *)0x50)// use to determine the pre_scaler Reset (doesn't use)


#endif /* TIMER0_PRIV_H_ */