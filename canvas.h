#define ARDUINO 1000
#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>

#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define CANVAS_PIN 3
#define CANVAS_WIDTH 8
#define CANVAS_HEIGHT 8
#define CANVAS_SIZE (CANVAS_WIDTH * CANVAS_HEIGHT)

typedef Adafruit_NeoMatrix *matrix_t;

typedef struct
{
	uint8_t width = 8;
	uint8_t height = 8;
	uint32_t grid[8][8];
	matrix_t matrix;
} * canvas_t;

void create_canvas(canvas_t);

void create_canvas(canvas_t, uint8_t, uint8_t, uint8_t);

void init_canvas(canvas_t);

void clear_canvas(canvas_t);

void show_canvas(canvas_t);

uint16_t get_color(canvas_t, uint8_t, uint8_t, uint8_t);

void draw_pixel(canvas_t, uint8_t, uint8_t, uint16_t);

#endif // CANVAS_H