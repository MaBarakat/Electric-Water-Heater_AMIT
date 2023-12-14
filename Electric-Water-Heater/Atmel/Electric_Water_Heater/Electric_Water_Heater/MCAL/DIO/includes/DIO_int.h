/*
 * DIO_int.h
 *
 * Author : Mahmoud Barakat
 *
 */ 
 
//pin &port in higher case letter 
#ifndef DIO_INT_H_
#define DIO_INT_H_

//the port number (A->0,B->1,C->2,D->3)
typedef enum {DIO_PORT_A,DIO_PORT_B,DIO_PORT_C,DIO_PORT_D} DIO_PORT_N;
	
/*	//the pin number in one port (0,1,2,3,4,5,6,7) way_1
typedef enum {DIO_PIN_0,DIO_PIN_1,DIO_PIN_2,DIO_PIN_3,DIO_PIN_4,DIO_PIN_5,DIO_PIN_6,DIO_PIN_7} DIO_PIN_N;*/
#define pins_of_port_A 0,1,2,3,4,5,6,7 //for seven_segment if in port
#define pins_of_port_B 8,9,10,11,12,13,14,15//for seven_segment if in port
#define pins_of_port_C 16,17,18,19,20,21,22,23//for seven_segment if in port
#define pins_of_port_D 24,25,26,27,28,29,30,31//for seven_segment if in port
/*	the pin number way 2 pin(0:31) the best write pin_0 --> 0 dirctally  
*typedef enum {DIO_PIN_0,DIO_PIN_1,DIO_PIN_2,DIO_PIN_3,DIO_PIN_4,DIO_PIN_5,DIO_PIN_6,DIO_PIN_7,
*			  DIO_PIN_8,DIO_PIN_9,DIO_PIN_10,DIO_PIN_11,DIO_PIN_12,DIO_PIN_13,DIO_PIN_14,DIO_PIN_15,
*			  DIO_PIN_16,DIO_PIN_17,DIO_PIN_18,DIO_PIN_19,DIO_PIN_20,DIO_PIN_21,DIO_PIN_22,DIO_PIN_23,
*			  DIO_PIN_24,DIO_PIN_25,DIO_PIN_26,DIO_PIN_27,DIO_PIN_28,DIO_PIN_29,DIO_PIN_30,DIO_PIN_31} DIO_PIN_N;	
*/

			/***********************************************************************************************************/
// the port type (input or output)
typedef enum {INPUT_PORT,OUTPUT_PORT} DIO_PORT_DIR;
	
// the pin type (input or output)
typedef enum {INPUT_PIN,OUTPUT_PIN} DIO_PIN_DIR;
	
			/***********************************************************************************************************/
// the port value (high or low)	
typedef enum {LOW_PORT,HIGH_PORT,TOGGLE_PORT} DIO_PORT_VALUE;	
	
// the pin value (high or low)	
typedef enum {LOW_PIN,HIGH_PIN,TOGGLE_PIN} DIO_PIN_VALUE;	

			/***********************************************************************************************************/
// functions for port	
	void DIO_vid_SET_PORT_DIR (uint8 u8PORT_NUM,uint8 u8PORT_DIR);// determine the direction of the port
	void DIO_VID_SET_PORT_VALUE (uint8 u8PORT_NUM,uint8 u8PORT_VALUE);// determine the value to write on the port
	uint8 DIO_U8_GET_PORT_VALUE (uint8 u8PORT_NUM);// get the value was red from the port

			/***********************************************************************************************************/	
/*
// functions for pin in first way
void DIO_vid_SET_PIN_DIR (uint8 u8PORT_NUM,uint8 u8PIN_NUM,uint8 u8PIN_DIR);// determine the direction of the PIN
void DIO_VID_SET_PIN_VALUE (uint8 u8PORT_NUM,uint8 u8PIN_NUM,uint8 u8PIN_VALUE);// determine the value to write on the PIN
uint8 DIO_U8_GET_PIN_VALUE (uint8 u8PORT_NUM,uint8 u8PIN_NUM);// get the value was red from the PIN	

*/

			/***********************************************************************************************************/

// functions for pin in second way
void DIO_vid_SET_PIN_DIR (uint8 u8PIN_NUM,uint8 u8PIN_DIR);// determine the direction of the PIN
void DIO_VID_SET_PIN_VALUE (uint8 u8PIN_NUM,uint8 u8PIN_VALUE);// determine the value to write on the PIN
uint8 DIO_U8_GET_PIN_VALUE (uint8 u8PIN_NUM);// get the value was red from the PIN


#endif /* DIO_INT_H_ */