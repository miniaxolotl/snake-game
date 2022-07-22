#include "./joy_stick.h"

void create_joy_stick(joy_stick_t joy_stick)
{
	joy_stick = (joy_stick_t)malloc(sizeof(joy_stick_t));
	joy_stick->x = 0;
	joy_stick->y = 0;
	joy_stick->last_x = 0;
	joy_stick->last_y = 0;
	joy_stick->direction = NONE;
}

void read_joy_stick_input(joy_stick_t joy_stick)
{
	if(joy_stick->x > JOYSTICK_THRESHOLD || joy_stick->x < -JOYSTICK_THRESHOLD)
	{
		joy_stick->last_x = joy_stick->x;
		joy_stick->x = analogRead(VRX_PIN);
	} else {
		joy_stick->x = 0;
	}

	if(joy_stick->y > JOYSTICK_THRESHOLD || joy_stick->y < -JOYSTICK_THRESHOLD)
	{
		joy_stick->last_y = joy_stick->y;
		joy_stick->y = analogRead(VRY_PIN);
	} else {
		joy_stick->y = 0;
	}

	if(joy_stick->x > 0 && joy_stick->y > 0) joy_stick->x = NORTH_EAST;
	if(joy_stick->x < 0 && joy_stick->y > 0) joy_stick->x = NORTH_WEST;
	if(joy_stick->x > 0 && joy_stick->y < 0) joy_stick->x = SOUTH_EAST;
	if(joy_stick->x < 0 && joy_stick->y < 0) joy_stick->x = SOUTH_WEST;
	if(joy_stick->x == 0 && joy_stick->y > 0) joy_stick->x = NORTH;
	if(joy_stick->x > 0 && joy_stick->y == 0) joy_stick->x = EAST;
	if(joy_stick->x == 0 && joy_stick->y < 0) joy_stick->x = SOUTH;
	if(joy_stick->x < 0 && joy_stick->y == 0) joy_stick->x = WEST;
}