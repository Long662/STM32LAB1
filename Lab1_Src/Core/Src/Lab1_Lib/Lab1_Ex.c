/*
 * Lab1_Ex1.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */

#include "Lab1_Ex.h"
//-----------------------------------------------------------------------------
// Exercise 1
void Lab1_Ex1_Init(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
}

void Lab1_Ex1_Run(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
}

//-----------------------------------------------------------------------------
// Exercise 2
void Lab1_Ex2_Init(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
}

void Lab1_Ex2_Run(){
	static int count = 0;
	if (count == 5) {
		HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	}
	else if (count == 8) {
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	}
	else if (count == 10) {
		HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
		HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		count = 0;
	}
	count++;
}
//-----------------------------------------------------------------------------
