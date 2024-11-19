/*
 * TIMER.h
 *
 * Created: 10/22/2024 6:03:50 PM
 *  Author: User
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void Timer_CTC_init_interrupt(void);
void Timer_Wave_nonPWM(void);
void Timer_Wave_PWM(void);
void Timer_wave_PhasecorrectPWM(void);

#endif /* TIMER_H_ */