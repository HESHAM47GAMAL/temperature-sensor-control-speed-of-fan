/******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the dc_motor driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/
 
 #include "dc_motor.h"
 #include "avr/io.h"
 #include "gpio.h"
 #include "timer0.h"
 void DcMotor_Init(void)
 {
	 /*set two pins as output pin*/
	 GPIO_setupPinDirection(PORT_ID ,IN1_PIN_ID ,PIN_OUTPUT);
	 GPIO_setupPinDirection(PORT_ID ,IN2_PIN_ID ,PIN_OUTPUT);
	 /*give initial value zero*/
	 GPIO_writePin(PORT_ID ,IN1_PIN_ID ,LOGIC_LOW);
	 GPIO_writePin(PORT_ID ,IN2_PIN_ID ,LOGIC_LOW);
 }
 
 
 void DcMotor_Rotate(DcMotor_State state,uint8 speed)
 {
	 switch(state)
	 {
		 case CW:
		 GPIO_writePin(PORT_ID ,IN1_PIN_ID ,LOGIC_LOW);
		 GPIO_writePin(PORT_ID ,IN2_PIN_ID ,LOGIC_HIGH);
		 PWM_Timer0_Start(speed);
		 break;
		 case A_CW:
		 GPIO_writePin(PORT_ID ,IN1_PIN_ID ,LOGIC_HIGH);
		 GPIO_writePin(PORT_ID ,IN2_PIN_ID ,LOGIC_LOW);
		 PWM_Timer0_Start(speed);
		 break;
		 
		 case STOP:
		 GPIO_writePin(PORT_ID ,IN1_PIN_ID ,LOGIC_LOW);
		 GPIO_writePin(PORT_ID ,IN2_PIN_ID ,LOGIC_LOW);
		 PWM_Timer0_Start(0);
		 break;
	 }
 }
