//-----------------------------------------------
//						INFO.h - 플레이어 정보 변수 및 초기화 선언
//-----------------------------------------------

#ifndef _INFO_H_
#define _INFO_H_

#define MAX 10
#define BOOL int

typedef struct PLAYER{
	int x, y;
};

#endif

extern struct PLAYER *p;									// 구조체 포인터를 통해 필요할 때 플레이어 정보 사용가능
extern int(*PLAYER_WHO)[MAX];

BOOL FINISH;

int Victory_p1,Victory_p2;
char P1_name[30], P2_name[30];

extern int PLAYER1_MAP[MAX][MAX];
extern int PLAYER2_MAP[MAX][MAX];
extern int COMPUTER_MAP[MAX][MAX];
extern int(*PLAYER_WHO)[MAX];
extern BOOL MAKE_SHIP;
extern struct PLAYER p1;
extern struct PLAYER p2;
extern struct PLAYER com;

extern int number;