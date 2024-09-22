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
