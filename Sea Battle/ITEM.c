#include "INFO.h"
#include "MAKE_SHIP.h"
#include "ITEM.h"

int ARRANGE_CHECK(int x,int y,int *dir,int ship){
	int Cx = 0, Cy = 0;
	int i, j;
	int count=0, Tdir;
	
	Tdir = *dir;

	while (Cx < ship && Cy < ship){
		for (i = -1; i <= 1; i++){
			for (j = -1; j <= 1; j++){
				
					if (COMPUTER_MAP[y + i + Cy][x + j + Cx] == BLOCK){
						if (count == 1){ return FALSE; }

						if (Tdir == WIDTH){ count++; Tdir = HEIGHT; Cx = 0; Cy = 0; }
						else if (Tdir == HEIGHT){ count++; Tdir = WIDTH; Cx = 0; Cy = 0; }
					
					}
			}
		}
		if (Tdir == WIDTH) Cx++;
		else if (Tdir == HEIGHT) Cy++;
	}

	*dir = Tdir;
	return TRUE;
}

int RANDOM_ARRANGE(){
	int x, y, i, j;
	int ship = 4, dir;
	int Lx = 0, Ly = 0;
	int Cx = 0, Cy = 0;
	int cnt = 1;

	while (1){
		srand((unsigned)time(NULL));
		x = rand() % MAX;	// 0 ~ 9
		y = rand() % MAX;	// 0 ~ 9
		dir = rand() % 2;		// 가로, 세로

		if (ARRANGE_CHECK(x, y, &dir, ship) == TRUE){
			for (i = 0; i < ship; i++) {
				if (y + Cy >= 0 && y + Cy <= MAX - 1 && x + Cx >= 0 && x + Cx <= MAX - 1){
					COMPUTER_MAP[y + Cy][x + Cx] = BLOCK;

					if (dir == WIDTH) Cx++;
					else if (dir == HEIGHT) Cy++;
				}
			}
			cnt++;
		}
		

		if (cnt == 2) ship = 3;				// 배 배치 3개짜리 (2개)
		else if (cnt == 4) ship = 2;		//    ""     2개 ""	(4개)
		else if (cnt == 8) ship = 1;		//	   ""     1개 ""	(4개)
		else if (cnt == 12) break;
	}

}