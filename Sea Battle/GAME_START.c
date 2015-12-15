#include "GAME_START.h"
#include "INFO.h"

//------------------------------------------
//                         GAME START
//------------------------------------------
void GAME_START_INIT(){
	p = &p1;

	p1.x = 4; p1.y = 4;

	gotoxy((p->x) * 6 + 3, (p->y) * 3 + 3); printf("¡â");

	gotoxy(50, 32); printf("                                                          ");
	gotoxy(11, 32); printf("GAME START!");
}