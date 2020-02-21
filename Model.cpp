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
	player1 = { "Player_One", "X" };
	player2 = { "Player_Two", "O" };
	DrawBoard(BOARD_SIZE);
    DrawBorder ((LEFT - 3), (TOP - 1), (4 * BOARD_SIZE + 6), (2 * BOARD_SIZE + 3));  // x,y, width, hight hàm này vẽ khung bên trái
	DrawBorder_1(70,2,54,27);// hàm này vẽ khung bên phải
    _TURN = true;
	_COMMAND = -1;// Gan luot ve phim mac dinh
    _X = _A[0][0].x;
	_Y = _A[0][0].y;
	GotoXY(_X,_Y);
}

//ham kiem tra luot nguoi choi khi nhan ENTER de danh dau
int CheckBoard(int pX, int pY){
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 0 && _A[i][j].x == pX && _A[i][j].y == pY) {
				if (_TURN) {
					_A[i][j].c = -1; // neu luot hien hanh la true thi c = -1
				}
				else {
					_A[i][j].c = 1;//neu luot hien hanh la false thi c = 1
				}
				return _A[i][j].c;
			}
			if (_A[i][j].c != 0 && _A[i][j].x == pX && _A[i][j].y == pY)
			{
				return 0; //đánh vào vị trí đã đánh thì ko được
			}
		}
	}
	return 0;
}

int TestBoard(){
	if(WinGame())//<- hàm win game truyền vào đây WinGame(), WinGame là hàm check thắng thua
		return (_TURN) ? -1 : 1;
	else if (BoardFull())//<- hàm BoardFull() kiểm tra ma trận đầy, cái này t làm
		return 0;
	else
		return 2;//nếu chưa ai thắng thua hay ma trận chưa đầy
}

int WinGame(){
	//Viết check thắng thua vào đây
	return 0;
}
int BoardFull(){
	//Viết ktra ma trận đầy vào đây
	return 0;
}

int ExitGame()
{
	return 0;
}