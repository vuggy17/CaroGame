#include "GamePlay.h"

using namespace std;

string name[5], str[2] = { ">>", "<<" };//2 dấu nháy lựa chọn options
int count1 = 1, count2 = 1, count3 = 1;

int startScreen()
{
	system("cls");

	SupportScreen1();

	///////////"               " 51 ---- 54--64
	name[0] =  "New  Game";
	name[1] =  "Load Game";
	name[2] =   "Setting";
	name[3] = "Introduction";
	name[4] =    "Quit";

	printWord(11, 54, 16, name[0]);
	printWord(15, 54, 18, name[1]);
	printWord(15, 55, 20, name[2]);
	printWord(15, 52, 22, name[3]);
	printWord(15, 56, 24, name[4]);
	//in >> <<
	printWord(11, 49, 16, str[0]);
	printWord(11, 66, 16, str[1]);


	return getKeyboard(16, 24, 2, name, 0, 4, 54, 54, 55, 52, 56);// trả về lựa chọn
}


int getKeyboard(int lmUp, int lmDown, int _range, string name[], int first, int last, int x0, int x1,int x2,int x3,int x4)
{
	int x[5] = { x0,x1,x2,x3,x4 };
	//range : do rong giua cac dong
	int y = lmUp, num;
	while (1)
	{
		_COMMAND = _getch();

		if (_COMMAND == 's' || _COMMAND == 'S')
		{
			y += _range;
			if (y > lmDown) y = lmDown;
		}

		else if (_COMMAND == 'w' || _COMMAND == 'W')
		{
			y -= _range;
			if (y < lmUp) y = lmUp;
		}

		else if (_COMMAND == 13)
		{
			return y;
		}

		if (y == lmUp)
		{
			//in >> <<
			printWord(11, 49, y, str[0]);
			printWord(11, 66, y, str[1]);
			//xoa >> <<
			printWord(15, 49, y + _range, "  ");
			printWord(15, 66, y + _range, "  ");

			printWord(11, x[first], y, name[first]);
			printWord(15, x[first + 1], y + _range, name[first + 1]);
		}
		else if (y == lmDown)
		{
			//in >> <<
			printWord(11, 49, y, str[0]);
			printWord(11, 66, y, str[1]);
			//xoa >> <<
			printWord(15, 49, y - _range, "  ");
			printWord(15, 66, y - _range, "  ");

			printWord(15, x[last - 1], y - _range, name[last - 1]);
			printWord(11, x[last], y, name[last]);
		}
		else if (y != lmUp && y != lmDown)
		{
			num = (y - lmUp) / _range;
			//xoa >> <<
			printWord(15, 49, y - _range, "  ");
			printWord(15, 66, y - _range, "  ");
			//in >> <<
			printWord(11, 49, y, str[0]);
			printWord(11, 66, y, str[1]);
			//xoa >> <<
			printWord(15, 49, y + _range, "  ");
			printWord(15, 66, y + _range, "  ");

			printWord(15, x[num - 1], y - _range, name[num - 1]);
			printWord(11, x[num], y, name[num]);
			printWord(15, x[num + 1], y + _range, name[num + 1]);
		}
	}
}
int playScreen(){

    Nocursortype(false);//hàm ẩn con trỏ chuột nhấp nháy trên bàn cờ
    system("cls");
    TextColor(15);
    ResetData();

    while(1){
        bool validEnter = true;//biến kiểm tra xem có được bấm phím enter hay không, trường hợp đánh vào ô đã đánh thì validenter = false -> ko cho enter đánh vào đó
        _COMMAND = getch();//nhận giá trị khi bấm phím W A S D hoặc enter, biến này đc khai báo ở Data.cpp
        if (_COMMAND == 27) {
            return 0;
        }
        else{
            if ((_COMMAND == 'A') || (_COMMAND == 'a')) MoveLeft();
			else if ((_COMMAND == 'D') || (_COMMAND == 'd')) MoveRight();
			else if ((_COMMAND == 'W') || (_COMMAND == 'w')) MoveUp();
			else if ((_COMMAND == 'S') || (_COMMAND == 's')) MoveDown();
            else if (_COMMAND == 13){ //13 là phím enter
                switch (CheckBoard(_X, _Y)){
                    case -1: //_TURN = true, người chơi 1
                        setColorPtr(_X, _Y, 1);
                        cout << player1.playerSymbol;
                        GotoXY(83,23);
                        cout<< player1.playerSymbol;
						GotoXY(83,24);
						cout<<count1++;
						GotoXY(97,9);
						cout<<count3++;
                        GotoXY(_X,_Y);
                        break;
                    case 1: //_TURN = false, người chơi 2
                        setColorPtr(_X, _Y, 1);
                        cout << player2.playerSymbol;
						GotoXY(111,23);
                        cout<< player2.playerSymbol;
						GotoXY(111,24);
						cout<<count2++;
						GotoXY(97,9);
						cout<<count3++;
                        GotoXY(_X,_Y);
                        break;
                    case 0:
                        validEnter = false;
                        break;
                }
                if(validEnter == true){
                    switch(TestBoard()){
                        case -1: 
                            system("cls");
                            cout << player1.playerName << endl; //người chơi 1 thắng
                            //ExitGame();
                            return 0;
                        case 1:
                            system("cls");
                            cout << player2.playerName << endl; //người chơi 2 thắng
                            //ExitGame();
                            return 0;
                        case 0:
                            system("cls");
                            cout << "Hoa" << endl;
                            ExitGame();
                        default:
                            _TURN = !(_TURN); //đổi lượt cho người chơi còn lại
                            break;
                    }
                }
            }
        }
    }
}
void SupportScreen1(){
	TextColor(11);
	GotoXY(39, 3);
	cout << "  .d8888b.           8888888b.   " << endl;
	GotoXY(39, 4);
	cout << " d88P  Y88b          888   Y88b" << endl;
	GotoXY(39, 5);
	cout << " 888    888          888    888" << endl;
	GotoXY(39, 6);
	cout << " 888         8888b.  888   d88P .d88b." << endl;
	GotoXY(39, 7);
	cout << " 888            '88b 8888888P' d88''88b " << endl;
	GotoXY(39, 8);
	cout << " 888    888 .d888888 888 T88b  888  888  " << endl;
	GotoXY(39, 9);
	cout << " Y88b  d88P 888  888 888  T88b Y88..88P" << endl;
	GotoXY(39, 10);
	cout << "  'Y8888P'  'Y888888 888   T88b 'Y88P'" << endl;
	GotoXY(39, 11);
	cout << "________________________________________" << endl;

}