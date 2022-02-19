/*
 * [練習問題08]
 * 概要　：ジャンケンゲーム
 * 作成者：Twister
 * 作成日：2022/02/13
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int player;	//プレイヤーの手用
	int pc;		//コンピュータの手用

	system("cls");

	//---------------------------------
	// コンピュータの手を乱数でセット
	//---------------------------------
	srand((unsigned)time(NULL));
	pc = rand() % 3 + 1;

	//---------------------------------
	// プレイヤーの手を入力
	//---------------------------------
	printf("＊＊＊＊＊＊＊＊＊＊\n");
	printf("＊ジャンケンゲーム＊\n");
	printf("＊＊＊＊＊＊＊＊＊＊\n\n");
	printf("ジャンケンの手を選んでください\n\n");
	printf("[1]グー　[2]チョキ　[その他]パー：");
	(void)scanf("%d", &player);
	printf("\n");
	//---------------------------------
	// 判定用
	//---------------------------------
	switch (player) {
	case 1:
		printf("あなたは[グー]で");
		break;

	case 2:
		printf("あなたは[チョキ]で");
		break;

	default:
		printf("あなたは[パー]で");
		player = 3;
		break;
	}

	switch (pc) {
	case 1:
		printf("コンピュータは[グー]なので");
		break;

	case 2:
		printf("コンピュータは[チョキ]なので");
		break;
	default:
		printf("コンピュータは[パー]なので");
		break;
	}
	//---------------------------------
	// 判定用
	//---------------------------------
	if (player == pc) {
		printf("[あいこ]です\n\n");

		printf("\t ∧ ∧ アレ？\n");
		printf("\t( °°)/\n");
		printf("\t(つ   つ\n");
		printf("\t Ｕ  Ｕ \n");
	}
	else if (player-pc==-1||player-pc==2) {
			//勝ちの組み合わせは
			// (1,2)…1-2=-1
			// (2,3)…2-3=-1
			// (3,1)…3-1=2
			//負けは
			// (1,3)…1-3=-2
			// (2,1)…2-1=1
			// (3,2)…3-2=1
			// だから
		printf("あなたの[勝ち]です\n\n");

		printf("\t ∧ ∧ クー・・・\n");
		printf("\t(` ~_~)/\n");
		printf("\t(つ   つ\n");
		printf("\t Ｕ  Ｕ \n");
	}
	else {
		printf("あなたの[負け]です\n\n");

		printf("\t ∧ ∧ やった～\n");
		printf("\t(*´O`)/\n");
		printf("\t(つ   つ\n");
		printf("\t Ｕ  Ｕ \n");
	}

	//rewind(stdin);
	//(void)getchar();
	system("pause");

	return 0;
}
