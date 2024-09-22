/*
 * Lab1_Ex1.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */

#include "Lab1_Ex.h"
//-----------------------------------------------------------------------------
// BEGIN of exercise 1
void Lab1_Ex1_Init(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
}

void Lab1_Ex1_Run(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
}
// END of exercise 1
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// BEGIN of exercise 2
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
// END of exercise 2
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// BEGIN of exercise 3
void Lab1_Ex3_Init(){
	HAL_GPIO_WritePin(GPIOB, RED1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, GREEN1_Pin, SET);

	HAL_GPIO_WritePin(GPIOB, RED2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, GREEN2_Pin, SET);
}

void Lab1_Ex3_Run(){
	static int count1 = 0;
	static int count2 = 5;
	Traffic_light_action(RED1_Pin, YELLOW1_Pin, GREEN1_Pin, count1);
	Traffic_light_action(RED2_Pin, YELLOW2_Pin, GREEN2_Pin, count2);
	count1++;
	count1 = (count1 >= 10)?0:count1;
	count2++;
	count2 = (count2 >= 10)?0:count2;
}

// Note: this void just work if all led pin connect to port GPIOB
void Traffic_light_action(int Red_pin, int Yellow_pin, int Green_pin, int Time_init){
	switch(Time_init){
		case 0:	HAL_GPIO_WritePin(GPIOB, Yellow_pin, SET);
				HAL_GPIO_WritePin(GPIOB, Red_pin, RESET);
				break;
		case 5:	HAL_GPIO_WritePin(GPIOB, Red_pin, SET);
				HAL_GPIO_WritePin(GPIOB, Green_pin, RESET);
				break;
		case 8: HAL_GPIO_WritePin(GPIOB, Green_pin, SET);
				HAL_GPIO_WritePin(GPIOB, Yellow_pin, RESET);
				break;
	}
}
// END of exercise 3
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// BEGIN of exercise 4
LED7SEG_Name SEG1;

void Lab1_Ex4_Init(){
	LED7SEG_Init(&SEG1,	SEG1_A_GPIO_Port, SEG1_A_Pin,
						SEG1_B_GPIO_Port, SEG1_B_Pin,
						SEG1_C_GPIO_Port, SEG1_C_Pin,
						SEG1_D_GPIO_Port, SEG1_D_Pin,
						SEG1_E_GPIO_Port, SEG1_E_Pin,
						SEG1_F_GPIO_Port, SEG1_F_Pin,
						SEG1_G_GPIO_Port, SEG1_G_Pin);
}

void display7SEG(int num){
	LED7SEG_Write(&SEG1, num);
}

// END of exercise 4
//-----------------------------------------------------------------------------
