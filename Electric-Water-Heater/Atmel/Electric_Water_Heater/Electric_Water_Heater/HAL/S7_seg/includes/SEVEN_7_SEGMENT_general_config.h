/*
 * SEVEN_7_SEGMENT_general_config.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef SEVEN_7_SEGMENT_GENERAL_CONFIG_H_
#define SEVEN_7_SEGMENT_GENERAL_CONFIG_H_

#define se7_seg_type 0 //if one or more seven segment of same type which is the ordinary one which use 8 pins 
#define BCD_seg_type 1 //if one or more seven segment of same type which BCD one which use 4 pins
#define gen_seg_type 2 //if more than one  seven segments of different type (EX:one use 8 pins  and other use 4 pins)

#define segment_type se7_seg_type//to determine the type of seven segment

#if segment_type == gen_seg_type  //if more than one  seven segments of different type
#define seven_8p_seg_Num  2 //the number of seven_segment
#define seven_4p_seg_Num  2 //the number of BCD_segment

#else
// for more than one with file.c
#define seven_7_seg_Num 2//the number of seven_segment of one type

#endif




#endif /* SEVEN_7_SEGMENT_GENERAL_CONFIG_H_ */