/*
 * SEVEN_7_SEGMENT_general_prog.c
 *
 * Author : Mahmoud Barakat
 */ 

#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "DIO_int.h"
#include "SEVEN_7_SEGMENT_general_config.h"
#include "SEVEN_7_SEGMENT_general_int.h"

uint8 error;//i the number of 7_segments
	
#if segment_type == se7_seg_type
 //if one or more seven segment of same type which is the ordinary one which use 8 pins 

//in different ports
extern uint8 SE7_seg_port[(seven_7_seg_Num*7)];
uint8 u8se7_seg_NUMs_x[11] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00};//the 7_segment numbers in hex shape
// 8 pins
//i the number of 7_segment
void SE7_seg_vid_int(uint8 i){
		uint8 j;//counter to pins
		if (i<=seven_7_seg_Num)
		{i--;
			for (j=(i*7);j<=(7+i*7);j++)
			{
				DIO_vid_SET_PIN_DIR(SE7_seg_port[j],OUTPUT_PIN);
				DIO_VID_SET_PIN_VALUE(SE7_seg_port[j],LOW_PIN);
			}
			}else{error=3;}
	
	}//to determine the direction and initial value of the port or pins of  7_seg
void SE7_seg_vid_write(uint8 u8seg_NUM,uint8 i){
	uint8 j,k;//j counter for pins of port
	//k to make shifting
	if (i<=seven_7_seg_Num){
		i--;
		for (j=(i*7),k=0;j<=(7+i*7),k<=6;j++,k++)
		{
			DIO_VID_SET_PIN_VALUE(SE7_seg_port[j],GET_pin(u8se7_seg_NUMs_x[u8seg_NUM],k));
		}}else{error=3;}
	
	//to write the number on  7_seg
	}


/********************************************************************************************************************************************/
#elif segment_type == BCD_seg_type //if one or more seven segment of same type which BCD one which use 4 pins
//in different ports
extern uint8 BCD_seg_pins[seven_7_seg_Num*4];
uint8 u8BCD_seg_NUMs_x[10] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};//the 7_segment numbers in hex shape// 4 pins

//i the number of BCD_segment
void BCD_seg_vid_int(uint8 i){
		uint8 j;//counter to pins
		if (i<=seven_7_seg_Num)
		{i--;
			for (j=(i*4);j<=(3+i*4);j++)
			{
				DIO_vid_SET_PIN_DIR(BCD_seg_pins[j],OUTPUT_PIN);
				DIO_VID_SET_PIN_VALUE(BCD_seg_pins[j],LOW_PIN);
			}
			}else{error=3;} 
				}//to determine the direction and initial value of the port or pins of  7_seg
void BCD_seg_vid_write(uint8 u8seg_NUM,uint8 i){
	uint8 j,k;//j counter for pins of port
	//k to make shifting
	if (i<=seven_7_seg_Num)
	{i--;
		for (j=(i*4),k=0;j<=(3+i*4),k<=3;j++,k++)
		{
			DIO_VID_SET_PIN_VALUE(BCD_seg_pins[j],GET_pin(u8BCD_seg_NUMs_x[u8seg_NUM],k));
		}
		}else{error=3;}
		}//to write the number on  7_seg


/********************************************************************************************************************************************/
#elif segment_type == gen_seg_type //if more than one  seven segments of different type (EX:one use 8 pins  and other use 4 pins)

extern uint8 SE7_seg_port[(seven_8p_seg_Num*8)];
extern uint8 BCD_seg_pins[seven_4p_seg_Num*4];

uint8 u8se7_seg_NUMs_x[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//the 7_segment numbers in hex shape
uint8 u8BCD_seg_NUMs_x[10] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};//the 7_segment numbers in hex shape
	
// different types
void gen_seg_vid_int(uint8 u8seg_type,uint8 i){
	if (u8seg_type ==seven_8p_segmnt_type)
	{
			uint8 j;//counter to pins
			if (i<=seven_8p_seg_Num)
			{i--;
				for (j=(i*8);j<=(7+i*8);j++)
				{
					DIO_vid_SET_PIN_DIR(SE7_seg_port[j],OUTPUT_PIN);
					DIO_VID_SET_PIN_VALUE(SE7_seg_port[j],LOW_PIN);
				}
				}else{error=3;}
	}else if (u8seg_type ==bcd_4p_segmnt_type)
	{
		uint8 j;//counter to pins
		if (i<=seven_4p_seg_Num)
		{i--;
			for (j=(i*4);j<=(3+i*4);j++)
			{
				DIO_vid_SET_PIN_DIR(BCD_seg_pins[j],OUTPUT_PIN);
				DIO_VID_SET_PIN_VALUE(BCD_seg_pins[j],LOW_PIN);
			}
			}else{error=3;}
	}
	
	}//to determine the direction and initial value of the port or pins of  7_seg
void gen_seg_vid_write(uint8 u8seg_type,uint8 u8seg_NUM,uint8 i){
	if (u8seg_type ==seven_8p_segmnt_type)
	{
			uint8 j,k;//j counter for pins of port
			//k to make shifting
			if (i<=seven_8p_seg_Num)
			{i--;
				for (j=(i*8),k=0;j<=(7+i*8),k<=7;j++,k++)
				{
					DIO_VID_SET_PIN_VALUE(SE7_seg_port[j],GET_pin(u8se7_seg_NUMs_x[u8seg_NUM],k));
				}
				}else{error=3;}
				
	}else if (u8seg_type ==bcd_4p_segmnt_type)
	{
			uint8 j,k;//j counter for pins of port
			//k to make shifting
			if (i<=seven_4p_seg_Num)
			{i--;
				for (j=(i*4),k=0;j<=(3+i*4),k<=3;j++,k++)
				{
					DIO_VID_SET_PIN_VALUE(BCD_seg_pins[j],GET_pin(u8BCD_seg_NUMs_x[u8seg_NUM],k));
				}
				}else{error=3;}
	}
	
	}//to write the number on  7_seg

#endif
