/*
 * LED_prog.c
 *
 * Author : Mahmoud Barakat
 */ 
#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"
 extern uint8 LED_pin[LED_NUM];
	
 uint8 error;//i the number of the led
void LED_vid_INT(uint8 LED_order){
	if (LED_order<=LED_NUM)
		{
		LED_order--;//cause led_1 ---> 0
	DIO_vid_SET_PIN_DIR(LED_pin[LED_order],OUTPUT_PIN);
	DIO_VID_SET_PIN_VALUE(LED_pin[LED_order],LOW_PIN);//initialization value
		}else{error=3;};
			} //function to link with the MC pins and initialize it
void LED_vid_write(uint8 u8LED_stat,uint8 LED_order){
		if (LED_order<=LED_NUM)
		{
		LED_order--;//cause led_1 ---> 0
	DIO_VID_SET_PIN_VALUE(LED_pin[LED_order],u8LED_stat);
		}else{error=3;};	
	}//function to on ,off or toggle the led