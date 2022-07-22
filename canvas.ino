#include "./canvas.h"

void create_canvas(canvas_t canvas)
{
	create_canvas(canvas, CANVAS_PIN, CANVAS_WIDTH, CANVAS_HEIGHT);
}

void create_canvas(canvas_t canvas, uint8_t pin, uint8_t width, uint8_t height)
{
	canvas = (canvas_t)malloc(sizeof(canvas_t));
	canvas->matrix = new Adafruit_NeoMatrix(width, height, pin);
	canvas->width = width;
	canvas->height = height;
}

void init_canvas(canvas_t canvas)
{
	canvas->matrix->begin();
	for (int i = 0; i < CANVAS_SIZE; i++)
	{
		canvas->matrix->setPixelColor(i, canvas->matrix->Color(0, 0, 0));
	}
}

void clear_canvas(canvas_t canvas)
{
	for (uint16_t i = 0; i < CANVAS_SIZE; i++)
	{
		canvas->matrix->setPixelColor(i, canvas->matrix->Color(0, 0, 0));
	}
}

void show_canvas(canvas_t canvas)
{
	canvas->matrix->show();
}

uint16_t get_color(canvas_t canvas, uint8_t r, uint8_t g, uint8_t b)
{
	canvas->matrix->Color(r, g, b);
}

void draw_pixel(canvas_t canvas, uint8_t x, uint8_t y, uint16_t color)
{
	canvas->matrix->setPixelColor(x + (y * canvas->width), color);
}
