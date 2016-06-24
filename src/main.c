/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#define BIT24 0x1000000
#define BIT26 0x4000000
#define BIT28 0x10000000
#define BIT30 0x40000000
#define BIT12 0x1000		// LED 1
#define BIT13 0x2000		// LED 2
#define BIT14 0x4000		// LED 3
#define BIT15 0x8000 		// LED 4

void delay(uint16_t delay);

void main(void) {
	// CONFIGURACIÓN
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	// Habilito el Clock del bus GPIO

	GPIOD->MODER |= BIT24;					// Configuro como salida el bit 13
	GPIOD->MODER |= BIT26;
	GPIOD->MODER |= BIT28;
	GPIOD->MODER |= BIT30;

	while (1) {
//		GPIOD->ODR ^= BIT12;
		delay(5000);
		GPIOD->ODR &= ~(BIT15);
		GPIOD->ODR |= BIT12;
		delay(5000);
		GPIOD->ODR &= ~(BIT12);
		GPIOD->ODR |= BIT13;
		delay(5000);
		GPIOD->ODR &= ~(BIT13);
		GPIOD->ODR |= BIT14;
		delay(5000);
		GPIOD->ODR &= ~(BIT14);
		GPIOD->ODR |= BIT15;
	}
}

void delay(uint16_t delay) {
	uint8_t i = 0;
	while (delay-- > 0) {
		for (i = 100; i > 0; i--)
			asm("nop");
		// Instrucción en assembler para que el micro no haga nada
	}
}
