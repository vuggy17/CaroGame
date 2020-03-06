//file này viết các hàm control dùng để di chuyển trên bàn cờ
#include "GamePlay.h"

using namespace std;


void MoveRight()
{
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		setColorPtr(_X, _Y,0);
		_X += 4;
		setColorPtr(_X, _Y,1);
	}
}

void MoveLeft()
{
	if (_X > _A[0][0].x) {
		setColorPtr(_X, _Y,0);
		_X -= 4;
		setColorPtr(_X, _Y,1);
	}
	
}

void MoveUp()
{
	if (_Y > _A[0][0].y) {
		setColorPtr(_X, _Y,0);
		_Y -= 2;
		setColorPtr(_X, _Y,1);
	}
}

void MoveDown()
{
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		setColorPtr(_X, _Y,0);
		_Y += 2;
		setColorPtr(_X, _Y,1);
	}
}
