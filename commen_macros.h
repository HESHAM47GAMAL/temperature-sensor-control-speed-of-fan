/******************************************
* Module: commen - macros
*
* File Name: commen_macros.h
*
* Description: commen macros used
*
* Author: Hesham Shehata
*
******************************************/


#ifndef COMMEN_MACROS_H_
#define COMMEN_MACROS_H_

/* set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* clear a certain bit in any register*/
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* toggle a certain bit in any register*/
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* rotate right register bits(value) with specific number of rotates*/
#define ROR(REG,NUM) (REG=(REG>>NUM)|(REG<<(8-NUM)))

/* rotate left register bits(value) with specific number of rotates */
#define ROL(REG,NUM) (REG=(REG<<NUM)|(REG>>(8-NUM)))

/* check if specific bit is set and if set return yes*/
#define BIT_IS_SET(REG,BIT) (REG&(1<<BIT))

/* check if specific bit is cleared and if cleared reurn true */
#define BIT_IS_CLEAR(REG,BIT) (!(REG&(1<<BIT)))


#endif /*COMMEN_MACROS_H_*/
