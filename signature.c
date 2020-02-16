#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"
#define H_DIFF1 100

void DrawSignature()
{

	if (signx <= 100)
	{
		DrawRectangle(posx - 100, posy, signx, 20, BLACK);
		DrawRectangle(posx - 100, posy + 100, signx, 20, BLACK);

		DrawRectangle(posx + H_DIFF1, posy, signx, 20, BLACK);
	}
	if (signy <= 100)
	{
		DrawRectangle(posx - 100, posy, 20, signy, BLACK);
		DrawRectangle(posx, posy + 100, 20, signy, BLACK);

		DrawRectangle(posx + H_DIFF1 + 100, posy, 20, signy, BLACK);
	}
	if (signx <= 200)
	{
		DrawRectangle(posx + H_DIFF1, posy, 20, signy, BLACK);
		signx++; signy++;
	}
	if (signy > 100 && signy > 100)
	{
		DrawRectangle(posx - 100, posy, 100, 20, BLACK);
		DrawRectangle(posx - 100, posy, 20, 100, BLACK);
		DrawRectangle(posx - 100, posy + 100, 110, 20, BLACK);
		DrawRectangle(posx, posy + 100, 20, 100, BLACK);
		DrawRectangle(posx - 100, posy + 200, 100, 20, BLACK);
		DrawRectangle(posx, posy + 200, 20, 20, BLACK);

		DrawRectangle(posx, posy, 20, 60, BLACK);
		DrawRectangle(posx - 100, posy + 140, 20, 60, BLACK);

		DrawRectangle(posx + H_DIFF1, posy, 100, 20, BLACK);
		DrawRectangle(posx + H_DIFF1, posy, 20, 200, BLACK);
		DrawRectangle(posx + H_DIFF1 + 100, posy, 20, 100, BLACK);
		DrawRectangle(posx + H_DIFF1, posy + 100, 120, 20, BLACK);

		DrawText("https://www.sujitpaul.itch.io", posx + 100, posy + 220, 25, BLACK);
	}
	if (timer >= 450)
	{
		blinkState = 2;
	}
	timer++;
}
