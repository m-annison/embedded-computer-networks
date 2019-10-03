/*
 * b_led_dice.c
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
#include "random_numbers.h"

// map the led to gpio pins
gpio_pin_t led1 = {PA_8,  GPIOA, GPIO_PIN_8};
gpio_pin_t ledUL = {PC_7,  GPIOC, GPIO_PIN_7};
gpio_pin_t ledL = {PC_6,  GPIOC, GPIO_PIN_6};
gpio_pin_t ledM = {PG_6,  GPIOG, GPIO_PIN_6};
gpio_pin_t ledBL = {PI_3,  GPIOI, GPIO_PIN_3};
gpio_pin_t ledUR = {PG_7,  GPIOG, GPIO_PIN_7};
gpio_pin_t ledR = {PI_0,  GPIOI, GPIO_PIN_0};
gpio_pin_t ledBR = {PH_6,  GPIOH, GPIO_PIN_6};


// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	
	init_gpio(ledUL, OUTPUT);
	init_gpio(ledL, OUTPUT);
	init_gpio(ledBL, OUTPUT);
	init_gpio(ledM, OUTPUT);
	init_gpio(ledUR, OUTPUT);
	init_gpio(ledR, OUTPUT);
	init_gpio(ledBR, OUTPUT);
	
	init_random();
	
	uint32_t rnd = (get_random_int() % 6) + 1;
	

	
	if(rnd == 1){
		write_gpio(ledUL, LOW);
		write_gpio(ledL, LOW);
		write_gpio(ledBL, LOW);
		write_gpio(ledM, HIGH);
		write_gpio(ledUR, LOW);
		write_gpio(ledR, LOW);
		write_gpio(ledBR, LOW);
	}
	else if (rnd == 2){
			write_gpio(ledUL, HIGH);
		write_gpio(ledL, LOW);
		write_gpio(ledBL, LOW);
		write_gpio(ledM, LOW);
		write_gpio(ledUR, LOW);
		write_gpio(ledR, LOW);
		write_gpio(ledBR, HIGH);
	}
	else if (rnd == 3){
			write_gpio(ledUL, HIGH);
		write_gpio(ledL, LOW);
		write_gpio(ledBL, LOW);
		write_gpio(ledM, HIGH);
		write_gpio(ledUR, LOW);
		write_gpio(ledR, LOW);
		write_gpio(ledBR, HIGH);
	}
	else if (rnd == 4){
			write_gpio(ledUL, HIGH);
		write_gpio(ledL, LOW);
		write_gpio(ledBL, HIGH);
		write_gpio(ledM, LOW);
		write_gpio(ledUR, HIGH);
		write_gpio(ledR, LOW);
		write_gpio(ledBR, HIGH);
	}
	else if (rnd == 5){
			write_gpio(ledUL, HIGH);
		write_gpio(ledL, LOW);
		write_gpio(ledBL, HIGH);
		write_gpio(ledM, HIGH);
		write_gpio(ledUR, HIGH);
		write_gpio(ledR, LOW);
		write_gpio(ledBR, HIGH);
	}
	else if (rnd == 6) {
				write_gpio(ledUL, HIGH);
		write_gpio(ledL, HIGH);
		write_gpio(ledBL, HIGH);
		write_gpio(ledM, LOW);
		write_gpio(ledUR, HIGH);
		write_gpio(ledR, HIGH);
		write_gpio(ledBR, HIGH);
	}
}
