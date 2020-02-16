#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"

//Texture2D enemy;
bool isenemydead = false;
int score;

Vector2 epos = { 1026,768 / 3 };
Rectangle enemyrec;
double timeintvl = 0.0f, dintrvl = 0.0f;

void spawnenemy(int speed)
{
	if (!isenemydead && speed == 0)
	{
		DrawTextureEx(enemy, epos, 0.0f, 1.0f, WHITE);
		//DrawRectangleLines(epos.x + 50, epos.y, enemy.width - 100, enemy.height, RED);
		Rectangle enemyrect = { epos.x + 50,epos.y,enemy.width - 100, enemy.height };
		enemyrec = enemyrect;
		epos.x -= 0.8f;
		//printf("SpawnEnemy %f\n", epos.x);
	}
	if (!isenemydead && speed == 1)
	{
		DrawTextureEx(enemy, epos, 0.0f, 1.0f, WHITE);
		//DrawRectangleLines(epos.x + 50, epos.y, enemy.width - 100, enemy.height, RED);
		Rectangle enemyrect = { epos.x + 50,epos.y,enemy.width - 100, enemy.height };
		enemyrec = enemyrect;
		epos.x -= 5.0f;
		//printf("SpawnEnemySpeedy %f\n", epos.x);
	}
	if (isenemydead)
	{
		epos.x = 1028;
		enemyrec.x = 1028;
		//printf("Epos reset..\n");
	}
	if (timeintvl > dintrvl && isenemydead)
	{
		//epos.x=1028;
		isenemydead = false;
		timeintvl = 0.0f;
		dintrvl = 0.0f;
	}
	timeintvl++;
	playerdamage(enemyrec);
}

void takedamage(Rectangle fballrec)
{
	if (CheckCollisionRecs(fballrec, enemyrec))
	{
		isenemydead = true;
		//printf("Enemy dead..\n");
		score++;
		extinguishfball();
		dintrvl = 2000.0f;
	}
}