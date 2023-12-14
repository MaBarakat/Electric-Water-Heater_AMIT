//Author: Mahmoud_Barakat

/*Preprocessor file guard*/
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MstrWriteByteErr,
	MstrReadByteWithAckErr,
	ReservedAddressErr,
	NULLPOINTERDATA

}TWI_ErrorStatus;

void TWI_voidMasterInit (void);

/*TWI_ErrorStatus TWI_voidMasterInit(uint8 Copy_u8Address);*/

TWI_ErrorStatus TWI_voidSlaveInit(uint8 Copy_u8Address);

TWI_ErrorStatus TWI_SendStartCondition(void);

TWI_ErrorStatus TWI_SendRepeatedStart(void);

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAdress);

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAdress);

TWI_ErrorStatus TWI_MstrSendDataByte(uint8 Copy_u8Data);

TWI_ErrorStatus TWI_MstrReadDataByte(uint8 *Copy_pu8Data);

void TWI_SendStopCondition(void);

//write data on EEPROM by TWI 
TWI_ErrorStatus EEPROM_SendDataByte(uint16 Copy_u16Adress,uint8 Copy_u8Data);

//Read data from EEPROM by TWI
TWI_ErrorStatus EEPROM_ReadDataByte(uint16 Copy_u16Adress,uint8 *Copy_pu8Data);


#endif
