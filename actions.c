#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"

//Texture2D jumptex, fireball;
bool jumplanded = true;
bool fireballextngshd = true;
bool isUP = true;
bool isDown = true;

Vector2 idlepos = { 1024 / 3, 768 / 3 };
float tmpjumpY = 0;

Rectangle playerFrame = { 1024 / 2.3, 768 / 3, 10, 380 };
float jumpspeed = 5.0f;

float fbrot = 0.0f;
Vector2 fpos = { 1024 / 2, 768 / 2 };

void resetjump()
{
	isDown = false;
	isUP = false;
}


void jumpfar(Rectangle frame)
{
	//printf("jumpfar called..\n");
	//DrawRectangleLines(playerFrame.x - 100, playerFrame.y, 236, 380, ORANGE);
	Rectangle rec = { playerFrame.x - 100, playerFrame.y, 236, 380 };

	Vector2 pos = { playerFrame.x - 100,playerFrame.y };
	jumplanded = false;
	//if(isTreeGrounded(rec) && !jumplanded)
	{
		//printf("jumped..\n");
		if (playerFrame.y >= 50 && !jumplanded && !isUP)
		{
			playerFrame.y -= jumpspeed;
			scrollGround();
			checkIsGrounded();
			DrawTextureEx(jumptex, pos, 0.0f, 1.0f, WHITE);
			//printf("player.y = %f\n",playerFrame.y);
			if (playerFrame.y - jumpspeed <= 100)
			{
				isUP = true;
				//printf("UP\n");
			}
		}
		if (isUP && !isDown)
		{
			playerFrame.y += jumpspeed;
			scrollGround();
			checkIsGrounded();
			DrawTextureEx(jumptex, pos, 0.0f, 1.0f, WHITE);
			//printf("player.y = %f\n",playerFrame.y);
			if (playerFrame.y + jumpspeed == 768 / 3)
			{
				isDown = true;
				//printf("Down\n");
			}
		}
		if (isUP && isDown)
		{
			//printf("Complete\n");
			jumplanded = true;
			resetjump();
		}
	}
	DrawTextureEx(jumptex, pos, 0.0f, 1.0f, WHITE);

}


void shoot()
{
	//Vector2 fpos={1024/2, 768/2};
	DrawTextureEx(fireball, fpos, 0.0f, 1.0f, WHITE);
	//DrawRectangleLines(fpos.x, fpos.y, 50, 50, ORANGE);
	Rectangle fballrec = { fpos.x,fpos.y,50,50 };
	fbrot += 1.0f;
	fpos.x += 2.0f;
	if (fbrot >= 360)
	{
		fbrot = 0.0f;
	}
	if (fpos.x >= 1026)
	{
		/*fireballextngshd = true;
		fpos.x = 1024 / 2;*/
		extinguishfball();
	}
	//printf("FireballExtenguished: %d, fpos.x: %f\n",fireballextngshd,fpos.x);
	takedamage(fballrec);
}

void playerdamage(Rectangle enemy)
{
	Rectangle player = { playerFrame.x - 100, playerFrame.y, 236, 380 };
	if (CheckCollisionRecs(player, enemy))
	{
		//printf("Player Dead..\n");
		isenemydead = true;
		blinkState = 4;
	}
}

void extinguishfball()
{
	fireballextngshd = true;
	fpos.x = 1024 / 2;
}