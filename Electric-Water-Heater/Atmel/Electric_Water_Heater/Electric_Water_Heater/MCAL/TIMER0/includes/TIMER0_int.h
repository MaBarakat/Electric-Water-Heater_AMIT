/*
 * TIMER0_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

//timer 0 funs
//ISR FUN
void (*TIMER0_OVF_INT)(void);
void (*TIMER0_CTC_INT)(void);


void TIMER0_vid_int(void);//interface & initialization


void TIMER0_vid_Start(void);//start timer 0 
void TIMER0_vid_Stop(void);//Stop timer 0 
void TIMER0_vid_Reset(void);//Reset timer 0 

void TIMER0_vid_Write_OVR_TCNT0(uint8 Copy_Start_Value);//to write the pre_load(new zero)
void TIMER0_vid_Write_COMP_OCR0(uint8 Copy_Start_Value);//comparing value to write the ocr


//INT enable &disable
void TIMER0_vid_OVR_Interrupt_Enable(void);//overflow INT enable
void TIMER0_vid_OVR_Interrupt_Disable(void);//overflow INT disable
void TIMER0_vid_COMP_Interrupt_Enable(void);//comparing INT enable
void TIMER0_vid_COMP_Interrupt_Disable(void);//comparing INT disable




//this funs it is better to calculate with your hand
uint16 prescaller_value();
uint16   TIMER0_OCR_PWM_u8_calc(float32 D);






#endif /* TIMER0_INT_H_ */