#include <stdio.h>
#include <Adafruit_NeoPixel.h>

#define VRX_PIN A2 // Arduino pin connected to VRX pin
#define VRY_PIN A3 // Arduino pin connected to VRY pin

uint32_t CANVAS[8][8];

bool is_inital = true;
int iX = 0;
int iY = 0;

int dX = 0;
int dY = 0;

#define NUMPIXELS 64
#define PIN 3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int uX = 7 - 0;
int uY = 7 - 0;

void setup()
{
	Serial.begin(9600);
	pixels.begin();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//      const int xy = (i * 8) + j + 1;
			//      const int z = ((i * 8) + j + 1) % 17;
			//
			//      uint8_t red = 0;
			//      if(xy < 16) red = 255;
			//      if(xy > 15 && xy < 32) red = 255 - (z * 16) - 1;
			//      if(xy > 47) red = (z * 16) - 1;
			//
			//      uint8_t green = 0;
			//      if(xy < 16) green = (z * 16) - 1;
			//      if(xy > 15 && xy < 32) green = 255;
			//      if(xy > 31 && xy < 48) green = 255 - (z * 16) - 1;
			//
			//      uint8_t blue = 0;
			//      if(xy > 31 && xy < 48) blue = (z * 16) - 1;
			//      if(xy > 47) blue = 255;
			//
			CANVAS[i][j] = pixels.Color(
					0, 0, 0
					//        red,
					//        green,
					//        blue
			);
		}
	}
}

void loop()
{
	if (is_inital)
	{
		iX = analogRead(VRX_PIN) + 4;
		iY = analogRead(VRY_PIN) - 18;
		is_inital = false;
	}

	// read analog X and Y analog values
	dX = -analogRead(VRX_PIN) + CENTER_RES - 4;
	dY = analogRead(VRY_PIN) - CENTER_RES - 17;

	Serial.print("x: ");
	Serial.println(dX);

	Serial.print("y: ");
	Serial.println(dY);

	if (dX > 256 && uX - 1 >= 0)
	{
		CANVAS[uX][uY] = pixels.Color(
				0, 0, 0);
		uX--;
	}
	if (dX < -256 && uX + 1 < 8)
	{
		CANVAS[uX][uY] = pixels.Color(
				0, 0, 0);
		uX++;
	}

	if (dY > 256 && uY - 1 >= 0)
	{
		CANVAS[uX][uY] = pixels.Color(
				0, 0, 0);
		uY--;
	}
	if (dY < -256 && uY + 1 < 8)
	{
		CANVAS[uX][uY] = pixels.Color(
				0, 0, 0);
		uY++;
	}

	CANVAS[uX][uY] = pixels.Color(
			255, 0, 0);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pixels.setPixelColor((i * 8) + j, CANVAS[i][j]);
			pixels.show();
		}
	}

	delay(2501);
}
