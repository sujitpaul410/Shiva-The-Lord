#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"

//Texture2D tree, tree1, water;
Vector2 treePos = { 512, 180 };
float minDist = 230.00f;
int numTrees = 0;
float tmpxpos;

Vector2 waterpos = { 0.5, 605 };
float treedist = 5.0f;

void setTrees()
{
	setWater();
	if (numTrees == 0)
		numTrees = genRandNum();
	for (int i = 0; i < numTrees; i++)
	{
		//tmpxpos+=(treePos.x+minDist);
		tmpxpos += minDist;
		//printf("Teesposx = %f\n",treePos.x);
		//printf("tmpxpos%d = %f\n",i,tmpxpos);
		Vector2 tmp = { tmpxpos + minDist,180 };
		if (i % 2 == 0)
		{
			//DrawTextureEx(tree, tmp, 0.0f, 1.0f, WHITE);
			//DrawRectangle(tmp.x + 80, tmp.y + 380, 20, 100, BLACK);
			Rectangle rec = { tmp.x + 80, tmp.y + 380, 20, 100 };
			if (isTreeGrounded(rec))
			{
				DrawTextureEx(tree, tmp, 0.0f, 1.0f, WHITE);
				//printf("%2 Tree placed..\n");
			}
		}
		else
		{
			Vector2 tree1pos = { tmp.x,180 + 80 };
			//DrawTextureEx(tree1, tree1pos, 0.0f, 1.0f, WHITE);
			//DrawRectangle(tree1pos.x + 80, tree1pos.y + 340, 20, 100, GREEN);
			Rectangle rec = { tree1pos.x + 80, tree1pos.y + 340, 20, 100 };
			//printf("Collision in !%2 is %d\n",isTreeGrounded(rec));
			if (isTreeGrounded(rec))
			{
				DrawTextureEx(tree1, tree1pos, 0.0f, 1.0f, WHITE);
				//printf("!%2 Tree placed..\n");
			}
		}
	}
	tmpxpos = treePos.x;
	DrawTextureEx(tree, treePos, 0.0f, 1.0f, WHITE);
	//DrawRectangle(treePos.x + 80, treePos.y + 380, 20, 100, BLUE);
}

void scrollTrees()
{
	treePos.x -= treedist;
	if (treePos.x + (minDist*numTrees) <= -280.00)
	{
		numTrees = 0;
		treePos.x = 1024;
	}
}

void setWater()
{
	DrawTextureEx(water, waterpos, 0.0f, 1.0f, WHITE);
}
