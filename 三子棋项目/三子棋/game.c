#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROW][LINE], int row, int line) {//��ʼ�����̣���ά���飩
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBorad(char board[ROW][LINE], int row, int line) {//��ʾ����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			printf(" %c ", board[i][j]);
			if (j < line - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < line - 1) {
			for (int j = 0; j < line; j++) {
				printf("---");
				if (j < line - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][LINE]) {
	int x = 0; int y = 0;
	printf("���������");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x > ROW || y > LINE) {
			printf("�����������������;");
			continue;
		}
		else if (board[x - 1][y - 1] != ' ') {
			printf("��λ���ѱ�ռ�ã�����������");
			continue;
		}
		else {
			board[x-1][y-1] = '+';
			break;
		}
	}
}
void CompMove(char board[ROW][LINE]) {
	printf("��������\n");
	int x = 0; int y = 0;
	while (1) {
		int ranx = rand() % ROW; int rany = rand() % LINE;
		if (board[ranx][rany] == ' ') {
			board[ranx][rany] = '#';
			break;
		}
	}
}
char JudWin(char board[ROW][LINE]) {
	//�ж���
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < LINE; j++) {
			if ((j + 2) < LINE && board[i][j] == board[i][j + 1] && board[i][j + 2]==board[i][j+1]&&board[i][j]!=' ') {
				return board[i][j];
			}
		}
	}
	//�ж���
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < ROW; j++) {
			if ((j + 2) < ROW && board[j][i] == board[j+1][i] && board[j+1][i]==board[j+2][i]&&board[j][i]!=' ') {
				return board[j][i];
			}
		}
	}
	//�ж�б��
	for (int i = 0; i <= ROW - 3; i++) {//ROW-3�������б��Ԫ�ز�����
		for (int j = 0; j + 2 < LINE; j++) {
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ') {
				return board[i][j];
			}
		}
	}
	//�ж�ƽ��
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++) 
		{
			if (board[i][j] == ' ')
			{
				count++;
			}
		}
	}
	if (count == 0) 
	{
		return '-';
	}
	return 'c';
	}
	
	//'+'-->���Ӯ 
	//'#'-->����Ӯ
	//'-'-->ƽ��
	//'c'-->����