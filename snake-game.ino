#include <stdio.h>
#include <stdint.h>

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "./canvas.h"
#include "./joy_stick.h"

canvas_t canvas = NULL;
joy_stick_t joy_stick = NULL;

void setup()
{
	Serial.begin(9600);

	create_canvas(canvas);
	init_canvas(canvas);

	create_joy_stick(joy_stick);
}

void loop()
{
	read_joy_stick_input(joy_stick);

	const uint16_t player_color = get_color(canvas, 0, 0, 255);

	// clear canvas state
	clear_canvas(canvas);

	// draw player
	draw_pixel(canvas, joy_stick->x, joy_stick->y, player_color);

	// show canvas updates
	show_canvas(canvas);

	delay(2501);
}
