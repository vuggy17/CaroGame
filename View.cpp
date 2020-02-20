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

//hàm vẽ khung
void DrawBorder (int x, int y, int width, int height){
	//vẽ góc trái trên
		GotoXY(x - 1,y - 1);
		cout<<static_cast<char>(218);
		//vẽ góc trái dưới
		GotoXY(x - 1, y + height + 1);
		cout<<static_cast<char>(192);
		//vẽ góc phải trên
		GotoXY(x + 1 + width, y - 1);
		cout<<static_cast<char>(191);
		//vẽ góc phải dưới
		GotoXY(x + 1 + width, y + height + 1);
		cout<<static_cast<char>(217);

	for(int i = 0; i <= width; i++){
	//vẽ viền khung bên trên
		GotoXY(x + i, y - 1);
		cout<<static_cast<char>(196);
	//vẽ viên khung bên dưới
		GotoXY(x + i, y + height + 1);
		cout<<static_cast<char>(196);
		}

	for(int i = 0; i <= height; i++){
	//vẽ viên khung bên trái
		GotoXY(x - 1, y + i);
		cout<<static_cast<char>(179);
	//vẽ viền khung bên phải
		GotoXY(x + width + 1, y + i);
		cout<<static_cast<char>(179);
	}
}

//Hàm vẽ bàn cờ
void DrawBoard(int pSize){
	for(int i = 0; i<= pSize; i++){
		for (int  j = 0; j <= pSize; j++)
		{
			GotoXY(LEFT + 4*i, TOP + 2*j);
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