//--------------------------------------------------------
//				START_INTERFACE.c - 시작 시 메뉴 선택 인터페이스와 맵 생성
//--------------------------------------------------------
#include <Windows.h>
#include <stdio.h>
#include "START_INTERFACE.h"
#include "KEYBOARD.h"
#include "ITEM.h"
#include "INFO.h"


//-------------------------------------------
//                            DRAW MAP / INTERFACE
//-------------------------------------------
void SELECT_MENU(int Player){
	

	if (Player == 0){
		gotoxy(22, 8); printf("┏━━━━━┓");
		gotoxy(22, 12); printf("    SELECT ");            
		gotoxy(22, 16); printf("┗━━━━━┛");
		gotoxy(42, 10); printf("                                 ");
		gotoxy(42, 10);  printf("1.  Custom Player");
		gotoxy(42, 12); printf("                                 ");
		gotoxy(42, 12); printf("2.  How To Play");
		gotoxy(42, 14); printf("                                 ");
		gotoxy(42, 14); printf("3.  Exit");
	}

	if (Player != 0){
		if (Player == 1){
			gotoxy(22, 12); printf("                      ");
			gotoxy(22, 12); printf("    Custom");
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

	if(ITEM_USE==FALSE) system("mode con cols=135 lines=34");
	else if (ITEM_USE == TRUE) system("mode con cols=135 lines=39");
	MAP_CREATE();

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");
	
}
void ITEM_EXPLAIN(){
	printf("<Item 설명>");
	printf("\n\n");
	printf("	1. 웜.\n\n");
	printf("	웜(worm)은 선택한 위치와 그 위치의 상, 하 또는 좌, 우 3칸을 동시 공격한다.\n\n");
	printf("	2. ACE의 불기둥.\n\n");
	printf("	ACE의 불기둥은 선택한 위치의 상, 하, 좌, 우 4칸을 동시 공격한다.(선택한 위치 제외)\n\n");
	printf("	3. 레이더.\n\n");
	printf("	레이더(radar)는 선택한 위치로부터 3x3의 범위를 탐지한다.(단, 공격권은 넘어간다)\n\n");
	printf("	4. 지뢰.\n\n");
	printf("	지뢰(mine)들은 빈 셀들에 설치됩니다.\n\n	만약 상대방이 당신의 지뢰를 건드리면 동일한 좌표의 상대발 셀을 오픈합니다.\n");
}
void EXPLAIN(){
	printf("\n\n");
	printf("\t\t\t\t Sea Battle 이란?\n\n");
	printf(" \t\t\t   자신의 배가 모두 침몰되기 전\n");
	printf("\t\t상대방의 배를 찾아내 침몰시키면 승리하는 게임이다.\n\n\n\n\n");
	printf("\t\t\t\t   <게임 방법>\n");
	printf("\t\t  게임 시작 시 Player에게 11척의 배가 주어진다.\n\n");
	printf(" \t■■         ■■■■ \n");
	printf(" \t■■         ■■■■ \n\n");
	printf(" \t■■         ■■■■ \n");
	printf(" \t■■         ■■■■ \n\n");
	printf(" \t■■         ■■■■         ■■■■■■\n");
	printf(" \t■■         ■■■■         ■■■■■■\n\n");
	printf(" \t■■         ■■■■         ■■■■■■         ■■■■■■■■\n");
	printf(" \t■■         ■■■■         ■■■■■■         ■■■■■■■■\n\n");
	printf("\t      방향키와 'z'키를 이용해 배를 원하는 위치에 배치시킨다.\n\n");
	printf("\t  게임이 시작되면 내 배는 물론 상대방의 배도 보이지 않게 되고\n\n");
	printf("\t\t  상대방의 배가 있을 곳을 예측해 공격을 한다.\n\n");
	printf("\t\t   공격에 성공하면 공격권이 한번더 주어지고,\n\n");
	printf("\t\t 공격에 실패하면 공격권이 상대방에게 넘어간다.\n\n");
	printf("\t         배 한채가 침몰 되면 그 주위의 타일이 공개된다.\n\n");
	printf("\t        한 Player의 배가 모두 침몰 되면 게임이 종료된다.\n\n");
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
					if (y == 10) SELECT_MENU(1);					//CUSTOM 플레이어	
					else if (y == 12){
						PRESS = FALSE;
						system("mode con cols=82 lines=41");
						EXPLAIN();

						getch();
						SELECT_MODE();
						return;
					}
					else if (y == 14){
						FINISH = TRUE;
						return;
					}
				}
				else{
					if (y == 10){ system("cls");  return;  }		// NOMAL 모드 실행
					else if (y == 12){										// ITEM 모드 실행
						system("cls"); 		ITEM_USE = TRUE; 		return;
					}										
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