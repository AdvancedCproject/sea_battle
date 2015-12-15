//-----------------------------------------------
//						INFO.h - �÷��̾� ���� ���� �� �ʱ�ȭ ����
//-----------------------------------------------
#include <windows.h>

#ifndef _INFO_H_
#define _INFO_H_

#define MAX 10

extern struct PLAYER *p;									// ����ü �����͸� ���� �ʿ��� �� �÷��̾� ���� ��밡��
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