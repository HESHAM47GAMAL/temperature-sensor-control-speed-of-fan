/************************************
* Module: GPIO
*
*File Name: gpio.h
*
* Description: header file for AVR GPIO Driver
*
*
* Author: Hesham Shehata
************************************/



#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

/********************************************************************
*                                Definitions
********************************************************************/
#define NUM_OF_PORTS               4
#define NUM_OF_PINS_PER_PORT       8

#define PORTA_ID                   0
#define PORTB_ID                   1
#define PORTC_ID                   2
#define PORTD_ID                   3

#define PIN0_ID                    0
#define PIN1_ID                    1
#define PIN2_ID                    2
#define PIN3_ID                    3
#define PIN4_ID                    4
#define PIN5_ID                    5
#define PIN6_ID                    6
#define PIN7_ID                    7

/********************************************************************
*                                Types Decleration
********************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum 
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/********************************************************************
*                               Function Prototypes
********************************************************************/



/*
* Description:
* setup direction of specific pin in port input/output
* if input port number and pin number are not correct ,function will not handle request
*/
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDirectionType direction);       

/*
* Description:
* write value logic high or low in specific pin 
* if pin is input ,this function will activite/deactivate internal pull up resistor
* if input port number and pin number are not correct ,function will not handle request
*/
void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value);

/*
* Description:
* read and return value for specific pin, it should be logic high or low  
* if input port number and pin number are not correct ,function will return logic low
*/
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num);

/*
* Description:
* setup direction for specific port all pins input/output
* If the direction value is PORT_INPUT all pins in this port should be input pins
* If the direction value is PORT_OUTPUT all pins in this port should be output pins
* if input port number is not correct ,function will not handle request
*/
void GPIO_setupPortDirection(uint8 port_num,uint8 direction);

/*
* Description:
* write value for specific port
* if any pin in this port is output pin value will written
* if any pin in this port is input pin this will activate/deactivate internal pull up resistor
* if input port number is not correct ,function will not handle request
*/
void GPIO_writePort(uint8 port_num,uint8 value);

/*
* Description:
* read and return value for specific port
* if input port number is not correct ,function will return logic low
*/
void GPIO_readPort(uint8 port_num);








#endif/*GPIO_H_*/
