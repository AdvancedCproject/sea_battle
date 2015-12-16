#ifndef _ITEM_H_
#define _ITEM_H_


#define WORM				0
#define ACE_FIRE		1
#define RETURN			2
#define RADAR			3
#define NO_ITEM		4
#define BOOL int

typedef struct ITEM{
	int item[5];
};
extern struct ITEM Item_P1;
extern struct ITEM Item_P2;
extern struct ITEM *P_ITEM;
BOOL ITEM_USE;
BOOL ITEM_CHOOSE;
int ITEM_INFO;

void ITEM_TYPE(int I_type,int x, int y);
void I_ARRANGE_SHOW(int x,int y);
void I_ARRANGE_ERASE(int x, int y);
void CHOOSE_DRAW(int x, int y);
void CHOOSE_ERASE(int x, int y);

#endif