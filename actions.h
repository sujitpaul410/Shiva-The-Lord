#include "MyIncludes.h"
#include<stdio.h>
#pragma once
extern Texture2D jumptex, fireball;
void jumpfar(Rectangle frame);
void shoot();
extern bool isUP;
extern bool isDown;
void resetjump();
void playerdamage(Rectangle enemy);
void extinguishfball();
