#define ARDUINO 1000
#ifndef JOY_STICK_H
#define JOY_STICK_H

#include <stdint.h>

#include <Arduino.h>

#define VRX_PIN A2
#define VRY_PIN A3
#define JOYSTICK_THRESHOLD 200

typedef enum joy_stick_direction_t
{
	NORTH,
	NORTH_EAST,
	EAST,
	SOUTH_EAST,
	SOUTH,
	SOUTH_WEST,
	WEST,
	NORTH_WEST,
	NONE
} joy_stick_direction_t;

typedef struct
{
	int x;
	int y;
	int last_x;
	int last_y;
	joy_stick_direction_t direction;
} * joy_stick_t;

void create_joy_stick(joy_stick_t);

void read_joy_stick_input(joy_stick_t);

#endif // JOY_STICK_H