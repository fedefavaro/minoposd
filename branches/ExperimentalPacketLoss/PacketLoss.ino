/**
 ******************************************************************************
 *
 * @file       PacketLoss.ino
 * @author     Joerg-D. Rothfuchs
 * @brief      Implements packet loss detection and measurement
 * 	       on the Ardupilot Mega MinimOSD using INT1.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/> or write to the 
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


// !!! For using this, you have to solder a little bit on the MinimOSD, see the wiki !!!

// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>

#include "PacketLoss.h"


volatile int pin_value;
volatile int pin_hi = 0;
volatile int pin_lo = 0;


void PacketLoss_init(void) {
	cli();				// disable global interrupts
	attachInterrupt(PL_INT, pin_int, CHANGE);
	setup_timer_int();
	sei();				// enable global interrupts
	pin_value = digitalRead(PL_PACKET_PIN);
}


void PacketLoss_print(void) {
	static float packet_loss_percent = 0.0;
	
	packet_loss_percent = 10.0 / (pin_hi + pin_lo) * pin_lo + packet_loss_percent * .9;
	pin_hi = 0;
	pin_lo = 0;
	osd.printf("%c%3i%c", 0xE1, 100 - (uint8_t) packet_loss_percent, 0x25);  	// show 'inverted' value
}


void setup_timer_int() {
	TCCR1A	= 0;			// initialize TCCR1A
	TCCR1B	= 0;			// initialize TCCR1B
	OCR1A	= 249;			// set compare match register to 1ms timer count (16MHz, 64 prescaler)
	TCCR1B |= (1 << WGM12);		// turn on CTC mode
	TCCR1B |= (1 << CS10);		// set CS10 bit for 64 prescaler
	TCCR1B |= (1 << CS11);		// set CS11 bit for 64 prescaler
	TIMSK1 |= (1 << OCIE1A);	// enable timer compare interrupt
}


ISR (TIMER1_COMPA_vect) {
	if (pin_value) {
		pin_hi++;
	} else {
		pin_lo++;
	}
}


void pin_int(void) {
	pin_value = digitalRead(PL_PACKET_PIN);
}
