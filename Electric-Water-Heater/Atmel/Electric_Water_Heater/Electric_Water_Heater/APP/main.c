/*
 * Electric_Water_Heater.c
 *
 * Author : Mahmoud Barakat
 */ 

#define F_CPU 16000000UL

/* SERVICE */
#include "SERV_STD.h"
#include "SERV_BITMATH.h"


/* HAL */
#include "LED_int.h"
#include "HEATER_int.h"
#include "COLLER_int.h"
#include "SEVEN_7_SEGMENT_general_int.h"
#include "SW_int.h"

#include "TIMER_int.h"
#include "EXT_ADC_int.h"
#include "EEPROM_int.h"

#include <util/delay.h>

#define on_off_led 2
#define Heating_Element_led 1

void timer_isr (void);//function of the timer
//counters and timers used in code
uint8 temp_timer=0,temp_counter=0;
/* temp_timer   :used as a counter to read the temperature every 100 ms */
/* temp_counter :used to determine the order of the temperature is red  */
uint16 seting_mode_counter=0;/* seting_mode_counter :to on the system after 5 sec of no pressing buttons in setting mode*/
uint8 blink_counter=0,blink_toggle=0;
/* blink_counter :used as a counter to blink t or led after 1sec   */
/* blink_toggle :used to toggle the seven segmen1 sec   */
uint8 colling_indicator=0,heating_indicator=0;
/* colling_indicator :indicate to cooler on or off  */
/* heating_indicator :indicate to heater on or off  */
uint8 Req_Temp_achieved_indicator=0;
uint16 Req_Temp_achieved_counter=0;
//modes (setting,on_off)
uint8 seting_mode=0 ,on_off_count=0;
/* seting_mode :indicate to seting_mode on or off  */
/* on_off_count :indicate to system on or off  */

