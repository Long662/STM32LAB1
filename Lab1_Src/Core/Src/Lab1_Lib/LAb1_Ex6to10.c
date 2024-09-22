/*
 * LAb1_Ex6to10.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */

#include "Lab1_Ex6to10.h"

//-----------------------------------------------
// BEGIN of exercise 6
int LED_Pin[12] = {	LED1_Pin, LED2_Pin, LED3_Pin, LED4_Pin,
					LED5_Pin, LED6_Pin, LED7_Pin, LED8_Pin,
					LED9_Pin, LED10_Pin, LED11_Pin, LED12_Pin};
void Lab1_Ex6_Init(){
	for (int i = 0; i < 12; i++) {
		HAL_GPIO_WritePin(GPIOA, LED_Pin[i], SET);
	}
//	HAL_GPIO_WritePin(GPIOA, LED1_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED2_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED3_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED4_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED5_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED6_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED7_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED8_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED9_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED10_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED11_Pin, SET);
//	HAL_GPIO_WritePin(GPIOA, LED12_Pin, SET);
}

void Lab1_Ex6_Run(){
	static int count = 0;
	HAL_GPIO_WritePin(GPIOA, LED_Pin[count], RESET);
	count = (count >= 11)?0:(count + 1);
}
// END of exercise 6
//-----------------------------------------------

