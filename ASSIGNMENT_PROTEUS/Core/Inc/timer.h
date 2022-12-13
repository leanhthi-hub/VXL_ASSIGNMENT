/*
 * timer.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Leanhthi
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;



extern int timerOut1_flag;
extern int timerOut2_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void setTimerOut1(int duration);
void setTimerOut2(int duration);

void timerRun0();
void timerRun1();
void timerRun2();
void timerRun3();


void timerOut1();
void timerOut2();

#endif /* INC_TIMER_H_ */
