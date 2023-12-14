/*
 * DIO_prog.c
 *
 * Author : Mahmoud Barakat
 */ 

//files need them to write the file

#include "SERV_STD.h"  //the file has the data types 
#include "SERV_BITMATH.h" //the file has functions to set,clear and toggle  port and pin
#include "DIO_priv.h"// the file has the configuration of the MC (the address of the registers)
#include "DIO_int.h"//the file has the declaration of functions and the main variables(port_x and pin_x)

			/***********************************************************************************************************/
//the array of the addresses of registers
	volatile uint8 * DIR_REG_Address[4] ={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};// direction registers addresses
	volatile uint8 * PORT_REG_Address[4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};// output registers addresses
	volatile uint8 * PIN_REG_Address[4]={PINA_REG,PINB_REG,PINC_REG,PIND_REG};// input registers addresses	
		
			/***********************************************************************************************************/
//the implementation of the functions
		 // if there is an error know it
// functions for port
void DIO_vid_SET_PORT_DIR (uint8 u8PORT_NUM,uint8 u8PORT_DIR){
	//u8PORT_NUM the port number(A,B,C,D)
	//u8PORT_DIR (input port,output port)
	if (u8PORT_NUM <= DIO_PORT_D)
	{
		switch (u8PORT_DIR)
		{
			case 0://INPUT PORT
			CLEAR_port(*DIR_REG_Address[u8PORT_NUM]);
			break;
			case 1://OUTPUT PORT
			SET_port(*DIR_REG_Address[u8PORT_NUM]);
		}
	}else{}
	}// determine the direction of the port
	
void DIO_VID_SET_PORT_VALUE (uint8 u8PORT_NUM,uint8 u8PORT_VALUE){
		//u8PORT_NUM the port number(A,B,C,D)
		//u8PORT_VALUE (high port,low port,toggle port)
	if (u8PORT_NUM <= DIO_PORT_D)
	{
		switch (u8PORT_VALUE)
		{
			case 0://LOW PORT
			CLEAR_port(*PORT_REG_Address[u8PORT_NUM]);
			break;
			case 1://HIGH PORT
			SET_port(*PORT_REG_Address[u8PORT_NUM]);
			break;
			case 2://TOGGLE PORT
			TOGGLE_port (*PORT_REG_Address[u8PORT_NUM]);
			default:
			*PORT_REG_Address[u8PORT_NUM]=u8PORT_VALUE;
			break;
		}
	}else{}
	}// determine the value to write on the port
	
uint8 DIO_U8_GET_PORT_VALUE (uint8 u8PORT_NUM){
	//u8PORT_NUM the port number(A,B,C,D)
	uint8 port_red_value;// the value red from the port
	if (u8PORT_NUM <= DIO_PORT_D)
	{
	port_red_value=*PIN_REG_Address[u8PORT_NUM];
	return port_red_value;
	}else{}
	}// get the value was red from the port
	
			/***********************************************************************************************************/
