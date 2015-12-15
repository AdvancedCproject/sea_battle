//--------------------------------
//			MAKE_SHIP.c  - 배틀쉽 배치 소스
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
	int Tx;// 제대로 된 Player2의 맵의 좌표 및 배열 대입을 위해서 

	if (p == &p2) Tx = x - 12;
	else if (p == &p1) Tx = x;

	for (i = -1; i <= 1; i++)								// UNBLOCK 을 놓기 전에 자기 위치 3 * 3 위치에 BLOCK이 아니여야함
		for (j = -1; j <= 1; j++)
			if (y + i >= 0 && y + i <= MAX - 1 && Tx + j <= MAX - 1 && Tx + j >= 0)		// 가끔 모서리 부근에 cnt를 세지는 현상 해결
				if (PLAYER_WHO[y + i][Tx + j] == BLOCK) cnt++;

	if (cnt == EMPTY){										// 만약 BLOCK이 없다면 UNBLOCK을 놓을 수가 있음
		gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("□□");
		gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("□□");
		PLAYER_WHO[y][Tx] = UNBLOCK;
	}
}


//-------------------------------------------
//							DRAW_BLOCK
//-------------------------------------------
void DRAW_BLOCK(int x, int y){
	int Tx;				// 제대로 된 Player1, 2의 맵의 좌표 및 배열 대입을 위해서 

	if (p == &p1) Tx = x;
	else if (p == &p2) Tx = x + 12;

	gotoxy((Tx)* 6 + 2, (y)* 3 + 1); printf("■■");
	gotoxy((Tx)* 6 + 2, (y)* 3 + 2); printf("■■");

	PLAYER_WHO[y][x] = BLOCK;
}


//------------------------------------------
//                         MAKE_SHIP_DRAW_ERA
//------------------------------------------
void MAKE_SHIP_DRAW_ERA(int x, int y){
	int Tx;				// 제대로 된 Player1, 2의 맵의 좌표 및 배열 대입을 위해서 

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
		gotoxy(11, 32); printf("PLAYER 1 : %d개짜리 배를 설치하시오. (총 %d개)", ship, (ship == 4) ? 1 : (ship == 3) ? 2 : (ship == 2 || ship == 1) ? 4 : 0);
	}
	else if (PLAYER_WHO == PLAYER2_MAP){
		gotoxy(11, 32); printf("                                                                           ");
		gotoxy(11, 50); printf("PLAYER 2 : %d개짜리 배를 설치하시오. (총 %d개)", ship, (ship == 4) ? 1 : (ship == 3) ? 2 : (ship == 2 || ship == 1) ? 4 : 0);
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
	// x축 검사 - 정해진 갯수만큼 배를 배치하면 자동 BLOCK으로 전환
	//-------------------------------------------
	while (1){
		count++;
		if (PLAYER_WHO[y][px++] == UNBLOCK)  countX++;		// UNBLOCK 된 연이은 갯수 셈
		else countX = 0;

		if (countX == *number){		//정해진 갯수만큼 있으면

			for (k = 0; k < countX; k++){
				--px;
				for (i = -1; i <= 1; i++){							// 혹시 주위에 남아있는 UNBLOCK이 있으면 제거
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

			if (cnt == 2) *number = 3;				// 배 배치 3개짜리 (2개)
			else if (cnt == 4) *number = 2;		//    ""     2개 ""	(4개)
			else if (cnt == 8) *number = 1;		//	   ""     1개 ""	(4개)
			else if (cnt == 12){
				for (i = 0; i < 300000000; i++){}			// 딜레이
				ERASE_ALL_BLOCK();							// 맵에서 그려진 블록 지우기

				if (p == &p2){										//맵 배치를 플레이어 2까지 다 끝냈을 때
					MAKE_SHIP = FALSE;
					gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
					GAME_START_INIT();
					return;
				}

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");

				p = &p2;	PLAYER_WHO = PLAYER2_MAP;
				cnt = 1;	*number = 4;

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");
			}  //    ""     0개 

			return;
		}
		if (count == MAX) break;
	}

	count = 0;

	//-------------------------------------------
	//y축 검사 - 정해진 갯수만큼 배를 배치하면 자동 BLOCK으로 전환
	//-------------------------------------------
	while (1){
		count++;
		if (PLAYER_WHO[py++][Tx] == UNBLOCK) countY++;		// UNBLOCK 된 연이은 갯수 셈
		else countY = 0;

		if (countY == *number){		//정해진 갯수만큼 있으면

			for (k = 0; k < countY; k++){
				--py;
				for (i = -1; i <= 1; i++){						// 혹시 주위에 남아있는 UNBLOCK이 있으면 제거
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

			if (cnt == 2) *number = 3;				// 배 배치 3개짜리 (2개)
			else if (cnt == 4) *number = 2;		//    ""     2개 ""	(4개)
			else if (cnt == 8) *number = 1;		//	   ""     1개 ""	(4개)
			else if (cnt == 12){
				for (i = 0; i < 300000000; i++){}			// 딜레이
				ERASE_ALL_BLOCK();

				if (p == &p2){								//맵 배치를 다 끝냈을 경우
					MAKE_SHIP = FALSE;
					gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
					GAME_START_INIT();
					return;
				}

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");

				PLAYER_WHO = PLAYER2_MAP;			p = &p2;		cnt = 1;		*number = 4;

				gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");

			}//    ""     0개 ""

			return;
		}
		if (count == MAX) break;
	}
}
