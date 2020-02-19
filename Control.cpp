//file này viết các hàm control dùng để di chuyển trên bàn cờ
#include "GamePlay.h"

using namespace std;


void MoveRight()
{
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
        GotoXY(_X,_Y);
	}
}

void MoveLeft()
{
	if (_X > _A[0][0].x) {
		_X -= 4;
        GotoXY(_X,_Y);
	}
	
}

void MoveUp()
{
	if (_Y > _A[0][0].y) {
		_Y -= 2;
        GotoXY(_X,_Y);
	}
}

void MoveDown()
{
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
        GotoXY(_X,_Y);
	}
}
