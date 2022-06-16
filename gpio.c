/************************************************
* Module: GPIO
*
* File Name: gpio.c
*
* Description: source file for AVR GPIO driver
*
* Author:Hesham Shehata
************************************************/
#include "gpio.h"
#include "commen_macros.h"
#include "avr/io.h"


/*
* Description:
* setup direction of specific pin in port input/output
* if input port number and pin number are not correct ,function will not handle request
*/
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDirectionType direction)
{
	/*
	*check if input port_num is greater than NUM_OF_PORTS
	*or if input pin_num is greater than NUM_OF_PINS_PER_PORT
	*in this case input pin_num and port_num is invalid
	*/
	if( (port_num>=NUM_OF_PORTS) || (pin_num>=NUM_OF_PINS_PER_PORT) )
	{
		/*Nothing to do*/
	}
	else 
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRA,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRA,pin_num);
				}
				break;
			case PORTB_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRB,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRB,pin_num);
				}
				break;
			case PORTC_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRC,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRC,pin_num);
				}
				break;
			case PORTD_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRD,pin_num);
				}
				else
				{
					CLEAR_BIT(DDRD,pin_num);
				}
				break;
			
		}
		
		
	}
	
}

/*
* Description:
* write value logic high or low in specific pin 
* if pin is input ,this function will activite/deactivate internal pull up resistor
* if input port number and pin number are not correct ,function will not handle request
*/
void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value)
{
	
	if( (port_num>=NUM_OF_PORTS) || (pin_num>=NUM_OF_PINS_PER_PORT) )
	{
		/*Nothing to do*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTA,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTA,pin_num);
				}
				break;
			case PORTB_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTB,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTB,pin_num);
				}
				break;
			case PORTC_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTC,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTC,pin_num);
				}
				break;
			case PORTD_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTD,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTD,pin_num);
				}
				break;
			
		}
		
	}
}

/*
* Description:
* read and return value for specific pin, it should be logic high or low  
* if input port number and pin number are not correct ,function will return logic low
*/
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;
	if( (port_num>=NUM_OF_PORTS) || (pin_num>=NUM_OF_PINS_PER_PORT) )
	{
		/*Nothing to do*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(BIT_IS_SET(PINA,pin_num))
				{
					pin_value = LOGIC_HIGH;
				}
				else
				{
					pin_value = LOGIC_LOW;
				}
				break;
			case PORTB_ID:
				if(BIT_IS_SET(PINB,pin_num))
				{
					pin_value = LOGIC_HIGH;
				}
				else
				{
					pin_value = LOGIC_LOW;
				}
				break;
			case PORTC_ID:
				if(BIT_IS_SET(PINC,pin_num))
				{
					pin_value = LOGIC_HIGH;
				}
				else
				{
					pin_value = LOGIC_LOW;
				}
				break;
			case PORTD_ID:
				if(BIT_IS_SET(PIND,pin_num))
				{
					pin_value = LOGIC_HIGH;
				}
				else
				{
					pin_value = LOGIC_LOW;
				}
				break;
			
		}
		
	}
	return pin_value;
}

/*
* Description:
* setup direction for specific port all pins input/output
* If the direction value is PORT_INPUT all pins in this port should be input pins
* If the direction value is PORT_OUTPUT all pins in this port should be output pins
* if input port number is not correct ,function will not handle request
*/
void GPIO_setupPortDirection(uint8 port_num,uint8 direction)
{
	if( (port_num>=NUM_OF_PORTS) )
	{
		/*Nothing to do*/
	}
	else 
	{
		switch(port_num)
		{
			case PORTA_ID:
				DDRA = direction;
				break;
			case PORTB_ID:
				DDRB = direction;
				break;
			case PORTC_ID:
				DDRC = direction;
				break;
			case PORTD_ID:
				DDRD = direction;
				break;
			
		}
	
	}
	
}

/*
* Description:
* write value for specific port
* if any pin in this port is output pin value will written
* if any pin in this port is input pin this will activate/deactivate internal pull up resistor
* if input port number is not correct ,function will not handle request
*/
void GPIO_writePort(uint8 port_num,uint8 value)
{
	
	if( (port_num>=NUM_OF_PORTS) )
	{
		/*Nothing to do*/
	}
	else 
	{
		switch(port_num)
		{
			case PORTA_ID:
				PORTA = value;
				break;
			case PORTB_ID:
				PORTB = value;
				break;
			case PORTC_ID:
				PORTC = value;
				break;
			case PORTD_ID:
				PORTD = value;
				break;
			
		}
	
	}
	
}

/*
* Description:
* read and return value for specific port
* if input port number is not correct ,function will return logic low
*/
void GPIO_readPort(uint8 port_num)
{
	uint8  port_value = LOGIC_LOW;
	if( (port_num>=NUM_OF_PORTS) )
	{
		/*Nothing to do*/
	}
	else 
	{
		switch(port_num)
		{
			case PORTA_ID:
				port_value = PINA;
				break;
			case PORTB_ID:
				port_value = PINB;
				break;
			case PORTC_ID:
				port_value = PINC;
				break;
			case PORTD_ID:
				port_value = PIND;
				break;
			
		}
	
	}
	
}









