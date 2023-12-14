/*
 * LED_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef LED_INT_H_
#define LED_INT_H_

enum {LOW_LED,HIGH_LED,TOGGLE_LED};	
// i the number of the led
void LED_vid_INT(uint8 LED_order); //function to link with the MC pins and initialize it
void LED_vid_write(uint8 u8LED_stat,uint8 LED_order);//function to on or off the led



#endif /* LED_INT_H_ */