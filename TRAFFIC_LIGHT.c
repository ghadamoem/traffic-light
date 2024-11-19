/*
 * TRAFFIC_LIGHT.c
 *
 * Created: 10/29/2024 1:36:13 PM
 *  Author: Ghada_Momen
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define  F_CPU 8000000UL
#include "LED.h"
#include "LCD.h"
#include "TIMER.h"

volatile unsigned char counter1=0;
unsigned char counter_green=10;
unsigned char counter_yellow=5;
unsigned char counter_red=8;


int main(void)
{
	LCD_Initial();
	LED_init('D',0);
	LED_init('D',1);
	LED_init('D',2);
	Timer_CTC_init_interrupt();
    while(1)
    {
      counter_green=10;
	  counter_yellow=5;
	  counter_red=8;
	  LCD_CLR_Screen();
	  LCD_Send_String("Remaining 10 sec");
	  LED_ON('D',0);
	  while (counter_green>0)
	  {
		  if (counter1>=10)
		  {
			counter1=0;
			counter_green--;
			LCD_Move_Cursor(1,11);
			LCD_Send_data(' ');
			LCD_Send_data((counter_green%10)+48);
		  }
	  }
	  
	  _delay_ms(50);
	  LED_ON('D',1);
	  LED_OFF('D',0);
	    LCD_CLR_Screen();
	    LCD_Send_String("Remaining 5  sec");
	   
	    while (counter_yellow>0)
	    {
		    if (counter1>=10)
		    {
			    counter1=0;
			    counter_yellow--;
			    LCD_Move_Cursor(1,11);
			    LCD_Send_data(' ');
			    LCD_Send_data((counter_yellow%10)+48);
		    }
	    }
		 _delay_ms(50);
		  LED_ON('D',2);
		 LED_OFF('D',1);
		  LCD_CLR_Screen();
		  LCD_Send_String("Remaining 8  sec");
		  
		  while (counter_red>0)
		  {
			  if (counter1>10)
			  {
				  counter1=0;
				  counter_red--;
				  LCD_Move_Cursor(1,11);
				  LCD_Send_data(' ');
				  LCD_Send_data((counter_red%10)+48);
			  }
		  }
		  _delay_ms(50);
		  LED_OFF('D',2);
		
		  
	  
    }
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
}