/*
 * TIMER0_prog.c
 *
 * Author : Mahmoud Barakat
 */ 

#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "TIMER0_priv.h"
#include "TIMER0_config.h"
#include "TIMER0_int.h"


//ISR FUN

#define ISR(vector)  															\
void vector(void)	__attribute__((signal,used,externally_visible));		\
void vector(void)

//timer 0 funs
//ISR timer 0 FUN

ISR(__vector_11){
	TIMER0_OVF_INT();
}

ISR(__vector_10){
	TIMER0_CTC_INT();
}


void TIMER0_vid_int(void)//interface & initialization
{ TCCR0=0x00;
	#if TIMER_MODE_WAVE == NORMAL_MODE
	CLEAR_pin(TCCR0,WGM00);
	CLEAR_pin(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;

	#elif TIMER_MODE_WAVE == PWM_MODE
	SET_pin(TCCR0,WGM00);
	CLEAR_pin(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
	
	#elif TIMER_MODE_WAVE == CTC_MODE
	CLEAR_pin(TCCR0,WGM00);
	SET_pin(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
	
	#elif TIMER_MODE_WAVE == FAST_PWM_MODE
	SET_pin(TCCR0,WGM00);
	SET_pin(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
	
	#else
	#warning "Invalid Value ........"
	
	#endif
}

void TIMER0_vid_Start(void)//start timer 0 
{	
	TCCR0 &= TIMER0_CLOCK_STOP;
	TCCR0 |= TIMER_SELECT_ENABLE;
	
}

void TIMER0_vid_Stop(void)//stop timer 0 
{
	TCCR0 &= TIMER0_CLOCK_STOP;
}
void TIMER0_vid_Reset(void)//reset timer 0 
{
	TCNT0 = 0x00;
}


void TIMER0_vid_Write_OVR_TCNT0(uint8 Copy_Start_Value)//pre_load
{
		TCNT0 = Copy_Start_Value;
}
void TIMER0_vid_Write_COMP_OCR0(uint8 Copy_Start_Value)//OCR
{
		OCR0 = Copy_Start_Value;
}

//INT enable &disable
void TIMER0_vid_OVR_Interrupt_Enable(void)//overflow INT enable
{
	SET_pin(SREG,GIE);
	SET_pin(TIMSK,TOIE0);
}


void TIMER0_vid_OVR_Interrupt_Disable(void)//overflow INT disable
{
	CLEAR_pin(TIMSK,TOIE0);
}

void TIMER0_vid_COMP_Interrupt_Enable(void)//comparing INT enable
{
	SET_pin(SREG,GIE);
	SET_pin(TIMSK,OCIE0);
}

void TIMER0_vid_COMP_Interrupt_Disable(void)//comparing INT disable
{
	CLEAR_pin(TIMSK,OCIE0);
}



/************************************************************************/
/*                  funs i optimize it to use in HAL                    */
/************************************************************************/
//funs used in app
//funs by laws of timer 
		//over flow mode
 uint16 prescaller[5]={1,8,64,256,1024};
	 uint16 prescaller_value()
	 {
		 return prescaller[TIMER_SELECT_ENABLE-1];
	 }
	uint16   TIMER0_OCR_PWM_u8_calc(float32 D)//to get OCR value
	{uint16  u8OCR_value; uint8 TOP=255;
		
	 	#if TIMER_MODE_WAVE == PWM_MODE//phase correct
		 D=D/256;
	 		#if TIMER_COMP_OUTPUT_MODE == CLEAR_PWM_MODE//Non-Inverted.
	 		u8OCR_value=D*TOP;
			#elif TIMER_COMP_OUTPUT_MODE == SET_PWM_MODE//Inverted.
			u8OCR_value=TOP*(1-D);
			#endif
		 
	 	#elif TIMER_MODE_WAVE == FAST_PWM_MODE
		 D=D/256;
			#if TIMER_COMP_OUTPUT_MODE == CLEAR_PWM_MODE//Non-Inverted.
			u8OCR_value=(D*(TOP+1))-1;
			#elif TIMER_COMP_OUTPUT_MODE == SET_PWM_MODE//Inverted.
			u8OCR_value=TOP-(D*(TOP+1));
			#endif
			
	 	#elif TIMER_MODE_WAVE == CTC_MODE
		 u8OCR_value=D;		 
	 	#endif
		 return u8OCR_value;
	}