int main(void)
{
	//initialization
	EXT_ADC_vid_int();//ADC_interface
	TIMER_vid_int();//timer_interface
	EEPROM_voidInit();//TWI_interface to work with EEPROM
	
		/* LED_count :indicate to number of leds in system  */
		/* SW_count :indicate to number of buttons in system   */
		/* S7_seg_count :indicate to number of seven segments in system  */
		/* int_count :the counter used to initialize leds,buttons and seven segments  */
	uint8 LED_count=2,SW_count=3,S7_seg_count=2,int_count=0;
	for (int_count=1;int_count<=LED_count;int_count++)
	{LED_vid_INT(int_count);//leds_interface
	}
	HEATER_vid_INT();//Heating Element_interface
	COLLER_vid_INT();//Cooling Element_interface
	for (int_count=1;int_count<=SW_count;int_count++)
	{SW_vid_INT(int_count);//buttons_interface
	}
	
	for (int_count=1;int_count<=S7_seg_count;int_count++)
	{SE7_seg_vid_int(int_count);//seven segments_interface
	}
	
	//coding
		//timer prepare					
		TIMER_vid_COMP_Interrupt_Enable();
		TIMER_vid_Write_COMP_OCR0(249);//the timer cycle take 4ms
		timer_isr_fun(timer_isr);
	
	//variables for tasks
	uint8 Tens_count=6,ones_count=0;
/* Tens_count :the left (Tens) seven segment  */
/* ones_count :the right (ones) seven segment  */

	// water_temp it is the temperature from sensor
	sint32 water_temp_arr[10];//the ten readings
	sint32 water_temp=0;//the average read
	
	//The initial set temperature is 60 degrees.
	uint8 temp=60;// temp it is the required temperature
	EEPROM_SendData(0X00,temp);
	SE7_seg_vid_write(Tens_count,1);
	SE7_seg_vid_write(ones_count,2);
	
    while (1) 
    {
		//the electric water heater is off
		if (on_off_count == 0)
		{LED_vid_write(LOW_LED,on_off_led);	//system off
		water_temp=(float32)((float32)((float32)EXT_ADC_u16ReadDigitalVal(CHANNEL0)*2.5)/10);//first reading degree
		LED_vid_write(LOW_LED,Heating_Element_led);
				COLLER_vid_write(COLLER_OFF);
				HEATER_vid_write(Heater_OFF);
				heating_indicator=0;
				colling_indicator=0;
				Req_Temp_achieved_indicator=0;
		//setting mode 
			//button 1 the increasing button
			if (SW_u8_reed(1)==0 )
			{if (seting_mode==0)//setting mode off
				{seting_mode=1;//setting mode on //the first press
					TIMER_vid_Start();
					while(SW_u8_reed(1)==0);//waiting until release the button
				}else	//setting mode on //not the first press
				{	//put the temp you want by increasing
					//increasing button by 5 degrees
					
					if (ones_count == 0)
					{ones_count=5;
					temp=(Tens_count*10)+ones_count;
					EEPROM_SendData(0X00,temp);//save in EEPROM
					while(SW_u8_reed(1)==0);
					EEPROM_ReadData(0x00,&temp);
					}else if (ones_count == 5 && Tens_count !=7)
					{ones_count=0;
					Tens_count++;
					temp=Tens_count*10;
					EEPROM_SendData(0X00,temp);
					while(SW_u8_reed(1)==0);
					EEPROM_ReadData(0x00,&temp);
					}
				}
				//write on seven segment
				Tens_count=temp/10;
				ones_count=temp%10;
				seting_mode_counter=0;//count 5 sec after last press
				}
				
		//button 2 the decreasing button
				else if (SW_u8_reed(2)==0 )
				{if (seting_mode==0)//setting mode off 
					{seting_mode=1;//setting mode on //the first press
					TIMER_vid_Start();
					while(SW_u8_reed(2)==0);//waiting until release the button
					}
					else//setting mode on //not the first press
					{	//put the temp you want by decreasing
						//decreasing button by 5 degrees
						
						if (ones_count == 5 && Tens_count !=3)
						{ones_count=0;
							temp=(Tens_count*10);
							EEPROM_SendData(0X00,temp);//save in EEPROM
							while(SW_u8_reed(2)==0);
							EEPROM_ReadData(0x00,&temp);
						}else if (ones_count == 0 && Tens_count !=3)
						{
							ones_count=5;
							Tens_count--;
							temp=Tens_count*10+ones_count;
							EEPROM_SendData(0X00,temp);
							while(SW_u8_reed(2)==0);
							EEPROM_ReadData(0x00,&temp);
						}
					}
					//write on seven segment
					Tens_count=temp/10;
					ones_count=temp-Tens_count*10;
					seting_mode_counter=0;//count 5 sec after last press
				}
				
		}else
		{//NOTHING
		}
// on or off the system 
				 if (SW_u8_reed(3)== 0)
				{on_off_count++;
					if (on_off_count == 2)//system off
					{	on_off_count=0;	}
					
					else if (on_off_count == 1)//system oN
					{	
						TIMER_vid_Reset();
						TIMER_vid_Start();
						seting_mode=0;
						seting_mode_counter=0;
					}
						while(SW_u8_reed(3) == 0);		
				}	
	
				
	//timers 			
// reading the temp sensor and the timer of the system 100ms
		if (temp_timer==25)
		{	water_temp_arr[temp_counter]=(float32)((float32)((float32)EXT_ADC_u16ReadDigitalVal(CHANNEL0)*2.5)/10);
			temp_counter++;
			if (temp_counter==10)
			{water_temp=water_temp_arr[0];
				for (uint8 i=1;i<10;i++)
				{water_temp+=water_temp_arr[i];
				}
				water_temp/=10;
				temp_counter=0;				
			}
			temp_timer=0;
		}
		
//setting mode waiting 5 sec
if (seting_mode_counter == 1250)
	{ seting_mode =0;
	  on_off_count = 1;
	  seting_mode_counter=0;
	  TIMER_vid_Reset();
	  TIMER_vid_Start();
	}
	
//blinking seven segment or heading led 1sec
 if (blink_counter==125)
 {	 if (seting_mode ==1)//seven segment
	 { if (blink_toggle == 0)
	 {	SE7_seg_vid_write(Tens_count,1);
		SE7_seg_vid_write(ones_count,2);
		blink_toggle++;
	 }else if(blink_toggle == 1)
     {
	 SE7_seg_vid_write(10,1);
	 SE7_seg_vid_write(10,2);
	 blink_toggle=0;
     }
	}
	else//heading led
	 {
		  if (heating_indicator==1 && on_off_count ==1)
		 {LED_vid_write(TOGGLE_LED,Heating_Element_led);
		 }else
		 {// nothing
		 }
	  }
	  blink_counter=0;
	 }
	 if ( colling_indicator==1 && on_off_count ==1)
	 {
		 LED_vid_write(HIGH_LED,Heating_Element_led);
	 }	
	 
// save the power if you forgot the electric water heater
 if (Req_Temp_achieved_counter == 60000)
 {on_off_count=0;
  Req_Temp_achieved_counter=0;
 }
 
 
			 // heater and cooler 
//system off doings
if (on_off_count==0 && seting_mode==0)
{	Tens_count=temp/10;
	ones_count=temp%10;
	SE7_seg_vid_write(Tens_count,1);
	SE7_seg_vid_write(ones_count,2);
	TIMER_vid_Reset();
	TIMER_vid_Stop();
}else
{
	//nothing
}

//the Heating and cooling Element control
		if (on_off_count==1)
		{	LED_vid_write(HIGH_LED,on_off_led);
			Tens_count=water_temp/10;
			ones_count=water_temp%10;
			if (water_temp > 99)
			{
			Tens_count=9;
			ones_count=9;
			}
			
			SE7_seg_vid_write(Tens_count,1);
			SE7_seg_vid_write(ones_count,2);
			//the first water temp is near to required temp already
			if ((water_temp < (temp+5) ) && ( water_temp > (temp-5)) && (colling_indicator==0 && heating_indicator==0)&& Req_Temp_achieved_indicator==0) 
			{	Req_Temp_achieved_indicator=1;
				Req_Temp_achieved_counter=0;
			}
			else if ((water_temp == (temp+5) && heating_indicator==1) || (colling_indicator==1 && water_temp == (temp-5))) //achieve the required temp
			{LED_vid_write(LOW_LED,Heating_Element_led);
				COLLER_vid_write(COLLER_OFF);
				HEATER_vid_write(Heater_OFF);
				heating_indicator=0;
				colling_indicator=0;
				Req_Temp_achieved_indicator=1;
				Req_Temp_achieved_counter=0;
			}
			else if (water_temp < (temp-5))//cooling Element on
			{	COLLER_vid_write(COLLER_OFF);
				HEATER_vid_write(Heater_ON);
			heating_indicator=1;colling_indicator=0;
			Req_Temp_achieved_counter=0;
			}
			else if (water_temp > (temp+5))//heating Element on
			{	COLLER_vid_write(COLLER_ON);
				HEATER_vid_write(Heater_OFF);
			colling_indicator=1;heating_indicator=0;
			Req_Temp_achieved_counter=0;
			}else 
			{//nothing
			}
		}else
		{
		//nothing
		}
    }
}

void timer_isr (void)//function of the timer
{
	temp_timer++;
	if (seting_mode == 1)
	{
		seting_mode_counter++;
		blink_counter++;
	}else if (on_off_count == 1 )
	{if (heating_indicator == 1)
	{blink_counter++;
	}else if (Req_Temp_achieved_indicator==1)
		{Req_Temp_achieved_counter++;
		}
	}
	
}