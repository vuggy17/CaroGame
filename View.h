#ifndef VIEW
#define VIEW

#include "GamePlay.h"
using namespace std;

void resizeConsole(int width, int height);
void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int x);
void DrawBoard(int pSize);
void DrawBorder (int x, int y, int width, int height);
void DrawBorder_1 (int x, int y, int width, int height);
void printWord(int Color, int x, int y, string name);
void Nocursortype(bool isHide);

#endif
