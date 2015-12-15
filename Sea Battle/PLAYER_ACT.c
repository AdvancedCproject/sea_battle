//--------------------------------------------------------
//							PLAYER_ACT.c - 플레이어 움직임 및 공격
//--------------------------------------------------------
#include <Windows.h>
#include "PLAYER_ACT.h"
#include "KEYBOARD.h"
#include "MAKE_SHIP.h"
#include "INFO.h"
//----------------------------------------
//							FINISH_CHECK - 게임 끝났는지 판단
//------------------------	----------------
void FINISH_CHECK(){					
	int i, j;

	for (i = 0; i < MAX; i++){			// 맵 전체를 검사
		for (j = 0; j < MAX; j++)
			if (PLAYER_WHO[i][j] == BLOCK) return;		// 블록이 존재할 시 함수 종료
	}

	if (p == &p1) PLAYER_WHO = &PLAYER1_MAP;		// 플레이어1이 이기면 왼쪽 맵을 공개
	else if (p == &p2) PLAYER_WHO = &PLAYER2_MAP;	// 플레이어2가 이기면 오른쪽 맵을 공개

	// 게임이 종료된 뒤, 상대방의 남은 SHIP 위치를 보여줌
	for (i = 0; i < MAX; i++){			
		for (j = 0; j < MAX; j++)	{
			if (PLAYER_WHO[i][j] == BLOCK){
					gotoxy(((p == &p1) ? j : j + 12) * 6 + 2, (i)* 3 + 1); printf("■■");
					gotoxy(((p == &p1) ? j : j + 12) * 6 + 2, (i)* 3 + 2); printf("■■");
			}
		}
	}

}

//-----------------------------------
//							DESTROY_BLOCK_DRAW
//-----------------------------------
void DESTROY_BLOCK_DRAW(int x,int y){
	gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("    ");
	gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("    ");
	gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("▩▩");
	gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("▩▩");
}

//-----------------------------------
//							PLAYER_ATTACK
//-----------------------------------
void PLAYER_ATTACK(int x,int y){
	int Tx;

	if (p == &p1) Tx = x - 12;
	else if (p == &p2) Tx = x;

	if (PLAYER_WHO[y][Tx] == BLOCK){
			PLAYER_WHO[y][Tx] = DESTROY_BLOCK;
			DESTROY_BLOCK_DRAW(x, y);		
			DESTROY_SHIP_CHECK(x, y);
			FINISH_CHECK();
	}
	else if (PLAYER_WHO[y][Tx] == EMPTY){
		SHOW_EMPTY_SPACE(x, y);
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");

		if (PLAYER_WHO == &PLAYER1_MAP){ 
			PLAYER_WHO = &PLAYER2_MAP; 
			p = &p1; p1.x = 16; p1.y = 4;
			gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");
		}
		else if (PLAYER_WHO == &PLAYER2_MAP){
			PLAYER_WHO = &PLAYER1_MAP;
			p = &p2; p2.x = 4; p2.y = 4;
			gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");
		}
	}
}
//-----------------------------------
//							DESTROY_SHIP_CHECK
//-----------------------------------
void SHOW_EMPTY_SPACE(int x,int y){
	int Tx;

	if (p == &p1) Tx = x - 12;
	else if (p == &p2) Tx = x;

	if (PLAYER_WHO[y][Tx] == EMPTY){
		PLAYER_WHO[y][Tx] = EMPTY_SHOW;
		gotoxy((x)* 6 + 2, (y)* 3 + 1); printf("＊＊");
		gotoxy((x)* 6 + 2, (y)* 3 + 2); printf("＊＊");
	}
}

