//-----------------------------------------------
//						INFO.h - 플레이어 정보 변수 및 초기화 선언
//-----------------------------------------------
#include <windows.h>

#ifndef _INFO_H_
#define _INFO_H_

#define MAX 10

extern struct PLAYER *p;									// 구조체 포인터를 통해 필요할 때 플레이어 정보 사용가능
extern int(*PLAYER_WHO)[MAX];


int PLAYER1_MAP[MAX][MAX];
int PLAYER2_MAP[MAX][MAX];
int COMPUTER_MAP[MAX][MAX];
int(*PLAYER_WHO)[MAX];
int number;

typedef struct PLAYER{
	int x, y;
};

extern BOOL MAKE_SHIP;
extern struct PLAYER p1;
extern struct PLAYER p2;
extern struct PLAYER com;

#endif