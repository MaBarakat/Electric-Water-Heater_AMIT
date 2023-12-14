/*
 * SW_prog.c
 *
 * Author : Mahmoud Barakat
 */ 
#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "DIO_int.h"
#include "SW_config.h"
#include "SW_int.h"

extern uint8 SW_pin[SW_N];
uint8 error=0;//i the number of the SW
void SW_vid_INT(uint8 i){
	if (i<=SW_N)
	{
	i--;//cause SW_1 ---> 0
	DIO_vid_SET_PIN_DIR(SW_pin[i],INPUT_PIN);
	DIO_VID_SET_PIN_VALUE(SW_pin[i],HIGH_PIN);//internal pull up
	}else{error=3;};
}
	
uint8 SW_u8_reed(uint8 i){
		if (i<=SW_N)
		{
	i--;//cause SW_1 ---> 0
	return DIO_U8_GET_PIN_VALUE(SW_pin[i]);
		}else{error=3;};
	}//function to get value of pin (0,1) depending on switch