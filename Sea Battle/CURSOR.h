//-----------------------------------------------
//						CURSOR.h - gotoxy 함수 및 커서 HIDE
//-----------------------------------------------

#ifndef _CURSOR_H_
#define _CURSOR_H_

#include <Windows.h>

void gotoxy(int x, int y){
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
void removeCursor(void){ // 커서 깜빡임 제거{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

#endif