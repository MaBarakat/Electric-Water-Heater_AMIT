//Author: Mahmoud_Barakat

/*Preprocessor file guard*/
#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_


#define GENERAL_CALL_RECOGNITION_DISABLE  0
#define GENERAL_CALL_RECOGNITION_ENABLE   1

#define General_Call_SLAVE_recognition GENERAL_CALL_RECOGNITION_ENABLE
#define General_Call_MASTER_recognition GENERAL_CALL_RECOGNITION_ENABLE


#define TWI_BIT_RATE_PRESCALER_1	1
#define TWI_BIT_RATE_PRESCALER_4	4
#define TWI_BIT_RATE_PRESCALER_16	16
#define TWI_BIT_RATE_PRESCALER_64	64

#define TWI_BIT_RATE_PRESCALER	TWI_BIT_RATE_PRESCALER_1

#define EEPROME_24C02   0
#define EEPROME_24C04   1
#define EEPROME_24C08   2
#define EEPROME_24C16   3

#define EEPROME_24C_TYPE EEPROME_24C16

#endif