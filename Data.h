#ifndef _DATA
#define _DATA

#include "GamePlay.h"
using namespace std;

#define BOARD_SIZE 12
#define LEFT 5
#define TOP 3
#define xSizeConsole 1000
#define ySizeConsole 600
extern bool _TURN;
extern int _COMMAND;
extern int _X;
extern int _Y;
struct _POINT
{
	int x, y, c;
};


extern _POINT _A[BOARD_SIZE][BOARD_SIZE];

#endif
