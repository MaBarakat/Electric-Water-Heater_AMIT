/*
 * SEVEN_7_SEGMENT_general_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef SEVEN_7_SEGMENT_GENERAL_INT_H_
#define SEVEN_7_SEGMENT_GENERAL_INT_H_

// 8 pins
//i the number of 7_segment
void SE7_seg_vid_int(uint8 i);//to determine the direction and initial value of the port or pins of  7_seg
void SE7_seg_vid_write(uint8 u8seg_NUM,uint8 i);//to write the number on  7_seg

// 4 pins
//i the number of BCD_segment
void BCD_seg_vid_int(uint8 i);//to determine the direction and initial value of the port or pins of  7_seg
void BCD_seg_vid_write(uint8 u8seg_NUM,uint8 i);//to write the number on  7_seg

// different types
enum {seven_8p_segmnt_type,bcd_4p_segmnt_type}; //u8seg_type =0 for 7_seg and =1 for bcd_seg
void gen_seg_vid_int(uint8 u8seg_type,uint8 i);//to determine the direction and initial value of the port or pins of  7_seg
void gen_seg_vid_write(uint8 u8seg_type,uint8 u8seg_NUM,uint8 i);//to write the number on  7_seg

#endif /* SEVEN_7_SEGMENT_GENERAL_INT_H_ */