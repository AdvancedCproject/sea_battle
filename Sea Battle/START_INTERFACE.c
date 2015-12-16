//--------------------------------------------------------
//				START_INTERFACE.c - ���� �� �޴� ���� �������̽��� �� ����
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
		gotoxy(22, 8); printf("��������������");
		gotoxy(22, 12); printf("    SELECT ");            
		gotoxy(22, 16); printf("��������������");
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
	printf(" ��������������������������������������������������������������������������������������\n");
	printf(" ������ᣪ����ᣪ�����ᣪ���ᣪ����ᣪ���ᣪ����ᣪ���ᣪ���ᣪ\n");
	printf(" ���ᣪ�������ᣪ���ᣪ�ᣪ�ᣪ�ᣪ�ᣪ�����ᣪ���������ᣪ���ᣪ���ᣪ�ᣪ�ᣪ���ᣪ��\n");
	printf(" ���ᣪ��ᣪ����ᣪ�ᣪ�ᣪ�ᣪ���ᣪ����ᣪ���ᣪ������ᣪ����ᣪ�ᣪ��\n");
	printf(" ���ᣪ���ᣪ�ᣪ���ᣪ�ᣪ�ᣪ�ᣪ�ᣪ�����������ᣪ���ᣪ���ᣪ���ᣪ�ᣪ���ᣪ�ᣪ��\n");
	printf(" ������ᣪ�ᣪ���ᣪ�ᣪ�ᣪ�ᣪ���ᣪ����ᣪ���ᣪ���ᣪ���ᣪ�ᣪ���ᣪ�ᣪ��\n");
	printf(" ��������������������������������������������������������������������������������������\n");

	Sleep(2000);

	system("cls");

	if(ITEM_USE==FALSE) system("mode con cols=135 lines=34");
	else if (ITEM_USE == TRUE) system("mode con cols=135 lines=39");
	MAP_CREATE();

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("��");
	
}
void ITEM_EXPLAIN(){
	printf("<Item ����>");
	printf("\n\n");
	printf("	1. ��.\n\n");
	printf("	��(worm)�� ������ ��ġ�� �� ��ġ�� ��, �� �Ǵ� ��, �� 3ĭ�� ���� �����Ѵ�.\n\n");
	printf("	2. ACE�� �ұ��.\n\n");
	printf("	ACE�� �ұ���� ������ ��ġ�� ��, ��, ��, �� 4ĭ�� ���� �����Ѵ�.(������ ��ġ ����)\n\n");
	printf("	3. ���̴�.\n\n");
	printf("	���̴�(radar)�� ������ ��ġ�κ��� 3x3�� ������ Ž���Ѵ�.(��, ���ݱ��� �Ѿ��)\n\n");
	printf("	4. ����.\n\n");
	printf("	����(mine)���� �� ���鿡 ��ġ�˴ϴ�.\n\n	���� ������ ����� ���ڸ� �ǵ帮�� ������ ��ǥ�� ���� ���� �����մϴ�.\n");
}
void EXPLAIN(){
	printf("\n\n");
	printf("\t\t\t\t Sea Battle �̶�?\n\n");
	printf(" \t\t\t   �ڽ��� �谡 ��� ħ���Ǳ� ��\n");
	printf("\t\t������ �踦 ã�Ƴ� ħ����Ű�� �¸��ϴ� �����̴�.\n\n\n\n\n");
	printf("\t\t\t\t   <���� ���>\n");
	printf("\t\t  ���� ���� �� Player���� 11ô�� �谡 �־�����.\n\n");
	printf(" \t���         ����� \n");
	printf(" \t���         ����� \n\n");
	printf(" \t���         ����� \n");
	printf(" \t���         ����� \n\n");
	printf(" \t���         �����         �������\n");
	printf(" \t���         �����         �������\n\n");
	printf(" \t���         �����         �������         ���������\n");
	printf(" \t���         �����         �������         ���������\n\n");
	printf("\t      ����Ű�� 'z'Ű�� �̿��� �踦 ���ϴ� ��ġ�� ��ġ��Ų��.\n\n");
	printf("\t  ������ ���۵Ǹ� �� ��� ���� ������ �赵 ������ �ʰ� �ǰ�\n\n");
	printf("\t\t  ������ �谡 ���� ���� ������ ������ �Ѵ�.\n\n");
	printf("\t\t   ���ݿ� �����ϸ� ���ݱ��� �ѹ��� �־�����,\n\n");
	printf("\t\t ���ݿ� �����ϸ� ���ݱ��� ���濡�� �Ѿ��.\n\n");
	printf("\t         �� ��ä�� ħ�� �Ǹ� �� ������ Ÿ���� �����ȴ�.\n\n");
	printf("\t        �� Player�� �谡 ��� ħ�� �Ǹ� ������ ����ȴ�.\n\n");
}
//----------------------------------------
//                            SELECT_MODE
//----------------------------------------
void SELECT_MODE(){
	int key, x = 37, y = 10;
	BOOL PRESS = FALSE;
	char *SELECT = "��";
	int SHAPE_SEL = 0;

	int What_Mode = 0;

	system("mode con cols=90 lines=18");
	printf(" ����������������������������������������������������������������������������������������\n");
	printf(" ������ᣪ����ᣪ����ᣪ����ᣪ������ᣪ���ᣪ���ᣪ�ᣪ��������ᣪ\n");
	printf(" ���ᣪ�������ᣪ�������ᣪ���ᣪ�ᣪ�����ᣪ�ᣪ���ᣪ���ᣪ�����ᣪ���ᣪ�����ᣪ������\n");
	printf(" ������ᣪ����ᣪ����ᣪ����ᣪ������ᣪ���ᣪ�����ᣪ���ᣪ��������ᣪ\n");
	printf(" ���������ᣪ�ᣪ�������ᣪ���ᣪ�ᣪ�����ᣪ�ᣪ���ᣪ���ᣪ�����ᣪ���ᣪ�����ᣪ������\n");
	printf(" ������ᣪ����ᣪ�ᣪ���ᣪ����ᣪ���ᣪ���ᣪ���ᣪ�����ᣪ�����ᣪ����ᣪ\n");
	printf(" ����������������������������������������������������������������������������������������\n");

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
					if (y == 10) SELECT_MENU(1);					//CUSTOM �÷��̾�	
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
					if (y == 10){ system("cls");  return;  }		// NOMAL ��� ����
					else if (y == 12){										// ITEM ��� ����
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

	gotoxy(0, 0);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 3);  printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 6);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 9);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 12);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 15);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 18);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 21);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 24);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 27);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 30);	printf("��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��          ��    ��    ��    ��    ��    ��    ��    ��    ��    ��    ��");
	gotoxy(0, 31);	printf("������������������������������������������������������������������  ������������������������������������������������������������������");
	gotoxy(0, 33);	printf("������������������������������������������������������������������  ������������������������������������������������������������������");
	
	for (i = 0; i < 31; i++) {
		gotoxy(64, i); printf("���᦭");
	}
}