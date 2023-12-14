/*
 * SW_config.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_
/*
//first way 
#define SW_PORT DIO_PORT_D
#define SW_pin PIN_2
*/
/*
//second way 
#define SW_pin 12
*/
// for more than SW with file .c
//the number of the switches
#define SW_N  3
/*
//way more than SW without file .c
#define SW_pin[1] 4 //the led number 1--->pin number
#define SW_pin[2] 23 //the SW number 2--->pin number
*/


#endif /* SW_CONFIG_H_ */