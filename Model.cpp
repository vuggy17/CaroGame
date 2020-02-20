//file này giữ các hàm xử lý khi load file
#include "GamePlay.h"

//hàm này khi bắt đầu vào game sẽ reset lại tất cả data
void ResetData(){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2; // Trung voi hoanh do man hinh ban co
            _A[i][j].y = 2 * i + TOP + 1; // Trung voi tung do man hinh ban co
            _A[i][j].c = 0;
            // 0 nghia la chua ai danh dau, neu danh dau phai theo quy                       
            //dinh nhu sau: -1 la luot true danh, 1 là luot false danh
        }
    }
    DrawBorder ((LEFT - 3), (TOP - 1), (4 * BOARD_SIZE + 6), (2 * BOARD_SIZE + 3));  // x,y, width, hieh
    DrawBoard(BOARD_SIZE);
    GotoXY(_X,_Y);
    _TURN = true;
	_COMMAND = -1;// Gan luot ve phim mac dinh
    _X = _A[0][0].x;
	_Y = _A[0][0].y;
}

int ExitGame()
{
	return 0;
}