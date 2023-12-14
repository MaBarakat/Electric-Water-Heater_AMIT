/*
 * TIMER0_config.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/******Timer Waveform Generation Mode******/
/*
 * -NORMAL_MODE   -PWM_MODE (Phase Correct)   -CTC_MODE    -FAST_PWM_MODE
 * */

/***** TIMER MODE *****/
#define NORMAL_MODE    0
#define PWM_MODE       1
#define CTC_MODE       2
#define FAST_PWM_MODE  3

#define TIMER_MODE_WAVE   CTC_MODE

#define TIMER0_CLOCK_STOP (uint8)0xF8//pre_scaller = 000

/***** Clock Select ENABLE TIMER*****/


/*---TIMER SELSET FACTOR---*/
#define TIMER_FACTOR_NO                    (uint8)0x00          //timer STOPED No_Clock_Source (pre_scaller = 000)
#define TIMER_FACTOR_1                     (uint8)0x01      	//no pre_scaller(pre_scaller =1)
#define TIMER_FACTOR_8                     (uint8)0x02      	//8 pre_scaller
#define TIMER_FACTOR_64                    (uint8)0x03      	//64 pre_scaller
#define TIMER_FACTOR_256                   (uint8)0x04      	//256 pre_scaller
#define TIMER_FACTOR_1024                  (uint8)0x05      	//1024 pre_scaller
#define TIMER_FACTOR_EXT_FALLING_PIN_T0    (uint8)0x06		    //(EVENT)using Counter with S.W or wave(external clock falling edge)
#define TIMER_FACTOR_EXT_RISING_PIN_T0     (uint8)0x07          //(EVENT)using Counter with S.W or wave(external clock raising edge)

#define TIMER_SELECT_ENABLE    TIMER_FACTOR_256

/*---Compare Output Mode USED In (NORMAL-Compare)non_PWM Mode com00,com01---
//it is not used because the high frequency of OC0 not be visible*/
#define NORMAL_port_non_PWM  0x00//Normal port operation, OC0 disconnected.
#define TOGGLE_non_PWM_MODE  0x10 //Toggle OC0
#define CLEAR_non_PWM_MODE   0x20 //Clear OC0
#define SET_non_PWM_MODE	 0x30 //Set OC0


/*---Compare Output Mode USED In (Fast-Phase) PWM Mode com00,com01---*/
#define NORMAL_port_PWM  0x00//Normal port operation, OC0 disconnected.
#define CLEAR_PWM_MODE   0x20//Fast --> Non-Inverted. //Phase --> Clear OC0 (up) then Set OC0 (down)
#define SET_PWM_MODE	 0x30//Fast --> Inverted.	  //Phase --> Set OC0 (up) then Clear OC0 (down)

#define TIMER_COMP_OUTPUT_MODE   NORMAL_port_non_PWM



// TCCR0 
typedef enum {
	/*--- use TIMER SELSET FACTOR---*/
// 	CS00     ,
// 	CS01     ,
// 	CS02     ,
	WGM01=3  ,
	COM00    ,
	COM01    ,
	WGM00    ,
	FOC0
}TCCR0_BIT_Reg;
//TIMSK Reg
#define TOIE0    (uint8)0
#define OCIE0    (uint8)1
//TIFR Reg
#define TOV0    (uint8)0
#define OCF0    (uint8)1
//SREG
#define GIE   7
//SFIOR
#define PSR10   (uint8)0



#endif /* TIMER0_CONFIG_H_ */