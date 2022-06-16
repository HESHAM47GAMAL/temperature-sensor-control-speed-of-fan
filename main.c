/*
 * main.c
 *
 *  Created on: Feb 24, 2022
 *      Author: 20112
 */


#include "lcd.h"
#include "adc.h"
#include "dc_motor.h"
int main(void)
{
	uint8 temp;
	ADC_ConfigType config={INTERNAL,F_CPU_8};
	LCD_init();
	ADC_init(&config);
	DcMotor_Init();
	LCD_displayStringRowColumn(0,3 ,"FAN is ");
	LCD_displayStringRowColumn(1,3 ,"Temp =   C ");
	while(1)
	{
		temp=LM35_getTemperature();//getvalue of temperature
		LCD_moveCursor(1,9); //move cursor to write value of temp
		if(temp>100)//condition to remove empty pixel
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(0,10);//move cursor to write if is off or on
		//condition depending on temperature fan maove with specific speed
		if(temp<30)
		{
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP,0);
		}
		else if((temp >= 30) && (temp<60))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,25);
		}
		else if((temp >= 60) && (temp<90))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,50);
		}
		else if((temp >= 90) && (temp<120))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,75);
		}
		else if((temp >= 120) )
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,100);
		}
	}
}
