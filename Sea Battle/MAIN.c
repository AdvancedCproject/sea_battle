//--------------------------------
//					MAIN.c - 메인 소스
//--------------------------------


#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MAKE_SHIP.h"
#include "SAVE_LOAD.h"
#include "START_INTERFACE.h"
#include "GAME_START.h"
#include "PLAYER_ACT.h"
#include "CURSOR.h"
#include "INFO.h"
#include "KEYBOARD.h"
#include "ITEM.h"

//--------------------------------
//                     MAIN 함수
//--------------------------------
int main(void){
	int key;

	removeCursor();		//커서 깜빡임 지우기
		
	SELECT_MODE();		//모드 선택
	if (FINISH == TRUE) return;
	LOAD();

	system("mode con cols=80 lines=34");
	EXPLAIN();
	getch();
	system("cls");

	if (ITEM_USE == TRUE){
		system("mode con cols=100 lines=24");
		ITEM_EXPLAIN();
		getch();
		system("cls");
	}
	
	if (ITEM_USE == FALSE) system("mode con cols=135 lines=34");
	else if (ITEM_USE == TRUE) system("mode con cols=135 lines=39");
	
	
	system("cls");
	MAP_CREATE();

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");

	MAKE_SHIP_NOTICE(number);

	
	while (1) {
		if (ITEM_USE == TRUE){

			ITEM_NUM();
		}
		key = getch();

		MOVE_PLAYER(key, &p->x, &p->y);
		if (MAKE_SHIP == TRUE) MAKE_SHIP_NOTICE(number);
		if (FINISH == TRUE) return;
	}
	
}