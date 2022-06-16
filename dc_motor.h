/******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the dc_motor driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/
 
 #ifndef DC_MOTOR_H_
 #define DC_MOTOR_H_
 #include "std_types.h"
 
  /*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
 #define PORT_ID       PORTB_ID
 #define IN1_PIN_ID    PIN0_ID
 #define IN2_PIN_ID    PIN1_ID
 
 typedef enum
 {
	 CW,A_CW,STOP
 }DcMotor_State;
 
 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 /*
  * Description :
  * set direction of pins and set as output
  */
 void DcMotor_Init(void);
 
 /*
  * Description :
  * set direction of motion and speed of motion
  */
 void DcMotor_Rotate(DcMotor_State state,uint8 speed);
 
 #endif
