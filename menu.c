#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"

//Texture2D start, about, exit, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg;

void menuScreen()
{
	DrawTexture(mainImg, 0.0f, 0.0f, WHITE);
	DrawTexture(start, 1024 / 10, 768 / 3, WHITE);
	DrawTexture(about, 1024 / 10, (768 / 3) + 100, WHITE);
	DrawTexture(exitbtn, 1024 / 10, (768 / 3) + 200, WHITE);
}


void highlightButton(const char* str)
{
	if (str[0] == 's')
	{
		//printf("Changed startButton\ns");
		DrawTexture(startSelected, 1024 / 10, 768 / 3, WHITE);
	}
	else if (str[0] == 'a')
	{
		DrawTexture(aboutSelected, 1024 / 10, (768 / 3) + 100, WHITE);
	}
	else
	{
		DrawTexture(exitSelected, 1024 / 10, (768 / 3) + 200, WHITE);
	}
}


void startGame(Rectangle frame, Rectangle frame1)
{
	fc++;
	Vector2 pos = { 1024 / 3, 768 / 3 };
	if (idleState == 1)
	{
		frame.x = (float)cf*(float)idle.width / 3;
		if (cf >= 7)
		{
			cf = 0;
			fc = 0;
		}
		DrawTextureRec(idle, frame, pos, WHITE);
		if (fc % 20 == 0)
		{
			cf++;
			cf1++;
		}
	}
	if (idleState == 0)
	{
		frame1.x = (float)cf1*(float)runImg.width / 8;
		if (cf1 >= 8)
		{
			cf1 = 0;
			fc = 0;
		}
		DrawTextureRec(runImg, frame1, pos, WHITE);
		if (fc % 10 == 0)
		{
			//cf++;
			cf1++;
		}
	}
}

void restartgame()
{
	score = 0;
	Vector2 rpos = { 1024 / 4,768 / 2 };
	//DrawText("GAME OVER..", rpos.x, rpos.y - 150.0f, 100, RED);
	Vector2 txtpos = { rpos.x - 100,rpos.y - 150 };
	DrawTextEx(f, "Game Paused; Since Shiva can't die..watch your move\nClick \"Resume\" to play..!!\t\t\tClick \"X\" to go back to Main Menu..", txtpos, 40, 2.0f, BLACK);
	DrawTextureEx(resume, rpos, 0.0f, 1.0f, WHITE);
	Vector2 cnclpos = { rpos.x + 250,rpos.y };
	DrawTextureEx(cancel, cnclpos, 0.0f, 1.0f, WHITE);
	//DrawRectangleLines(rpos.x, rpos.y, resume.width, resume.height, RED);
	//DrawRectangleLines(rpos.x + 250, rpos.y, cancel.width, cancel.height, RED);
	Rectangle restartrec = { rpos.x,rpos.y,resume.width,resume.height };
	Rectangle cancelrec = { rpos.x + 250,rpos.y,cancel.width,cancel.height };
	if (CheckCollisionPointRec(GetMousePosition(), restartrec))
	{
		DrawTextureEx(resumeSelected, rpos, 0.0f, 1.0f, WHITE);
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			blinkState = 3;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), cancelrec))
	{
		DrawTextureEx(cancelSelected, cnclpos, 0.0f, 1.0f, WHITE);
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			blinkState = 2;
		}
	}
}

void displayabout()
{
	//DrawRectangleLines(1024 / 10, 768 / 3, 800, 400, RED);
	Vector2 v = { 1024 / 10,768 / 3 };
	//DrawText("Shiva: The Lord is a 2D infinite runner game, developed using Raylib\nframework in C language.\n\nPress \"W\" to move, \"D\" to fire and \"SPACE\" to jump.", 1024 / 10, 768 / 3, 25, BLACK);
	DrawTextEx(f, "Shiva: The Lord is a 2D infinite runner game, developed using Raylib\nframework in C language.\n\nPress \"W\" to move, \"d\" to fire and \"SPACE\" to jump.", v, 40, 2.0f, BLACK);
	v.y += 300;
	DrawTextEx(f, "Thank you for trying the game..\n\t\t\tWith Love,\n\t\t\tSujit Paul", v, 40, 2.0f, BLACK);
	//DrawRectangleLines(1024 / 10, 768 / 5, 80, 80, RED);
	Rectangle bckbtnrec = { 1024 / 10, 768 / 5, 80, 80 };
	Vector2 bckpos = { 1024 / 10,768 / 5 };
	DrawTextureEx(back, bckpos, 0.0f, 1.0f, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), bckbtnrec))
	{
		DrawTextureEx(backSelected, bckpos, 0.0f, 1.0f, WHITE);
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			blinkState = 2;
		}
	}
}
