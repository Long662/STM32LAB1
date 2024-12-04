/*
 * LAb1_Ex6to10.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */

#include "Lab1_Ex6to10.h"

int LED_Pin[12] = {	LED1_Pin, LED2_Pin, LED3_Pin, LED4_Pin,
					LED5_Pin, LED6_Pin, LED7_Pin, LED8_Pin,
					LED9_Pin, LED10_Pin, LED11_Pin, LED12_Pin};

void Lab1_Ex6To10_Init(){
	for (int i = 0; i < 12; i++){
		HAL_GPIO_WritePin(GPIOA, LED_Pin[i], SET);
	}
}

//-----------------------------------------------
// BEGIN of exercise 6
void Lab1_Ex6_Run(){
	static int count = 0;
	HAL_GPIO_WritePin(GPIOA, LED_Pin[count], RESET);
	count = (count >= 11)?0:(count + 1);
	if (count == 0) ClearAllClock();
}
// END of exercise 6
//-----------------------------------------------


//-----------------------------------------------
// BEGIN of exercise 7
void ClearAllClock(){
	for (int i = 0; i < 12; i++){
		HAL_GPIO_WritePin(GPIOA, LED_Pin[i], SET);
	}
}
// END of exercise 7
//-----------------------------------------------


//-----------------------------------------------
// BEGIN of exercise 8
void setNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, LED_Pin[num], RESET);
}
// END of exercise 8
//-----------------------------------------------


//-----------------------------------------------
// BEGIN of exercise 9
void clearNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, LED_Pin[num], SET);
}
// END of exercise 9
//-----------------------------------------------


//-----------------------------------------------
// BEGIN of exercise 10
void Lab1_Ex10_AutoRun(){
	static int count_sec;
	static int count_min;
	static int count_hour;

	ClearAllClock();

	int hour_num = count_hour % 12;
	int min_num	= count_min / 5;
	int sec_num = count_sec / 5;

	setNumberOnClock(hour_num);
	setNumberOnClock(min_num);
	setNumberOnClock(sec_num);

	if (count_sec >= 59){
		if (count_min >= 59){
			count_hour++;
			count_min = 0;
		}
		else{
			count_min++;
		}
		count_sec = 0;
	}
	else
		count_sec++;
}

void Lab1_Ex10_EnterTime(uint8_t hours, uint8_t minutes, uint8_t seconds){
	ClearAllClock();
	// Error check
	if(hours >= 24 || minutes >= 60 || seconds >= 60){
		Lab1_Ex6_Run(); // When error, turn on everyled in sequence
	}
	setNumberOnClock(hours % 12);
	setNumberOnClock(minutes/5);
	setNumberOnClock(seconds/5);
}
// END of exercise 10
//-----------------------------------------------
