#include "GamePlay.h"
using namespace std;

int main(){
    resizeConsole(xSizeConsole,ySizeConsole); //hàm chỉnh kích thước màn hình console theo độ rộng và chiều cao
    FixConsoleWindow();//cố định màn hình console, ko cho kéo chuột lên kéo xuống
    system("cls");
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
                        cout << player1.playerSymbol;
                        break;
                    case 1: //_TURN = false, người chơi 2
                        cout << player2.playerSymbol;
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
                            ExitGame();
                        case 1:
                            system("cls");
                            cout << player2.playerName << endl; //người chơi 2 thắng
                            ExitGame();
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