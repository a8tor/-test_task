#include "logic.h"

Err set_dir(uint8_t direction){
	
	switch(direction){
		case FORWARD:
			HAL_GPIO_WritePin(GPIOB, DIR_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, DIR_2_Pin, GPIO_PIN_SET);
			break;
		case LEFT:
			HAL_GPIO_WritePin(GPIOB, DIR_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, DIR_2_Pin, GPIO_PIN_SET);
			break;
		case RIGHT:
			HAL_GPIO_WritePin(GPIOB, DIR_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, DIR_2_Pin, GPIO_PIN_RESET);
			break;
		case BACKWARD:
			HAL_GPIO_WritePin(GPIOB, DIR_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, DIR_2_Pin, GPIO_PIN_RESET);
			break;
		default:
			return ERR;
	}
	
return OK;
}


Err move(void){
	if(HAL_OK == HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1)){
		return OK;
	}
	else{
		return ERR;
	}
}

Err set_speed(uint16_t speed){
	if(speed < SPEED_MAX && speed > SPEED_MIN){
		TIM1->CCR1 = speed;
		TIM1->CCR2 = speed;
		return OK;
	} else {
		return ERR;
	}

}





