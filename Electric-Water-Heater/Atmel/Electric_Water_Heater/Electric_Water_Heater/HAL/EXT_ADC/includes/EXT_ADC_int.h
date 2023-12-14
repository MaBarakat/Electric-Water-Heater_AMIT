/*
 * EXT_ADC_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef EXT_ADC_INT_H_
#define EXT_ADC_INT_H_

typedef enum{
	//single ended channels
	CHANNEL0,
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7
}CHANNEL;
void EXT_ADC_vid_int();
uint16 EXT_ADC_u16ReadDigitalVal(CHANNEL ChannelCopy);



#endif /* EXT_ADC_INT_H_ */