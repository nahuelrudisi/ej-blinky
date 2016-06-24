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
#include "delay.h"
#include "bits.h"		// No hace falta crear bits.c porque no tiene funciones, solo son definiciones

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
