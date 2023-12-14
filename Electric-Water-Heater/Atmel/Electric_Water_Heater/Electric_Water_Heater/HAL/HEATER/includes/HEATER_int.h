/*
 * HEATER_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef HEATER_INT_H_
#define HEATER_INT_H_


enum {Heater_OFF,Heater_ON};

void HEATER_vid_INT(); 
void HEATER_vid_write(uint8 u8HEATER_stat);


#endif /* HEATER_INT_H_ */