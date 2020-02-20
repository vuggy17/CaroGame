//file này là nơi bắt đầu game chứ hàm main
#include "GamePlay.h"
using namespace std;

int main(){
    resizeConsole(xSizeConsole,ySizeConsole); //hàm chỉnh kích thước màn hình console theo độ rộng và chiều cao
    FixConsoleWindow();//cố định màn hình console, ko cho kéo chuột lên kéo xuống
    system("cls");
    ResetData();
    DrawBoard(12);
    while(1){
        bool validEnter = true;
        _COMMAND = getch();//nhận giá trị khi bấm phím W A S D hoặc enter, biến này đc khai báo ở Data.cpp
        if (_COMMAND == 27) {
            return 0;
        }
        else{
            if ((_COMMAND == 'A') || (_COMMAND == 'a')) MoveLeft();
			else if ((_COMMAND == 'D') || (_COMMAND == 'd')) MoveRight();
			else if ((_COMMAND == 'W') || (_COMMAND == 'w')) MoveUp();
			else if ((_COMMAND == 'S') || (_COMMAND == 's')) MoveDown();
            else if (_COMMAND == 13){
                //13 là phím enter, người dùng nhấn phím enter thì đánh quân cờ lên bàn cờ
            }
        }
    }
}