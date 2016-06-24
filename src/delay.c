#include <stdint.h>	// Para que pueda interpretar uint8_t
#include "delay.h"	// En "" porque es un .h que defini yo y esta guardado en otra carpeta
					// Se puedo incluir una carpeta con .h propios para que el compilador busque los .h ahí y entonces podemos poner #include <delay.h>

void delay(uint16_t delay) {
	uint8_t i = 0;
	while (delay-- > 0) {
		for (i = 100; i > 0; i--)
			asm("nop");
		// Instrucción en assembler para que el micro no haga nada
	}
}

