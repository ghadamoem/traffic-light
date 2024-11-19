/*
 * LED.h
 *
 * Created: 10/29/2023 8:56:06 PM
 *  Author: Ghada_Moemn
 */ 


#ifndef LED_H_
#define LED_H_
void LED_init(unsigned char PORT,unsigned char PIN);
void LED_ON(unsigned char PORT,unsigned char PIN);
void LED_OFF(unsigned char PORT,unsigned char PIN);
void LED_TOG(unsigned char PORT,unsigned char PIN);
char LED_ReadStaly(unsigned char PORT,unsigned char PIN);



#endif /* LED_H_ */