//-----------------------------------
//							DESTROY_SHIP_CHECK
//-----------------------------------
void DESTROY_SHIP_CHECK(int x,int y){
	int Tx;
	int i, j;
	BOOL CHK_XY = FALSE;

	if (p == &p1) Tx = x - 12;		// 플레이어 1일 때, 오른쪽 맵을 사용하므로
	else if (p == &p2) Tx = x;		// 플레이어 2일 때, 왼쪽 맵을 사용하므로


	//------------------------------------------------------
	// ① X축 검사, ② Y축 검사 - SHIP 이 파괴된지 확인	
	//------------------------------------------------------
	while (1){
		while (2){	// 파괴한 SHIP 좌표를 기준으로 왼쪽 검사
			if (PLAYER_WHO[y][Tx] == DESTROY_BLOCK){
				if (CHK_XY == FALSE){
					Tx--;
					if (Tx == 0 && PLAYER_WHO[y][Tx] == BLOCK) return;				// 사각지대 및 외곽 지역에서의 문제 해결
					else if (Tx < 0) break;																	//                         ""
				}
				else if (CHK_XY == TRUE){
					y--;
					if (y == MAX - 1 && PLAYER_WHO[y][Tx] == BLOCK) return;      // 사각지대 및 외곽 지역에서의 문제 해결
					if (y < 0) break;																				//                         ""
				}
			}
			else if (PLAYER_WHO[y][Tx] == BLOCK) return;
			else break;
		}
		if (CHK_XY == TRUE) break;
		CHK_XY = TRUE;	Tx++;
	}
	 y++;	// x 좌표가 왼쪽으로 1칸 더 이동됨 - 정상적인 위치를 잡아줌 ( 머리 부분 )
	CHK_XY = FALSE;		// 재활용

	while (1){
		while (2){   // 파괴된 SHIP의 맨 왼쪽에서 차근히 오른쪽 검사
			if (PLAYER_WHO[y][Tx] == DESTROY_BLOCK){
				if (CHK_XY == FALSE){
					Tx++;
					if (Tx == MAX - 1 && PLAYER_WHO[y][Tx] == BLOCK) return;		// 사각지대 및 외곽 지역에서의 문제 해결
					else if (Tx > MAX - 1) break;															//                         ""
				}
				else if (CHK_XY == TRUE){
					y++;
					if (y == MAX - 1 && PLAYER_WHO[y][Tx] == BLOCK) return;			// 사각지대 및 외곽 지역에서의 문제 해결
					else if (y > MAX - 1) break;																//                         ""
				}
			}
			else if (PLAYER_WHO[y][Tx] == BLOCK) return;
			else break;
		}
		if (CHK_XY == TRUE) break;
		CHK_XY = TRUE; Tx--;
	}
	 y--; // x 좌표가 오른쪽으로 1칸 더 이동됨 - 정상적인 위치를 잡아줌 ( 꼬리 부분 )
	CHK_XY = FALSE;

	//--------------------------------------------------------
	//					파괴된 SHIP 의 주변의 맵을 밝혀줌
	//--------------------------------------------------------
	while (1){
		while (2){
			
			// 좌우 반경 1칸씩 EMPTY 공간을 밝히고 아니면은 패스
			for (i = -1; i <= 1; i++){
				for (j = -1; j <= 1; j++){
					if (y + i >= 0 && y + i <= MAX - 1 && (Tx + j) >= 0 && (Tx + j) <= MAX - 1){		// 맵 외곽에서의 범위 설정
						if (PLAYER_WHO[y + i][Tx + j] == DESTROY_BLOCK || PLAYER_WHO[y + i][Tx + j] == EMPTY_SHOW) continue;			// 패스
						else if (PLAYER_WHO[y + i][Tx + j] == EMPTY){ // EMPTY 공간이면 맵을 밝힘
							if (p == &p1) SHOW_EMPTY_SPACE(Tx + 12 + j, y + i);
							else if (p == &p2) SHOW_EMPTY_SPACE(Tx + j, y + i);
						}
					}
				}
			}
			
			if(CHK_XY == FALSE) Tx--;				// x, y축으로 이동
			else if (CHK_XY == TRUE) y--;

			if (PLAYER_WHO[y][Tx] != DESTROY_BLOCK) break;	// 만약 파괴된 블록이 나타나지 않으면 끝냄
		}
		if (CHK_XY == TRUE) break;
		CHK_XY = TRUE; Tx++;
	}
}	

//-----------------------------------
//							MOVE_PLAYER 
//-----------------------------------
void MOVE_PLAYER(int key, int *x, int *y) {
	int i;
	switch (key) {
	case LEFT:
		if (PLAYER_WHO == &PLAYER1_MAP){
			if (*x > 0){
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*x)--;
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
			}
		}
		else if (PLAYER_WHO == &PLAYER2_MAP){
			if (*x > 12){
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*x)--;
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
			}
		}
		break;

	case RIGHT:
		if (PLAYER_WHO == &PLAYER1_MAP){
			if (*x < 9){
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*x)++;
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
			}
		}
		else if (PLAYER_WHO == &PLAYER2_MAP){
			if (*x < 21){
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*x)++;
				gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
			}
		}
		break;

	case UP:
		if (*y > 0){
			gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*y)--;
			gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
		}
		break;

	case DOWN:
		if (*y < 9){
			gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("  "); (*y)++;
			gotoxy((*x) * 6 + 3, (*y) * 3 + 3); printf("△");
		}
		break;

	case X:
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("▲");
		for (i = 0; i < 20000000; i++){}
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");

		if(MAKE_SHIP==TRUE) MAKE_SHIP_DRAW_ERA((*x), (*y));
		break;

	case Z:
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("▲");
		for (i = 0; i < 20000000; i++){}
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("  ");
		gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("△");

		if (MAKE_SHIP == TRUE){
			MAKE_SHIP_DRAW_ING((*x), (*y));
			MAKE_SHIP_DRAW_COM((*x), (*y), &number);
		}
		else if (MAKE_SHIP == FALSE) PLAYER_ATTACK(*x, *y);
		break;

	case SPACEBAR:
		break;
	}
}
