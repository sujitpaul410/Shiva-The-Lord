#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int genRandNum()
{
	int num;

	srand(time(NULL));
	num=rand()%10+1;

	printf("Num is %d\n",num);
	return num;
}