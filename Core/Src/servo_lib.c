/*
 * servo_lib.c
 *
 *  Created on: Jan 17, 2023
 *      Author: ilbey
 */

#include "servo_lib.h"



void init_servo(	servo_config* 		servo_config,
					GPIO_TypeDef*		servo_GPIOx,
					uint32_t 			servo_GPIO_pin,
					TIM_HandleTypeDef*	Timer_Handle,
					uint32_t			Timer_Channel)
{
	servo_config->servo_GPIOx 			=servo_GPIOx;
	servo_config->servo_GPIO_pin 		=servo_GPIO_pin;
	servo_config->Timer_Handle 			=Timer_Handle;
	servo_config->Timer_Channel			=Timer_Channel;
}


uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void servo_angle(servo_config* servo_config, uint32_t angle)
{
	if(0!= angle)
	{
		HAL_TIM_PWM_Start(servo_config->Timer_Handle, servo_config->Timer_Channel);
		__HAL_TIM_SET_COMPARE(servo_config->Timer_Handle,servo_config->Timer_Channel, map(angle,0,180,1000,2000));
	}

}

