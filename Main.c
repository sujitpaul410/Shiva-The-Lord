#include "MyIncludes.h"
#include "signature.h"
#include "actions.h"
#include "blink.h"
#include "enemy.h"
#include "environment.h"
#include "menu.h"
#include "platform.h"
#define H_DIFF 100
extern int posx = -180, posy = -180, timer = 0, blinkState = 0;
extern int signx = 20, signy = 20;
Texture2D start, about, exitbtn, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg, ground, ground1;
Texture2D tree, tree1, ground2, jumptex, fireball, enemy, back, backSelected, cancel, cancelSelected, resume, resumeSelected;
extern int dbg = 0, cf = 0, idleState = 0, fc = 0, cf1 = 0;
Texture2D water;
Font f;

//-----------
//void BlinkStart();
//void DrawSignature();
//void menuScreen();
//void highlightButton(const char* str);
//void startGame(Rectangle frame, Rectangle frame1);
//void restartgame();

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "https://www.sujitpaul.itch.io");
	Image img = LoadImage("Resources/Images/fireball.png");
	SetWindowIcon(img);

	start = LoadTexture("Resources/Images/Start.png");
	about = LoadTexture("Resources/Images/About.png");
	exitbtn = LoadTexture("Resources/Images/Exit.png");
	startSelected = LoadTexture("Resources/Images/StartSelected.png");
	aboutSelected = LoadTexture("Resources/Images/AboutSelected.png");
	exitSelected = LoadTexture("Resources/Images/ExitSelected.png");
	idle = LoadTexture("Resources/Images/Idle.png");
	mainImg = LoadTexture("Resources/Images/1.png");
	runImg = LoadTexture("Resources/Images/RunAnim.png");
	ground = LoadTexture("Resources/Images/ground1.png");
	ground1 = LoadTexture("Resources/Images/ground1.png");
	tree = LoadTexture("Resources/Images/Tree1.png");
	tree1 = LoadTexture("Resources/Images/Tree2.png");
	ground2 = LoadTexture("Resources/Images/ground2.png");
	water = LoadTexture("Resources/Images/water.png");
	jumptex = LoadTexture("Resources/Images/jump.png");
	fireball = LoadTexture("Resources/Images/fireball.png");
	enemy = LoadTexture("Resources/Images/demon.png");
	f = LoadFont("Resources/Font/MyFont.ttf");
	back = LoadTexture("Resources/Images/back.png");
	backSelected = LoadTexture("Resources/Images/backSelected.png");
	resume = LoadTexture("Resources/Images/resumeN.png");
	resumeSelected = LoadTexture("Resources/Images/resumeSelected.png");
	cancel = LoadTexture("Resources/Images/cancel.png");
	cancelSelected = LoadTexture("Resources/Images/cancelSelected.png");

	Rectangle startBound = { screenWidth / 10, screenHeight / 3, start.width, start.height };
	Rectangle aboutBound = { screenWidth / 10, (screenHeight / 3) + 100, start.width, start.height };
	Rectangle exitBound = { screenWidth / 10, (screenHeight / 3) + 200, start.width, start.height };
	//Rectangle startBound = { 100, 200, start.width, start.height };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle frame = { 0.0f, 0.0f, (float)idle.width / 3, (float)idle.height };
	Rectangle frame1 = { 0.0f, 0.0f, (float)runImg.width / 8, (float)runImg.height };
	jumplanded = true;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
									//--------------------------------------------------------------------------------------
									// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		//DrawFPS(50, 50);

		if (blinkState == 0)
		{
			BlinkStart();
		}
		else if (blinkState == 1)
		{
			DrawSignature();
		}
		else if (blinkState == 2)
		{
			posx = -180;
			posy = -180;
			menuScreen();
			mousePoint = GetMousePosition();
			if (CheckCollisionPointRec(mousePoint, startBound))
			{
				//printf("Mouse over button %d\n",dbg++);
				highlightButton("start");
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					blinkState = 3;
				}
			}
			if (CheckCollisionPointRec(mousePoint, aboutBound))
			{
				//printf("Mouse over button %d\n",dbg++);
				highlightButton("about");
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					blinkState = 5;
				}
			}
			if (CheckCollisionPointRec(mousePoint, exitBound))
			{
				//printf("Mouse over button %d\n",dbg++);
				highlightButton("exit");
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					return 0;
				}
			}
		}
		else if (blinkState == 3)
		{
			displayscore();
			setGround();
			spawnenemy(0);
			if (IsKeyDown(KEY_W) && !IsKeyPressed(KEY_SPACE) && jumplanded)
			{
				idleState = 0;
				//printf("KeyDownDetected..\n");
				scrollGround();
				spawnenemy(1);
				startGame(frame, frame1);
				if (!checkIsGrounded())
				{
					//printf("You Died..\n");
					//return;
					blinkState = 4;
				}
				if (!fireballextngshd)
				{
					shoot();
				}
				//jump(frame);	
			}
			else if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_SPACE) && jumplanded)
			{
				idleState = 0;
				//startGame(frame, frame1);
				jumpfar(frame);
				if (!checkIsGrounded())
				{
					//printf("You Died..\n");
					//return;
					blinkState = 4;
				}
				if (!fireballextngshd)
				{
					shoot();
				}
				//jump(frame);	
			}
			else if (IsKeyPressed(KEY_SPACE) || !jumplanded)
			{
				jumpfar(frame);
				spawnenemy(1);
				idleState = 3;
				if (!fireballextngshd)
				{
					shoot();
				}
			}
			else if (IsKeyPressed(KEY_D) || !fireballextngshd)
			{
				idleState = 1;
				startGame(frame1, frame);
				fireballextngshd = false;
				shoot();
			}
			else
			{
				/*if(!isenemydead)
				{
				spawnenemy();
				}*/
				if (jumplanded)
				{
					idleState = 1;
					resetjump();
					startGame(frame, frame1);
				}
			}
		}
		else if (blinkState == 4)
		{
			restartgame();
		}
		else if (blinkState == 5)
		{
			//printf("About..\n");
			displayabout();
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BEIGE);
		DrawRectangle(posx, posy, 20, 20, BLACK);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}

void displayscore()
{
	DrawText("Score: ", 1024 - 150, 20, 30, GREEN);
	char str[10];
	//_itoa_s(score, str, 10);
	snprintf(str,10,"%d",score);
	DrawText(str, (1024 - 150) + 110, 20, 30, GREEN);

}





