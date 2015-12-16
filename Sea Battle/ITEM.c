#include "MAKE_SHIP.h"
#include "INFO.h"
#include "KEYBOARD.h"
#include "ITEM.h"

void CHOOSE_DRAW(int x,int y){
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 34 + (y * 2)); printf("旨收收收收收收旬");
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 35 + (y * 2)); printf("早            早 ");
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 36 + (y * 2)); printf("曲收收收收收收旭");
}
void CHOOSE_ERASE(int x,int y){
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 34 + (y * 2)); printf("                 ");
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 35 + (y * 2)); printf("  ");
	gotoxy(((p == &p1) ? 24 : 93) + (27 * x), 35 + (y * 2)); printf("  ");
	gotoxy(((p == &p1) ? 10 : 79) + (27 * x), 36 + (y * 2)); printf("                 ");
}
void CHOOSE_ITEM(int key){
	static int x = 0, y = 0;

	CHOOSE_ERASE(x, y);
	
	switch (key){
		case LEFT:
			if (x == 1) x--;
			break;
		case RIGHT:
			if (x == 0) x++;
			break;
		case UP:
			if (y == 1) y--;
			break;
		case DOWN:
			if (y == 0) y++;
			break;
	}
	
	CHOOSE_DRAW(x, y);

	if (key == Z){
		if (x == 0 && y == 0) {
			if (P_ITEM->item[WORM] != 0){
				ITEM_INFO = WORM;
				P_ITEM->item[WORM]--;
			}
		}
		else if (x == 1 && y == 0){
			if (P_ITEM->item[RETURN] != 0){
				ITEM_INFO = RETURN;
				P_ITEM->item[RETURN]--;
			}
		}
		else if (x == 0 && y == 1){
			if (P_ITEM->item[ACE_FIRE] != 0){
				ITEM_INFO = ACE_FIRE;
				P_ITEM->item[ACE_FIRE]--;
			}
		}
		else if (x == 1 && y == 1){
			if (P_ITEM->item[RADAR] != 0){
				ITEM_INFO = RADAR;
				P_ITEM->item[RADAR]--;
			}
		}

		CHOOSE_ERASE(x, y);
		x = 0, y = 0;
	}
	else if (key == X){
		CHOOSE_ERASE(x, y);
		ITEM_CHOOSE = 0;
		return;
	}
}

void ITEM_NUM(){
	gotoxy(12,35); printf("錢⊥ :%3d",Item_P1.item[WORM]);
	gotoxy(12, 37); printf("縑碳 :%3d", Item_P1.item[ACE_FIRE]);
	gotoxy(39, 35); printf("錢∟ :%3d", Item_P1.item[RETURN]);
	gotoxy(39, 37); printf("溯檜渦 :%3d", Item_P1.item[RADAR]);
	
	gotoxy(81, 35); printf("錢⊥ :%3d", Item_P2.item[WORM]);
	gotoxy(81, 37); printf("縑碳 :%3d", Item_P2.item[ACE_FIRE]);
	gotoxy(108, 35); printf("錢∟ :%3d", Item_P2.item[RETURN]);
	gotoxy(108, 37); printf("溯檜渦 :%3d", Item_P2.item[RADAR]);
}

void ITEM_CHECK(int x,int y,int Tx){
	if (PLAYER_WHO[y][Tx] == EMPTY || PLAYER_WHO[y][Tx] == EMPTY_SHOW){
		PLAYER_WHO[y][Tx] = EMPTY_SHOW;
		gotoxy((x) * 6 + 2, (y) * 3 + 1); printf("ㄙㄙ");
		gotoxy((x) * 6 + 2, (y) * 3 + 2); printf("ㄙㄙ");
	}
	else if (PLAYER_WHO[y][Tx] == BLOCK){
		PLAYER_WHO[y][Tx] = DESTROY_BLOCK;
		gotoxy((x) * 6 + 2, (y) * 3 + 1); printf("十十");
		gotoxy((x) * 6 + 2, (y) * 3 + 2); printf("十十");
	}
}

void ITEM_TYPE(int I_type,int x, int y){
	int i, j, Tx;

	if (p == &p1) Tx = x - 12;
	else if (p == &p2) Tx = x;

	switch (I_type){
	case WORM:
		for (i = -1; i <= 1; i++){
			if (Tx + i < 0 || Tx + i > MAX - 1 || y + i < 0 || y + i > MAX - 1) continue;
			ITEM_CHECK(x + i, y, Tx + i);
		}
		break;

	case ACE_FIRE:
		for (i = -1; i <= 1; i++){
			for (j = -1; j <= 1; j++){
				if (Tx + i < 0 || Tx + i > MAX - 1 || y + i < 0 || y + i > MAX - 1) continue;
				if (((i == -1 || i == 1) && j == 0) || (i == 0 && (j == -1 || j == 1))){
					ITEM_CHECK(x + j, y + i, Tx + j);
				}
			}
		}
		break;

	case RETURN:
		for (i = -1; i <= 1; i++){
			if (Tx + i < 0 || Tx + i > MAX - 1 || y + i < 0 || y + i > MAX - 1) continue;
			ITEM_CHECK(x, y+i, Tx + i);
		}
		break;

	case RADAR:
		for (i = -1; i <= 1; i++){
			for (j = -1; j <= 1; j++){
				if (Tx + i < 0 || Tx + i > MAX - 1 || y + i < 0 || y + i > MAX - 1) continue;				
				if (PLAYER_WHO[y+i][Tx+j] == EMPTY){
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 1); printf("ㄙㄙ");
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 2); printf("ㄙㄙ");
				}
				else if (PLAYER_WHO[y+i][Tx+j] == BLOCK){
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 1); printf("﹥﹥");
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 2); printf("﹥﹥");
				}
			}
		}
		for (i = 0; i < 200000000; i++);
		for (i = -1; i <= 1; i++){
			for (j = -1; j <= 1; j++){
				if (Tx + i < 0 || Tx + i > MAX - 1 || y + i < 0 || y + i > MAX - 1) continue;
				if (PLAYER_WHO[y+i][Tx+j] == EMPTY){
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 1); printf("    ");
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 2); printf("    ");
				}
				else if (PLAYER_WHO[y+i][Tx+j] == BLOCK){
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 1); printf("    ");
					gotoxy((x + j) * 6 + 2, (y + i) * 3 + 2); printf("    ");
				}
			}
		}
		break;
	}
	DESTROY_SHIP_CHECK(x, y);
}

