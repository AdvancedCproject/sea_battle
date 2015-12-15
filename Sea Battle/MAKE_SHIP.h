//-----------------------------------------------
//						MAKE_SHIP.h 
//-----------------------------------------------
#ifndef _MAKE_SHIP_H_
#define _MAKE_SHIP_H_

#define EMPTY 0
#define EMPTY_SHOW 4
#define BLOCK 1
#define UNBLOCK 2
#define DESTROY_BLOCK 3

void PRINT();
//-------------------------------
//                ¸Ê ¹èÄ¡ ÇÔ¼ö
//------------------------------
void MAKE_SHIP_DRAW_ING(int x, int y);
void MAKE_SHIP_DRAW_ERA(int x, int y);
void MAKE_SHIP_DRAW_COM(int x, int y, int *number);
void MAKE_SHIP_NOTICE(int ship);
void DRAW_BLOCK(int x, int y);
void ERASE_DISABLE_BLOCK();
void ERASE_ABLE_BLOCK();

#endif