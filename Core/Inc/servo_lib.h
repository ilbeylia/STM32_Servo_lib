/*
 * servo_lib.h
 *
 *  Created on: Jan 17, 2023
 *      Author: ilbey
 */

#ifndef INC_SERVO_LIB_H_
#define INC_SERVO_LIB_H_

#include	"stm32f4xx.h"

typedef struct{
	GPIO_TypeDef*		servo_GPIOx;
	uint32_t 			servo_GPIO_pin;
	TIM_HandleTypeDef*	Timer_Handle;
	uint32_t			Timer_Channel;
}servo_config;


void init_servo(	servo_config* 		servo_config,
					GPIO_TypeDef*		servo_GPIOx,
					uint32_t 			servo_GPIO_pin,
					TIM_HandleTypeDef*	Timer_Handle,
					uint32_t			Timer_Channel);

uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);


void servo_angle(servo_config* servo_config, uint32_t angle);



#endif /* INC_SERVO_LIB_H_ */
