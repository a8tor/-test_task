#ifndef __LOGIC_H
#define __LOGIC_H

#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "main.h"

#define RIGHT 0
#define LEFT 1
#define FORWARD 3
#define BACKWARD 4


#define SPEED_MIN 200
#define SPEED_MAX 65535

extern uint16_t left_dist;
extern uint16_t forward_dist;
extern uint16_t right_dist;
extern TIM_HandleTypeDef htim1;
typedef enum{
OK = 0,
ERR = 1
} Err;


Err set_dir(uint8_t direction);

Err move(void);

Err set_speed(uint16_t speed);
#endif //__LOGIC_H


