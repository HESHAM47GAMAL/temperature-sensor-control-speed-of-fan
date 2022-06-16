 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/
 
 #include "adc.h"
 #include"avr/io.h"
 #include <avr/interrupt.h>
 #include "commen_macros.h"
 
 
 /*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
 volatile uint16 g_adcResult =0;
 
 /*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/
 ISR(ADC_vect)
 {
	 /* Read ADC Data after conversion complete */
	 g_adcResult=ADC;
 }
 
 /*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
 void ADC_init(const ADC_ConfigType * Config_Ptr)
 {
	 /* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);
	 
	 /* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 1 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADIE) ;
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);
 }
 
 
 void ADC_readChannelInt(uint8 channel_num)
 {
	 ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
	// channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	// ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	// ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	 SET_BIT(ADCSRA,ADSC);/* Start conversion write '1' to ADSC */
 }
 
 uint16 ADC_readChannel(uint8 channel_num)
 {
	  ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
	// channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	// ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	// ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	 SET_BIT(ADCSRA,ADSC);/* Start conversion write '1' to ADSC */
	 while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	 SET_BIT(ADCSRA,ADIF);/* Clear ADIF by write '1' to it :) */
	 return ADC;/* Read the digital value from the data register */
 }