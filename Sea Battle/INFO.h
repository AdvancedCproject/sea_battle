//-----------------------------------------------
//						INFO.h - �÷��̾� ���� ���� �� �ʱ�ȭ ����
//-----------------------------------------------

#ifndef _INFO_H_
#define _INFO_H_

#define MAX 10
#define BOOL int

typedef struct PLAYER{
	int x, y;
};

#endif

extern struct PLAYER *p;									// ����ü �����͸� ���� �ʿ��� �� �÷��̾� ���� ��밡��
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