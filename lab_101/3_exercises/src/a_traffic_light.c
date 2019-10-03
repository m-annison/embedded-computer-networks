/*
 * a_traffic_lights.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to gpio pins
gpio_pin_t led1 = {PA_8,  GPIOA, GPIO_PIN_8};
gpio_pin_t ledRed = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t ledAmb = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t ledGre = {PB_15, GPIOB, GPIO_PIN_15};


// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	
	init_gpio(led1, OUTPUT);
	init_gpio(ledRed, OUTPUT);
	init_gpio(ledAmb, OUTPUT);
	init_gpio(ledGre, OUTPUT);
	
	
	while(1){
	
		write_gpio(ledRed, HIGH);
		HAL_Delay(2000);
		write_gpio(ledAmb, HIGH);
		HAL_Delay(500);
		toggle_gpio(ledRed);
		toggle_gpio(ledAmb);
		write_gpio(ledGre, HIGH);
		HAL_Delay(3000);
		toggle_gpio(ledGre);
		toggle_gpio(ledAmb);
		HAL_Delay(1000);
		toggle_gpio(ledAmb);
	}
	

}
