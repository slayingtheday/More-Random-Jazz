#ifndef F_CPU
#define F_CPU 16000000UL // telling controller crystal frequency (16 MHz AVR ATMega328P)
#endif

#include <avr/io.h> //header to enable data flow control over pins. Defines pins, ports, etc.
#include <util/delay.h> //header to enable delay function in program

#define BUTTON1 1 // button switch connected to port B pin 1

#define DEBOUNCE_TIME 25 // time to wait while "de-bouncing" button 
#define LOCK_INPUT_TIME 300 // time to wait after a button press

void init_ports_mcu()
{
	DDRB=0xFFu; //	Set all pins of the PORTB as output.
	DDRB &= ~(1<<BUTTON1);//Makes first pin of PORTB as Input
	PORTB = 0xFF;  // Set all pins of the PORTB as HIGH. Led is turn on, also the internal Pull Up resistor of first pin PORTB is enable. 

	
	DDRC=0xFFu; //	Set all pins of the PORTC as output.
	PORTC=0x00u; // Set all pins of PORTC low which turns it off.

	DDRD=0xFFu; //	Set all pins of the PORTD as output.
	PORTD=0x00u; // Set all pins of PORTD low which turns it off.
}

unsigned char button_state()
{
	/* the button is pressed when BUTTON1 bit is clear */
	if (!(PINB & (1<<BUTTON1)))
	{
		_delay_ms(DEBOUNCE_TIME);
		if (!(PINB & (1<<BUTTON1))) return 1;
	}
	return 0;
}

int main (void)
{
		DDRB |= 1 << PINB1; // Set pin 9 on arduino to output

	/* 1. Set Fast PWM mode 14: set WGM11, WGM12, WGM13 to 1 */
	/* 3. Set pre-scaler of 8 */
	/* 4. Set Fast PWM non-inverting mode */
	TCCR1A |= (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);

	/* 2. Set ICR1 register: PWM period */
	ICR1 = 24999;

	/* 5. Set duty cycle */

	unsigned char n_led = 1; // LED number is on now
	init_ports_mcu();
	while (1)
	{
		if (button_state()) // If the button is pressed, toggle the LED's state and delay for 300ms (#define LOCK_INPUT_TIME)
		{
			OCR1A = 4899;

		_delay_ms(500);
			_
		}
	}
	return (0); 
}