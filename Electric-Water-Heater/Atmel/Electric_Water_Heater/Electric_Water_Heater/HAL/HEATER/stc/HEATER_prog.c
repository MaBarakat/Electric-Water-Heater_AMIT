/*
 * HEATER_prog.c
 *
 * Author : Mahmoud Barakat
 */ 

#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "DIO_int.h"
#include "HEATER_config.h"
#include "HEATER_int.h"

void HEATER_vid_INT()
{
	DIO_vid_SET_PIN_DIR(heater_pin,OUTPUT_PIN);
	DIO_VID_SET_PIN_VALUE(heater_pin,Heater_OFF);
}
void HEATER_vid_write(uint8 u8HEATER_stat)
{
	DIO_VID_SET_PIN_VALUE(heater_pin,u8HEATER_stat);
}
