//file này vẽ bàn cờ
#include "GamePlay.h"

//ham co dinh man hinh console
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Set lại độ rộng và chiều cao màn hình console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//Hàm vẽ bàn cờ
void DrawBoard(int pSize){
	for(int i = 0; i<= pSize; i++){
		for (int  j = 0; j <= pSize; j++)
		{
			GotoXY(LEFT + 4*i, TOP + 2*i);
			printf(".");
		}
		
	}
}

//ham di chuyen con tro
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}