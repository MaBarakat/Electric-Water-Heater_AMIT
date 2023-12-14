/*
 * SEVEN_7_SEGMENT_general_config.c
 *
 * Author : Mahmoud Barakat
 */ 
#include "SERV_STD.h"
#include "DIO_int.h"
#include "SEVEN_7_SEGMENT_general_config.h"


#if segment_type == se7_seg_type //if one or more seven segment of same type which is the ordinary one which use 8 pins 

//in different ports or in same
/*
i put in dio_int pins_of_port_X = the number of its pins
EX: #define pins_of_port_A 0,1,2,3,4,5,6,7 and so on
*/

uint8 SE7_seg_port[(seven_7_seg_Num*7)]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};	//the number of pins equal 8 times the number of 7_segments
	/************************************************************************************************************************************************/

#elif segment_type == BCD_seg_type//if one or more seven segment of same type which BCD one which use 4 pins

//in different ports or in same
uint8 BCD_seg_pins[(seven_7_seg_Num*4)]={4,5,6,7,12,13,14,15};	//the number of pins equal 8 times the number of 7_segments
	
	/************************************************************************************************************************************************/
	
#elif segment_type == gen_seg_type //if more than one  seven segments of different type (EX:one use 8 pins  and other use 4 pins)

uint8 SE7_seg_port[(seven_8p_seg_Num*8)]={pins_of_port_C,pins_of_port_D};	//the number of pins equal 8 times the number of 7_segments
											/**********************************/
uint8 BCD_seg_pins[(seven_4p_seg_Num*4)]={2,3,4,5,6,7,12,13};	//the number of pins equal 4 times the number of 7_segments

#endif

	