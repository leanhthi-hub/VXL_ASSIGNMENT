/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Leanhthi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 23092002
#define RUNNING 100
#define Waiting 99




#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

#define MAN_RED 11
#define MAN_GREEN 12
#define MAN_YELLOW 13


#define HAND_RED 21
#define HAND_GREEN 22
#define HAND_YELLOW 23


#define P_RED 31
#define P_GREEN 32


extern int timer;
extern int timer2;
extern int timer3;

extern int status1;
extern int status2;
extern int status3;
extern int status4;

extern int RED_TIME;
extern int GREEN_TIME;
extern int YELLOW_TIME;




extern int global_time;
void update_time();
int get_time();
#endif /* INC_GLOBAL_H_ */