/*
// functions for pin in first way
void DIO_vid_SET_PIN_DIR (uint8 u8PORT_NUM,uint8 u8PIN_NUM,uint8 u8PIN_DIR){
			//u8PORT_NUM the port number(A,B,C,D)
			//u8PIN_NUM the pin number(0-7)
			//u8PIN_DIR (input pin,output pin)
			if (u8PORT_NUM <= DIO_PORT_D)
			{	if (u8PIN_NUM<=PIN_7)
				{switch (u8PIN_DIR)
				{
					case 0://INPUT PIN
					CLEAR_pin(*DIR_REG_Address[u8PORT_NUM],u8PIN_NUM);
					break;
					case 1://OUTPUT PIN
					SET_pin(*DIR_REG_Address[u8PORT_NUM],u8PIN_NUM);
					break;
				}
				}else{error=2;}
			}else{error=1;}
	}// determine the direction of the PIN
	
void DIO_VID_SET_PIN_VALUE (uint8 u8PORT_NUM,uint8 u8PIN_NUM,uint8 u8pin_value){
			//u8PORT_NUM the port number(A,B,C,D)
			//u8PIN_NUM the pin number(0-7)
			//u8PIN_VALUE the pin value (high pin,low pin,toggle pin)
			if (u8PORT_NUM <= DIO_PORT_D)
			{	if (u8PIN_NUM<=PIN_7)
				{switch (u8PIN_VALUE)
					{
						case 0://LOW PIN
						CLEAR_pin(*PORT_REG_Address[u8PORT_NUM],u8PIN_NUM);
						break;
						case 1://HIGH PIN
						SET_pin(*PORT_REG_Address[u8PORT_NUM],u8PIN_NUM);
						break;
						case 2://TOGGLE PIN
						TOGGLE_PIN(*PORT_REG_Address[u8PORT_NUM],u8PIN_NUM);
						break;
					}
					}else{error=2;}
					}else{error=1;}
						
	}// determine the value to write on the PIN
	
uint8 DIO_U8_GET_PIN_VALUE (uint8 u8PORT_NUM,uint8 u8PIN_NUM){
			//u8PORT_NUM the port number(A,B,C,D)
			//u8PIN_NUM the pin number(0-7)
			uint8 pin_red_value;// the value red from the port
			if (u8PORT_NUM <= DIO_PORT_D)
			{	if (u8PIN_NUM<=PIN_7)
				{
					pin_red_value=GET_pin (*PIN_REG_Address,u8PIN_NUM)
					return pin_red_value;
				}else{error=2;}
			}else{error=1;}
	
	}// get the value was red from the PIN
	*/

			/***********************************************************************************************************/

// functions for pin in second way
void DIO_vid_SET_PIN_DIR (uint8 u8PIN_NUM,uint8 u8PIN_DIR)// determine the direction of the PIN
			//u8PIN_NUM the pin number(0-31)
			//u8PIN_DIR (input pin,output pin)
			{	if (0<= u8PIN_NUM&&u8PIN_NUM <=31)
				{switch (u8PIN_DIR)
					{
						case 0://INPUT PIN
						CLEAR_pin(*DIR_REG_Address[u8PIN_NUM/8],(u8PIN_NUM%8));
						break;
						case 1://OUTPUT PIN
						SET_pin(*DIR_REG_Address[u8PIN_NUM/8],(u8PIN_NUM%8));
						break;
					}
					}else{}}
						
void DIO_VID_SET_PIN_VALUE (uint8 u8PIN_NUM,uint8 u8PIN_VALUE){// determine the value to write on the PIN
			//u8PIN_NUM the pin number(0-31)
			//u8PIN_VALUE the pin value (high pin,low pin,toggle pin)
				if (0<= u8PIN_NUM&&u8PIN_NUM <=31)
				{switch (u8PIN_VALUE)
					{
						case 0://LOW PIN
						CLEAR_pin(*PORT_REG_Address[u8PIN_NUM/8],(u8PIN_NUM%8));
						break;
						case 1://HIGH PIN
						SET_pin(*PORT_REG_Address[u8PIN_NUM/8],(u8PIN_NUM%8));
						break;
						case 2://toggle pin
						TOGGLE_pin(*PORT_REG_Address[u8PIN_NUM/8],(u8PIN_NUM%8));
						break;
					}
					}else{}}
uint8 DIO_U8_GET_PIN_VALUE (uint8 u8PIN_NUM){// get the value was red from the PIN
			//u8PIN_NUM the pin number(0-31)
			uint8 pin_red_value=0;// the value red from the port
			if (0<= u8PIN_NUM&&u8PIN_NUM <=31)
			{
				pin_red_value=GET_pin(* PIN_REG_Address[(u8PIN_NUM/8)],(u8PIN_NUM%8));
				return pin_red_value;
			}else{}}