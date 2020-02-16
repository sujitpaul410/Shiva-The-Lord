#include "MyIncludes.h"
#pragma once
extern Texture2D start, about, exitbtn, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg, back, backSelected, cancel, cancelSelected, resume, resumeSelected;
void menuScreen();

void highlightButton(const char* str);

void startGame(Rectangle frame, Rectangle frame1);

void restartgame();
void displayabout();
extern Font f;
