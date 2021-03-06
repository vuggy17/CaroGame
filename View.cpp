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
//khung bên trái
void DrawBorder(int x, int y, int width, int height){
	//vẽ góc trái trên
		TextColor(11);
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
//khung bên phải
void DrawBorder_1(int x, int y, int width, int height){
	//vẽ góc trái trên
		TextColor(11);
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
	// vẽ đường ngang chính giữa
	for(int i = 0; i <= width; i++){
		GotoXY(70 + i,14);
		cout<<static_cast<char>(196);
	}
	//vẽ dấu nối chính giữa,bên trái
	GotoXY(69,14);
	cout<<static_cast<char>(195);
	//vẽ dấu nối chính giữa bên phải
	GotoXY(125,14);
	cout<<static_cast<char>(180);
	//vẽ dấu nối chính giữa bên trên
	GotoXY(97,14);
	cout<<static_cast<char>(194);
	//vẽ dấu nối chính giữa bên dưới
	GotoXY(97,30);
	cout<<static_cast<char>(193);
	GotoXY(89,8);
	cout<<"Tong so buoc da di";
	
	for(int i = 0; i <= 14; i++){
	//vẽ đường chính giữa khung dưới
		GotoXY(97, 15 + i);
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

//hàm tô màu
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

//hàm ẩn con trỏ nhấp nháy trên màn hình , nguon tham khao: https://daynhauhoc.com/t/an-con-tro-chuot-tren-man-hinh-console/34411
void Nocursortype(bool isHide)
{
	
		CONSOLE_CURSOR_INFO Info;
		Info.bVisible = !isHide;
		Info.dwSize = 20;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
	
}

//hàm hỗ trợ rút gọn code goto xy, set màu
void printWord(int Color, int x, int y, string name)
{
	TextColor(Color);
	GotoXY(x, y);
	cout << name;
}

//hàm hỗ trợ tô màu con trỏ nhấp nháy trên bàn cờ
void setColorPtr(int x, int y, int value){
	int i,j,ex = 0;

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].x == x && _A[i][j].y == y)
			{
				ex = 1;
				break;
			}
		}
		if (ex == 1) break;
	}

	if (_A[i][j].c == 0) TextColor(15);
	else if (_A[i][j].c == 1) TextColor(10);
	else TextColor(12);

	if (value)
	{
		char topLeft = 201, topCenter = 205, topRight = 187, bottomLeft = 200, bottomRight = 188, bottomCenter = 205, rightCenter = 186, leftCenter = 186;
		GotoXY(LEFT + 4 * j, TOP + 2 * i);
		cout << topLeft << topCenter << topCenter << topCenter;

		GotoXY(LEFT + 4 * j, TOP + 2 * i + 1);
		cout << leftCenter;

		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * i);
		cout << topRight;
		GotoXY(LEFT + 4 * j, TOP + 2 * (i + 1));
		cout << bottomLeft << bottomCenter << bottomCenter << bottomCenter;
		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * (i + 1));
		cout << bottomRight;

		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * i + 1);
		cout << rightCenter;
	}
	else
	{
		TextColor(15);
		GotoXY(LEFT + 4 * j, TOP + 2 * i);
		cout << ".   ";

		GotoXY(LEFT + 4 * j, TOP + 2 * i + 1);
		cout << " ";

		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * i);
		cout << ".";
		GotoXY(LEFT + 4 * j, TOP + 2 * (i + 1));
		cout << ".   ";
		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * (i + 1));
		cout <<".";

		GotoXY(LEFT + 4 * (j + 1), TOP + 2 * i + 1);
		cout << " ";

	}
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}