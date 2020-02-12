#include "menu.h"

Texture2D start, about, exit, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg;

void menuScreen()
{
	DrawTexture(mainImg, 0.0f, 0.0f, WHITE);
	DrawTexture(start, 1024/10, 768/3, WHITE);
	DrawTexture(about, 1024/10, (768/3)+100, WHITE);	
	DrawTexture(exit, 1024/10, (768/3)+200, WHITE);
}


void highlightButton(char* str)
{
	if(str[0]=='s')
	{
		//printf("Changed startButton\ns");
		DrawTexture(startSelected, 1024/10, 768/3, WHITE);
	}
	else if(str[0]=='a')
	{
		DrawTexture(aboutSelected, 1024/10, (768/3)+100, WHITE);
	}
	else
	{
		DrawTexture(exitSelected, 1024/10, (768/3)+200, WHITE);
	}
}


void startGame(Rectangle frame, Rectangle frame1)
{
	fc++;
	Vector2 pos={1024/3, 768/3};
	if(idleState==1)
	{
		frame.x=(float)cf*(float)idle.width/3;
		if(cf>=7)
		{
			cf=0;
			fc=0;
		}
		DrawTextureRec(idle, frame, pos, WHITE);
		if(fc%20==0)
		{
			cf++;
			cf1++;
		}
	}
	if(idleState==0)
	{
		frame1.x=(float)cf1*(float)runImg.width/8;
		if(cf1>=8)
		{
			cf1=0;
			fc=0;
		}
		DrawTextureRec(runImg, frame1, pos, WHITE);
		if(fc%10==0)
		{
			//cf++;
			cf1++;
		}
	}
}
