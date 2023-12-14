/*
 * ADC_config.h
 *
 * Author : Mahmoud Barakat
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

//ADC VOLTAGE sources
#define ADC_AREF       0
#define ADC_AVCC       1
#define ADC_INTERNAL   2

#define ADC_VOLT_source   ADC_INTERNAL

// ADC ADJUSTMENT
#define ADC_Right_ADJUSTMENT      0
#define ADC_Left_ADJUSTMENT       1

#define ADC_ADJUSTMENT	ADC_Right_ADJUSTMENT

//ADC PRESCALER (ADC DIVISION FACTOR)

#define ADC_DIVISION_FACTOR_2        (uint8)0x01//can be 0x00
#define ADC_DIVISION_FACTOR_4        (uint8)0x02
#define ADC_DIVISION_FACTOR_8        (uint8)0x03
#define ADC_DIVISION_FACTOR_16       (uint8)0x04
#define ADC_DIVISION_FACTOR_32       (uint8)0x05
#define ADC_DIVISION_FACTOR_64       (uint8)0x06
#define ADC_DIVISION_FACTOR_128      (uint8)0x07

#define ADC_PRESCALER   ADC_DIVISION_FACTOR_64


/*---------CHANNEL CLEAR MASK-------*/

#define ADC_CLEAR_MASK  (uint8)0xE0//make MUXn=0

/*-------ADMUX_REG_bits--------*/
#define ADLAR   (uint8)5
#define REFS0   (uint8)6
#define REFS1   (uint8)7



/*------ADCSRA_bits-------*/
#define ADEN     (uint8)7//enable
#define ADSC     (uint8)6//start conversion 
#define ADATE    (uint8)5//auto triggering enable
#define ADIF     (uint8)4//INT flag
#define ADIE     (uint8)3//INT enable
//used ADC_PRESCALER  
//#define ADPS2    (uint8)2
//#define ADPS1    (uint8)1
//#define ADPS0    (uint8)0


/*-------SREG_bits-------*/
#define GIE   7



#endif /* ADC_CONFIG_H_ */