#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"


void BlinkStart()
{
	if (posx == -180 && timer <= 180)
	{
		posx = 1024 / 2;
		posy = 768 / 2;
	}
	else if (timer > 180)
	{
		blinkState = 1;
	}
	else
	{
		posx = -180;
		posy = -180;
	}
	timer++;
}
