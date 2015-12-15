//--------------------------------
//			MAKE_SHIP.c  - ��Ʋ�� ��ġ �ҽ�
//--------------------------------
#include "MAKE_SHIP.h"
#include "INFO.h"
//------------------------------------------
//										PRINT
//------------------------------------------
void PRINT() {
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			gotoxy(j * 2 + 138, i); printf("%d ", COMPUTER_MAP[i][j]);
		}
		printf("\n");
	}
}


//------------------------------------------
//                         MAKE_SHIP_DRAW_ING
//------------------------------------------
void MAKE_SHIP_DRAW_ING(int x, int y){
	int i, j, cnt = 0;
	int Tx;// ����� �� Player2�� ���� ��ǥ �� �迭 ������ ���ؼ� 

	if (p == &p2) Tx = x - 12;
	else if (p == &p1) Tx = x;

	for (i = -1; i <= 1; i++)								// UNBLOCK �� ���� ���� �ڱ� ��ġ 3 * 3 ��ġ�� BLOCK�� �ƴϿ�����
		for (j = -1; j <= 1; j++)
			if (y + i >= 0 && y + i <= MAX - 1 && Tx + j <= MAX - 1 && Tx + j >= 0)		// ���� �𼭸� �αٿ� cnt�� ������ ���� �ذ�
				if (PLAYER_WHO[y + i][Tx + j] == BLOCK) cnt++;

	if (cnt == EMPTY){										// ���� BLOCK�� ���ٸ� UNBLOCK�� ���� ���� ����
		gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("���");
		gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("���");
		PLAYER_WHO[y][Tx] = UNBLOCK;
	}
}


//-------------------------------------------
//							DRAW_BLOCK
//-------------------------------------------
void DRAW_BLOCK(int x, int y){
	int Tx;				// ����� �� Player1, 2�� ���� ��ǥ �� �迭 ������ ���ؼ� 

	if (p == &p1) Tx = x;
	else if (p == &p2) Tx = x + 12;

	gotoxy((Tx)* 6 + 2, (y)* 3 + 1); printf("���");
	gotoxy((Tx)* 6 + 2, (y)* 3 + 2); printf("���");

	PLAYER_WHO[y][x] = BLOCK;
}


//------------------------------------------
//                         MAKE_SHIP_DRAW_ERA
//------------------------------------------
void MAKE_SHIP_DRAW_ERA(int x, int y){
	int Tx;				// ����� �� Player1, 2�� ���� ��ǥ �� �迭 ������ ���ؼ� 

	if (p == &p1) Tx = x;
	else if (p == &p2) Tx = x - 12;

	if (PLAYER_WHO[y][Tx] == UNBLOCK){
		gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("      ");
		gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("      ");

		PLAYER_WHO[y][Tx] = EMPTY;
	}
}


//-------------------------------------------
//							ERASE_DISABLE_BLOCK
//-------------------------------------------
void ERASE_ALL_BLOCK(){
	int i, j;
	int Alpha;

	if (p == &p1) Alpha = 0;
	else if (p == &p2) Alpha = 12;


	for (i = 0; i < MAX; i++){
		for (j = 0 + Alpha; j < MAX + Alpha; j++){
				gotoxy((j)* 6 + 2, (i)* 3 + 1); printf("      ");
				gotoxy((j)* 6 + 2, (i)* 3 + 2); printf("      ");	
		}
	}
}


//-------------------------------------------
//							MAKE_SHIP_NOTICE
//-------------------------------------------
void MAKE_SHIP_NOTICE(int ship){
	if (PLAYER_WHO == PLAYER1_MAP){
		gotoxy(11, 32); printf("PLAYER 1 : %d��¥�� �踦 ��ġ�Ͻÿ�. (�� %d��)", ship, (ship == 4) ? 1 : (ship == 3) ? 2 : (ship == 2 || ship == 1) ? 4 : 0);
	}
	else if (PLAYER_WHO == PLAYER2_MAP){
		gotoxy(11, 32); printf("                                                                           ");
		gotoxy(11, 50); printf("PLAYER 2 : %d��¥�� �踦 ��ġ�Ͻÿ�. (�� %d��)", ship, (ship == 4) ? 1 : (ship == 3) ? 2 : (ship == 2 || ship == 1) ? 4 : 0);
	}
}



