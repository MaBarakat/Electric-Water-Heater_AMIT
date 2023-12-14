/*
 * COLLER_prog.c
 *
 * Author : Mahmoud Barakat
 */ 
#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "DIO_int.h"
#include "COLLER_config.h"
#include "COLLER_int.h"

void COLLER_vid_INT()
{
	DIO_vid_SET_PIN_DIR(COLLER_pin,OUTPUT_PIN);
	DIO_VID_SET_PIN_VALUE(COLLER_pin,COLLER_OFF);
}
void COLLER_vid_write(uint8 u8COLLER_stat)
{
	DIO_VID_SET_PIN_VALUE(COLLER_pin,u8COLLER_stat);
}