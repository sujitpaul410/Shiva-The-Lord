#include "MyIncludes.h"
#define H_DIFF 100
extern int posx=-180,posy=-180,timer=0,blinkState=0;
extern int signx=20,signy=20;
Texture2D start, about, exit, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg, ground, ground1;
Texture2D tree, tree1, ground2,jumptex, fireball;
extern int dbg=0, cf=0, idleState=0, fc=0, cf1=0;
Texture2D water;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "https://www.sujitpaul.itch.io");

	start=LoadTexture("Resources/Images/Start.png");
	about=LoadTexture("Resources/Images/About.png");
	exit=LoadTexture("Resources/Images/Exit.png");
	startSelected=LoadTexture("Resources/Images/StartSelected.png");
	aboutSelected=LoadTexture("Resources/Images/AboutSelected.png");
	exitSelected=LoadTexture("Resources/Images/ExitSelected.png");
	idle=LoadTexture("Resources/Images/Idle.png");
	mainImg=LoadTexture("Resources/Images/1.png");
	runImg=LoadTexture("Resources/Images/RunAnim.png");
	ground=LoadTexture("Resources/Images/ground1.png");
	ground1=LoadTexture("Resources/Images/ground1.png");
	tree=LoadTexture("Resources/Images/Tree1.png");
	tree1=LoadTexture("Resources/Images/Tree2.png");
	ground2=LoadTexture("Resources/Images/ground2.png");
	water=LoadTexture("Resources/Images/water.png");
	jumptex=LoadTexture("Resources/Images/jump.png");
	fireball=LoadTexture("Resources/Images/fireball.png");

	Rectangle startBound = { screenWidth/10, screenHeight/3, start.width, start.height };
	Rectangle aboutBound = { screenWidth/10, (screenHeight/3)+100, start.width, start.height };
	Rectangle exitBound = { screenWidth/10, (screenHeight/3)+200, start.width, start.height };
	//Rectangle startBound = { 100, 200, start.width, start.height };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle frame={0.0f, 0.0f, (float)idle.width/3, (float)idle.height};
	Rectangle frame1={0.0f, 0.0f, (float)runImg.width/8, (float)runImg.height};
	jumplanded=true;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

	if(blinkState==0)
	{
		BlinkStart();
	}
	else if(blinkState==1)
	{
		DrawSignature();
	}
	else if(blinkState==2)
	{
		posx=-180;
		posy=-180;
		menuScreen();
		mousePoint = GetMousePosition();
		if (CheckCollisionPointRec(mousePoint, startBound))
        	{
			//printf("Mouse over button %d\n",dbg++);
			highlightButton("start");
			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			{
				blinkState=3;
			}
        	}
		if (CheckCollisionPointRec(mousePoint, aboutBound))
        	{
			//printf("Mouse over button %d\n",dbg++);
			highlightButton("about");
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
	else if(blinkState==3)
	{
		setGround();
		if(IsKeyDown(KEY_W) && !IsKeyPressed(KEY_SPACE) && jumplanded)
		{
			idleState=0;
			//printf("KeyDownDetected..\n");
			scrollGround();
			startGame(frame, frame1);
			if(!checkIsGrounded())
			{
				//printf("You Died..\n");
				//return;
			}
			if(!fireballextngshd)
			{
				shoot();
			}
			//jump(frame);	
		}
		else if(IsKeyDown(KEY_W) && IsKeyPressed(KEY_SPACE) && jumplanded)
		{
			idleState=0;
			//startGame(frame, frame1);
			jumpfar(frame);
			if(!checkIsGrounded())
			{
				//printf("You Died..\n");
				//return;
			}
			if(!fireballextngshd)
			{
				shoot();
			}
			//jump(frame);	
		}
		else if(IsKeyPressed(KEY_SPACE) || !jumplanded)
		{
			jumpfar(frame);
			idleState=3;
			if(!fireballextngshd)
			{
				shoot();
			}
		}
		else if(IsKeyPressed(KEY_D) || !fireballextngshd)
		{
			idleState=1;
			startGame(frame1, frame);
			fireballextngshd=false;
			shoot();
		}
		else
		{
			if(jumplanded)
			{
				idleState=1;
				resetjump();
				startGame(frame, frame1);
			}
		}
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





