/*
 * timer.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Leanhthi
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


extern int timer0_flag;
extern int timer3_flag;

void setTimer0(int duration);
void setTimer3(int duration);

void timerRun0();
void timerRun3();


#endif /* INC_TIMER_H_ */
