#include<raylib.h>
#include<stdlib.h>
#pragma once

extern int posx, posy, timer, blinkState;
extern int signx, signy;
//extern Texture2D start, about, exit, startSelected, aboutSelected, exitSelected, idle, mainImg, runImg;
extern int dbg, cf, idleState, fc, cf1;
extern bool jumplanded;
extern bool fireballextngshd;
extern bool isenemydead;
int genRandNum();
extern int score;
void displayscore();