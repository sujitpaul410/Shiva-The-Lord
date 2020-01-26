#include "platform.h"

Texture2D ground, ground1;
Vector2 pos={0.5f,605};
Vector2 pos1={1150,605};

Vector2 tempPos={2300,605};

float px=1024;
float px1=1024;

void setGround(Rectangle frame)
{
	DrawTextureEx(ground, pos, 0.0f, 1.0f, WHITE);
	DrawTextureEx(ground1, pos1, 0.0f, 1.0f, WHITE);
	if(pos1.x<(1150/2))
	{
		if(tempPos.x<=-1024)
		{
			tempPos.x=pos1.x+1024+50;
		}
		if(pos1.x<=-1024)
		{
			pos1.x=tempPos.x+1024+50;
		}
	}
	DrawTextureEx(ground1, tempPos, 0.0f, 1.0f, WHITE);
}

void scrollGround()
{
	pos.x-=0.8f;
	pos1.x-=0.8f;
	tempPos.x-=0.8f;
	DrawTextureEx(ground, pos, 0.0f, 1.0f, WHITE);
	DrawTextureEx(ground1, pos1, 0.0f, 1.0f, WHITE);
	DrawTextureEx(ground1, tempPos, 0.0f, 1.0f, WHITE);
}

float getPlatPos()
{
	printf("pos.x=> %f\n",pos.x);
	return pos.x;
}

bool checkIsGrounded()
{

		/*float platposX=getPlatPos();
		Rectangle platFrame={0.5f, 605, platposX, 0.5f};*/
		DrawRectangle(0.5f, 605, px, 10, RED);
		Rectangle platFrame={0.5f, 605, px, 10.0f};
		DrawRectangle(pos1.x, 605, px1, 10, BLACK);
		//Rectangle platFrame1={1022, 605, pos1.x, 10.0f};
		DrawRectangle(tempPos.x, 605, px1, 10, ORANGE);
		Rectangle platFrame2={tempPos.x, 605, px1, 10, ORANGE};
		Rectangle platFrame1={pos1.x, 605, px1, 10.0f};
		Rectangle playerFrame={1024/2.3, 768/3, 10, 380};

		px-=0.8f;
		//px1-=0.8f;
		//pos1.x-=0.8;
		DrawRectangle(1024/2.3, 768/3, 10, 380, GREEN);
		if(CheckCollisionRecs(platFrame, playerFrame) || CheckCollisionRecs(platFrame1, playerFrame) || CheckCollisionRecs(platFrame2, playerFrame))
		{
			printf("Collided with ground..\n");
			return true;
		}
		else
		{
			printf("Collision failed..\n");
			return false;
		}
}
