/*
 * EXT_ADC_prog.c
 *
 * Author : Mahmoud Barakat
 */ 

#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "ADC_int.h"
#include "EXT_ADC_int.h"

void EXT_ADC_vid_int()
{	 ADC_vid_int();
	 ADC_vid_Enable();
}
uint16 EXT_ADC_u16ReadDigitalVal(CHANNEL ChannelCopy)
{
	return ADC_u16ReadDigitalVal(ChannelCopy);
}
