/*
 * SERV_BITMATH.h
 *
 * Author : Mahmoud Barakat
 */ 

//pin &port in lowercase letter 
#ifndef SERV_BITMATH_H_
#define SERV_BITMATH_H_

//change in one PIN
#define SET_pin(Reg,PIN_NO) Reg |= (1<<PIN_NO)
#define CLEAR_pin(Reg,PIN_NO) Reg &= ~(1<<PIN_NO)
#define TOGGLE_pin(Reg,PIN_NO) Reg ^= (1<<PIN_NO)
#define GET_pin(Reg,PIN_NO) ((Reg >>PIN_NO) & 0x01)

//change in the total port
#define SET_port(Reg) Reg = 0xFF
#define CLEAR_port(Reg) Reg = 0x00
#define TOGGLE_port(Reg) Reg ^= (0xff)

//masking

#endif /* SERV_BITMATH_H_ */