//-------------------------------------------
//							MAKE_SHIP_DRAW_COM
//-------------------------------------------
void MAKE_SHIP_DRAW_COM(int x, int y, int *number){
	int px = 0, py = 0;
	int Tx;
	int countX = 0, countY = 0, count = 0;
	int i, j, k;
	BOOL Switch = FALSE;
	static int cnt = 1;

	if (p == &p2) Tx = x - 12;
	else if (p == &p1) Tx = x;

	//-------------------------------------------
	// x�� �˻� - ������ ������ŭ �踦 ��ġ�ϸ� �ڵ� BLOCK���� ��ȯ
	//-------------------------------------------
	while (1){
		count++;
		if (PLAYER_WHO[y][px++] == UNBLOCK)  countX++;		// UNBLOCK �� ������ ���� ��
		else countX = 0;

		if (countX == *number){		//������ ������ŭ ������

			for (k = 0; k < countX; k++){
				--px;
				for (i = -1; i <= 1; i++){							// Ȥ�� ������ �����ִ� UNBLOCK�� ������ ����
					for (j = -1; j <= 1; j++){
						//if (y + i >= 0 && y + i <= MAX - 1 && (px + j) >= 0 && (px + j) <= MAX - 1){
							if (p == &p1)  MAKE_SHIP_DRAW_ERA(px + j, y + i);
							else if (p == &p2)	MAKE_SHIP_DRAW_ERA((px + 12) + j, y + i);
						//}
					}
				}
			}
			
			for (k = 0; k < countX; k++)  DRAW_BLOCK(px++, y);	// UNBLOCK -> BLOCK	
			
			cnt++;

			if (cnt == 2) *number = 3;				// �� ��ġ 3��¥�� (2��)
			else if (cnt == 4) *number = 2;		//    ""     2�� ""	(4��)
			else if (cnt == 8) *number = 1;		//	   ""     1�� ""	(4��)
			else if (cnt == 12){
				for (i = 0; i < 300000000; i++){}			// ������
				ERASE_ALL_BLOCK();							// �ʿ��� �׷��� ��� �����

				if (p == &p2){										//�� ��ġ�� �÷��̾� 2���� �� ������ ��
					MAKE_SHIP = FALSE;
					gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
					GAME_START_INIT();
					return;
				}

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");

				p = &p2;	PLAYER_WHO = PLAYER2_MAP;
				cnt = 1;	*number = 4;

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("��");
			}  //    ""     0�� 

			return;
		}
		if (count == MAX) break;
	}

	count = 0;

	//-------------------------------------------
	//y�� �˻� - ������ ������ŭ �踦 ��ġ�ϸ� �ڵ� BLOCK���� ��ȯ
	//-------------------------------------------
	while (1){
		count++;
		if (PLAYER_WHO[py++][Tx] == UNBLOCK) countY++;		// UNBLOCK �� ������ ���� ��
		else countY = 0;

		if (countY == *number){		//������ ������ŭ ������

			for (k = 0; k < countY; k++){
				--py;
				for (i = -1; i <= 1; i++){						// Ȥ�� ������ �����ִ� UNBLOCK�� ������ ����
					for (j = -1; j <= 1; j++){
						//if (py + i >= 0 && py + i <= MAX - 1 && (Tx + j) >= 0 && (Tx + j) <= MAX - 1){
							if (p == &p1) MAKE_SHIP_DRAW_ERA(Tx + j, py + i);
							else if (p == &p2) MAKE_SHIP_DRAW_ERA((Tx + 12) + j, py + i);
						//}
					}
				}
			}
			for (k = 0; k < countY; k++)  DRAW_BLOCK(Tx, py++);	// UNBLOCK -> BLOCK	

			cnt++;

			if (cnt == 2) *number = 3;				// �� ��ġ 3��¥�� (2��)
			else if (cnt == 4) *number = 2;		//    ""     2�� ""	(4��)
			else if (cnt == 8) *number = 1;		//	   ""     1�� ""	(4��)
			else if (cnt == 12){
				for (i = 0; i < 300000000; i++){}			// ������
				ERASE_ALL_BLOCK();

				if (p == &p2){								//�� ��ġ�� �� ������ ���
					MAKE_SHIP = FALSE;
					gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
					GAME_START_INIT();
					return;
				}

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");

				PLAYER_WHO = PLAYER2_MAP;			p = &p2;		cnt = 1;		*number = 4;

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("��");

			}//    ""     0�� ""

			return;
		}
		if (count == MAX) break;
	}
}
