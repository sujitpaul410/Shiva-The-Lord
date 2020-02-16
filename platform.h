#include "MyIncludes.h"
#pragma once
extern Texture2D ground, ground1, ground2;
void setGround();
void scrollGround();

float getPlatPos();
bool checkIsGrounded();
bool isTreeGrounded(Rectangle rec);