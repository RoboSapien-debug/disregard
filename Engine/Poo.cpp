#include "Poo.h"
#include "Graphics.h"
#include "Dude.h"


void Poo::Update()
{
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x= (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y= (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}

void Poo::ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight)
{
	const int rightdude = dudex + dudewidth;
	const int bottomdude = dudey + dudeheight;
	const int rightpoo = x + width;
	const int bottompoo = y + height;

	if(rightdude >= x &&
		dudex <= rightpoo &&
		bottomdude >= y &&
		dudey <= bottompoo)
	{
		isEaten = true;
	}
}
