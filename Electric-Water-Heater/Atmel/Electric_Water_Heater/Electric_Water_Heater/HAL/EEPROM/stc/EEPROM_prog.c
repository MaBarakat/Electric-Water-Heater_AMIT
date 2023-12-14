/*
 * EEPROM_prog.c
  *
  * Author : Mahmoud Barakat
 */ 

#include "SERV_STD.h"
#include "SERV_BITMATH.h"
#include "TWI_interface.h"
#include "EEPROM_int.h"

void EEPROM_voidInit (void)
{
	TWI_voidMasterInit();
}
//write data on EEPROM by TWI
void EEPROM_SendData(uint16 Copy_u16Adress,uint8 Copy_u8Data)
{
	EEPROM_SendDataByte(Copy_u16Adress,Copy_u8Data);
}

//Read data from EEPROM by TWI
void EEPROM_ReadData(uint16 Copy_u16Adress,uint8 *Copy_pu8Data)
{
	EEPROM_ReadDataByte(Copy_u16Adress,Copy_pu8Data);
}