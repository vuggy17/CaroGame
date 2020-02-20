#ifndef _DATA
#define _DATA

#include "GamePlay.h"
using namespace std;

#define BOARD_SIZE 12 // kích thước bàn cờ
#define LEFT 5
#define TOP 3
#define xSizeConsole 2000
#define ySizeConsole 600
extern bool _TURN;
extern int _COMMAND;
extern int _X;
extern int _Y;
struct _POINT
{
	int x, y, c;
};
struct _PLAYERINFO
{
	string playerName;
	string playerSymbol;
};
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern _PLAYERINFO player1,player2;// người chơi 1 và người chơi 2

#endif
