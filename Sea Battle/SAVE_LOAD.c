#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <conio.h>
#include "INFO.h"

void SAVE(){
	FILE *fp = fopen("SEA_BATTLE.txt", "w");

	system("mode con: cols=50 lines=10");

	printf("[Player1] 이름 입력 : ");
	scanf("%s", P1_name);

	fprintf(fp, "%s %d\n", P1_name,Victory_p1);

	printf("\n[Player2] 이름 입력 : ");
	scanf("%s", P2_name);

	fprintf(fp, "%s %d", P2_name, Victory_p2);
	
	fclose(fp);

	getch();
	system("cls");
}
void LOAD(){
	FILE *fp = fopen("SEA_BATTLE.txt", "r");
	

	if (fp == NULL){
		printf("정보가 없습니다. 새로운 정보를 입력하세요.\n\n");
		SAVE();
		return;
	}
	
	fscanf(fp, "%s%d", P1_name, &Victory_p1);
	fscanf(fp, "%s%d", P2_name, &Victory_p2);

	system("cls");
	system("mode con: cols=50 lines=10");
	printf("[%s] 승리 : %d\n", P1_name, Victory_p1);
	printf("[%s] 승리 : %d\n", P2_name, Victory_p2);

	getch();

	fclose(fp);
}