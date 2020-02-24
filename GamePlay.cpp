#include "GamePlay.h"
using namespace std;


int main() {
    resizeConsole(xSizeConsole, ySizeConsole);
    FixConsoleWindow();
    TextColor(15);
    Nocursortype(true);//hàm ẩn con trỏ chuột nhấp nháy trên bàn cờ
    system("cls");

    //lua chon o man hinh start
    switch (startScreen())
    {
    case 16:
        //new game
        playScreen();
        break;
    case 18:
        //load
        //chức năng load game
    case 20:
        //setting
        //chức năng cài đặt
        // break;
    case 22:
        //introduction
        //giới thiệu vê game
        // break;
    case 24:
        //Quit
        return 0;
        break;
    }
}