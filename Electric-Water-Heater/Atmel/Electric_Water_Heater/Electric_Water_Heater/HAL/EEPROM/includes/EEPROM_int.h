/*
 * EEPROM_int.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_
void EEPROM_voidInit (void);
//write data on EEPROM by TWI
void EEPROM_SendData(uint16 Copy_u16Adress,uint8 Copy_u8Data);

//Read data from EEPROM by TWI
void EEPROM_ReadData(uint16 Copy_u16Adress,uint8 *Copy_pu8Data);





#endif /* EEPROM_INT_H_ */