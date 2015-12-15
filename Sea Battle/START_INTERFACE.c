//--------------------------------------------------------
//				START_INTERFACE.c - 시작 시 메뉴 선택 인터페이스와 맵 생성
//--------------------------------------------------------
#include <Windows.h>
#include "START_INTERFACE.h"
#include "KEYBOARD.h"
#include "INFO.h"


//-------------------------------------------
//                            DRAW MAP / INTERFACE
//-------------------------------------------
void SELECT_MENU(int Player){

	if (Player == 0){
		gotoxy(22, 8); printf("┏━━━━━┓");
		gotoxy(22, 12); printf("    SELECT ");//printf("     SINGLE PLAYER  ");
		gotoxy(22, 16); printf("┗━━━━━┛");
		gotoxy(42, 10); printf("                                 ");
		gotoxy(42, 10);  printf("1.  Single Player");
		gotoxy(42, 12); printf("                                 ");
		gotoxy(42, 12); printf("2.  Custom Player");
		gotoxy(42, 14); printf("                                 ");
		gotoxy(42, 14); printf("3.  How To Play");
	}

	if (Player != 0){
		if (Player == 1){
			gotoxy(22, 12); printf("                      ");
			gotoxy(22, 12); printf("    SINGLE");
		}
		else if (Player == 2){
			gotoxy(22, 12); printf("                      ");
			gotoxy(22, 12); printf("     Custom");
		}

		gotoxy(42, 10); printf("                                      ");

		gotoxy(42, 10); printf("1.  NOMAL MODE");
		gotoxy(42, 12); printf("                                      ");
		gotoxy(42, 12); printf("2.  ITEM MODE");
		gotoxy(42, 14); printf("                                      ");
		gotoxy(42, 14); printf("3.  CANCLE");

	}
}


//------------------------------------------
//                         GAME START
//------------------------------------------
void GAME_START_INIT(){
	p = &p1;
	PLAYER_WHO = &PLAYER2_MAP;

	p1.x = 16; p1.y = 4;

	system("cls");

	system("mode con cols=88 lines=16");

	printf("\n\n\n\n");
	printf(" ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n");
	printf(" ＊■■■■＊■■■■＊■■■■■＊■■■＊■■■■＊■■■＊■■■■＊■■■＊■■■＊\n");
	printf(" ＊■＊＊＊＊■＊＊■＊■＊■＊■＊■＊＊＊■＊＊＊＊＊■＊＊■＊＊■＊■＊■＊＊■＊＊\n");
	printf(" ＊■＊■■＊■■■■＊■＊■＊■＊■■■＊■■■■＊＊■＊＊■■■■＊■■■■＊■＊＊\n");
	printf(" ＊■＊＊■＊■＊＊■＊■＊■＊■＊■＊＊＊＊＊＊■＊＊■＊＊■＊＊■＊■＊＊■＊■＊＊\n");
	printf(" ＊■■■■＊■＊＊■＊■＊■＊■＊■■■＊■■■■＊＊■＊＊■＊＊■＊■＊＊■＊■＊＊\n");
	printf(" ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n");

	Sleep(2000);

	system("cls");
	//system("mode con cols=160 lines=34");
	system("mode con cols=135 lines=34");
	MAP_CREATE();

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");
	
}

//----------------------------------------
//                            SELECT_MODE
//----------------------------------------
void SELECT_MODE(){
	int key, x = 37, y = 10;
	BOOL PRESS = FALSE;
	char *SELECT = "▶";
	int SHAPE_SEL = 0;

	int What_Mode = 0;

	system("mode con cols=90 lines=18");
	printf(" ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n");
	printf(" ＊■■■■＊■■■■＊■■■■＊■■■■＊＊■■■■＊■■■＊■■■＊■＊＊＊■■■■＊\n");
	printf(" ＊■＊＊＊＊■＊＊＊＊■＊＊■＊■＊＊＊■＊■＊＊■＊＊■＊＊＊■＊＊■＊＊＊■＊＊＊＊\n");
	printf(" ＊■■■■＊■■■■＊■■■■＊■■■■＊＊■■■■＊＊■＊＊＊■＊＊■＊＊＊■■■■＊\n");
	printf(" ＊＊＊＊■＊■＊＊＊＊■＊＊■＊■＊＊＊■＊■＊＊■＊＊■＊＊＊■＊＊■＊＊＊■＊＊＊＊\n");
	printf(" ＊■■■■＊■■■■＊■＊＊■＊■■■■＊＊■＊＊■＊＊■＊＊＊■＊＊■■■＊■■■■＊\n");
	printf(" ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n");

	SELECT_MENU(0);
	gotoxy(x, y); puts(SELECT);

	while (1){
		key = getch();

		switch (key){
		case UP:
			if (y >= 12){
				gotoxy(x, y); printf("  "); y -= 2;
				gotoxy(x, y); puts(SELECT);
			}
			break;


		case DOWN:
			if (y <= 12){
				gotoxy(x, y); printf("  "); y += 2;
				gotoxy(x, y); puts(SELECT);
			}
			break;

		case SPACEBAR:
			if (PRESS == FALSE){
				PRESS = TRUE;
				if (y == 10) SELECT_MENU(1);					//SINGLE 플레이어
				else if (y == 12) SELECT_MENU(2);			//CUSTOM 플레이어
				else if (y == 14) SELECT_MENU(0);
			}
			else{
				if (y == 10){ system("cls"); return; }		// NOMAL 모드 실행
				else if (y == 12){}										// ITEM 모드 실행
				else{ SELECT_MENU(0); PRESS = FALSE; }
			}
			break;
		}
	}
}

//----------------------------------------
//                            MAP_CREATE
//----------------------------------------
void MAP_CREATE() {
	int i = 0;

	gotoxy(0, 0);	printf("┏    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┓          ┏    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┳    ┓");
	gotoxy(0, 3);  printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 6);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 9);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 12);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 15);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 18);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 21);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 24);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 27);	printf("┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫          ┣    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ╋    ┫");
	gotoxy(0, 30);	printf("┗    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┛          ┗    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┻    ┛");
	gotoxy(0, 31);	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(0, 33);	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	for (i = 0; i < 31; i++) {
		gotoxy(64, i); printf("┃■┃");
	}
}