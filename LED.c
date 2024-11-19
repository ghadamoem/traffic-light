/*
 * LED.c
 *
 * Created: 10/29/2023 9:12:21 PM
 *  Author: Ghada_Moemn
 */ 

#include <avr/io.h>
#include "std_macros.h"
#include "DIO.h"
#include "LED.h"
void LED_init(unsigned char PORT,unsigned char PIN)
{
	DIO_SetPinDirection(PORT,PIN,1);

}
void LED_ON(unsigned char PORT,unsigned char PIN)
{
	DIO_WritePin(PORT,PIN,1);
}
void LED_OFF(unsigned char PORT,unsigned char PIN)
{
	DIO_WritePin(PORT,PIN,0);
}
void LED_TOG(unsigned char PORT,unsigned char PIN)
{
	
	DIO_TOG_PORT( PORT);
}
char LED_ReadStaly(unsigned char PORT,unsigned char PIN)
{
	
	return DIO_u8Read( PORT, PIN);
}