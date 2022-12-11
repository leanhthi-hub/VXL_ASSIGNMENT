/*
 * fsm.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Leanhthi
 */


#include "fsm.h"
//HAL_GPIO_WritePin(GPIOB, ledpa_Pin|led1b_Pin|led2b_Pin|led2a_Pin, GPIO_PIN_RESET);
//HAL_GPIO_WritePin(GPIOA, ledpb_Pin|led1a_Pin, GPIO_PIN_RESET);
void toogleRed(){
	HAL_GPIO_WritePin(GPIOA,led1a_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,led1b_Pin, GPIO_PIN_SET);
}
void toogleGreen(){
	HAL_GPIO_WritePin(GPIOA,led1a_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,led1b_Pin, GPIO_PIN_RESET);
}
void toogleYellow(){
	HAL_GPIO_WritePin(GPIOA,led1a_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,led1b_Pin, GPIO_PIN_RESET);
}
void toogleRed1(){
	HAL_GPIO_WritePin(GPIOB,led2a_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,led2b_Pin, GPIO_PIN_SET);
}
void toogleGreen1(){
	HAL_GPIO_WritePin(GPIOB,led2a_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,led2b_Pin, GPIO_PIN_RESET);
}
void toogleYellow1(){
	HAL_GPIO_WritePin(GPIOB,led2a_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,led2b_Pin, GPIO_PIN_RESET);
}
void fsm_automatic_run1(){
	switch (status1	) {
		case INIT:
			status1 = AUTO_RED;
			setTimer1(RED_TIME);
			break;
		case AUTO_RED:
			toogleRed();
			if(timer1_flag==1){
				status1 = AUTO_GREEN;
				setTimer1(GREEN_TIME);
				timer=GREEN_TIME/100;
			}


			break;
		case AUTO_GREEN:
			toogleGreen();
			if(timer1_flag==1){
				status1 = AUTO_YELLOW;
				setTimer1(YELLOW_TIME);
				timer=YELLOW_TIME/100;
			}


			break;
		case AUTO_YELLOW:
			toogleYellow();
			if(timer1_flag==1){
				status1 = AUTO_RED;
				setTimer1(RED_TIME);
				timer=RED_TIME/100;
			}



			break;
		default:
			break;
	}
}


void fsm_automatic_run2(){
	switch (status2	) {
		case INIT:
			status2 = AUTO_GREEN;
			setTimer2(GREEN_TIME);
			break;
		case AUTO_RED:
			toogleRed1();
			if(timer2_flag==1){
				status2 = AUTO_GREEN;
				setTimer2(GREEN_TIME);
				timer2=GREEN_TIME/100;
			}


			break;
		case AUTO_GREEN:
			toogleGreen1();
			if(timer2_flag==1){
				status2 = AUTO_YELLOW;
				setTimer2(YELLOW_TIME);
				timer2=YELLOW_TIME/100;
			}


			break;
		case AUTO_YELLOW:
			toogleYellow1();
			if(timer2_flag==1){
				status2 = AUTO_RED;
				setTimer2(RED_TIME);
				timer2=RED_TIME/100;
			}



			break;
		default:
			break;
	}
}

#include "fsm.h"

void fsm_automatic_run3(){
	switch (status3	) {
		case RUNNING:
			if( timer0_flag == 1) {
					Print_HELLO();
					  timer--;
					  timer2--;
					  setTimer0 (100) ;
				  }
			if(button_flag[0]==1){
				button_flag[0]=0;
				status1=Waiting;
				status2=Waiting;
				status3=MAN_RED;
				timer2=RED_TIME/100;
			}
			break;

		case INIT:
			status1=INIT;
			status2=INIT;
			status3=RUNNING;



			break;
		case MAN_RED:
			toogleRed();
			toogleRed1();
			if(timer2>99)timer2=0;

			timer=01;
			if(button_flag[0]==1){
				button_flag[0]=0;
				timer2=GREEN_TIME/100;
				status3=MAN_GREEN;
			}
			if(button_flag[1]==1){
				Print_HELLO();
				button_flag[1]=0;
				timer2++;
			}
			if(button_flag[2]==1){
				button_flag[2]=0;
				timer2--;
			}
			if(button_flag[3]==1){
				button_flag[3]=0;
				RED_TIME=timer2*100;
			}
			break;
		case MAN_GREEN:
			toogleGreen();
			toogleGreen1();
			if(timer2>99)timer2=0;

			timer=02;
			if(button_flag[0]==1){
				button_flag[0]=0;
				timer2=YELLOW_TIME/100;
				status3=MAN_YELLOW;
			}
			if(button_flag[1]==1){
				button_flag[1]=0;
				timer2++;
			}
			if(button_flag[2]==1){
				button_flag[2]=0;
				timer2--;
			}
			if(button_flag[3]==1){
				button_flag[3]=0;
				YELLOW_TIME=timer2*100;
			}



			break;
		case MAN_YELLOW:
			toogleYellow();
			toogleYellow1();
			if(timer2>99)timer2=0;

			timer=03;
			if(button_flag[0]==1){
				button_flag[0]=0;

				status3=INIT;
			}
			if(button_flag[1]==1){
				button_flag[1]=0;
				timer2++;
			}
			if(button_flag[2]==1){
				button_flag[2]=0;
				timer2--;
			}
			if(button_flag[3]==1){
				button_flag[3]=0;
				YELLOW_TIME=timer2*100;
			}


			break;

		default:
			break;
	}
}
