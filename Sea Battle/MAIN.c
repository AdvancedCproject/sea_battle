//--------------------------------
//					MAIN.c - ���� �ҽ�
//--------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "MAKE_SHIP.h"
#include "CURSOR.h"
#include "INFO.h"
#include "KEYBOARD.h"
#include "ITEM.h"


//--------------------------------
//                     MAIN �Լ�
//--------------------------------
int main(void){
	int key;

	removeCursor();		//Ŀ�� ������ �����

	RANDOM_ARRANGE();
	PRINT();
	/*
	SELECT_MODE();		//��� ����

	system("mode con cols=135 lines=34");
	MAP_CREATE();

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("��");

	MAKE_SHIP_NOTICE(number);
	
	while (1) {

		key = getch();

		MOVE_PLAYER(key, &p->x, &p->y);
		if (MAKE_SHIP == TRUE) MAKE_SHIP_NOTICE(number);
	}
	*/
}