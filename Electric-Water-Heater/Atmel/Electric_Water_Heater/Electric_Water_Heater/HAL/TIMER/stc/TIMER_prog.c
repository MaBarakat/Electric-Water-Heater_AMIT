/*
 * TIMER_prog.c
 *
 * Author : Mahmoud Barakat
 */ 
#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "TIMER0_int.h"
#include "TIMER_int.h"

void TIMER_vid_int(void)//interface & initialization
{
	TIMER0_vid_int();
}

void TIMER_vid_Start(void)//start timer
{
	TIMER0_vid_Start();
}
void TIMER_vid_Stop(void)//Stop timer
{
	TIMER0_vid_Stop();
}
void TIMER_vid_Reset(void)//Reset timer
{
	TIMER0_vid_Reset();
}

void TIMER_vid_Write_COMP_OCR0(uint8 Copy_Start_Value)//comparing value to write the ocr
{
	TIMER0_vid_Write_COMP_OCR0(Copy_Start_Value);
}

//INT enable
void TIMER_vid_COMP_Interrupt_Enable(void)//comparing INT enable
{
	TIMER0_vid_COMP_Interrupt_Enable();
}

void timer_isr_fun(void (*fun)(void))
{
	TIMER0_CTC_INT=fun;
}