#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRB		///< DDR of LED.
#define LED_PORT	PORTB		///< Port of LED.
#define	BLUE_PIN	0			///< Pin number of blue colour LED terminal.
#define GREEN_PIN	1			///< Pin number of green colour LED terminal.
#define RED_PIN		2			///< Pin number of red colour LED terminal.

void PORT_INIT(void);

int main(void){
	PORT_INIT();
	for(uint8_t i=BLUE_PIN;i<=RED_PIN;i++){
		LED_PORT = (1<<i);
		_delay_ms(500);
	}
}

/*!
 *	@brief Initialize Ports.
 */

void PORT_INIT(void){
	LED_DDR |= (1<<BLUE_PIN)|(1<<GREEN_PIN)|(1<<RED_PIN);
}