/*
 * TIMER_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_

void TIMER_vid_int(void);//interface & initialization


void TIMER_vid_Start(void);//start timer 
void TIMER_vid_Stop(void);//Stop timer 
void TIMER_vid_Reset(void);//Reset timer

void TIMER_vid_Write_COMP_OCR0(uint8 Copy_Start_Value);//comparing value to write the ocr


//INT enable
void TIMER_vid_COMP_Interrupt_Enable(void);//comparing INT enable

void timer_isr_fun(void (*fun)(void));



#endif /* TIMER_INT_H_ */