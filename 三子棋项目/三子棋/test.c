#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu() {
	printf("++++++++++++++++++++++++++\n");
	printf("++ 1.��ʼ��Ϸ 2.������Ϸ++\n");
	printf("++++++++++++++++++++++++++\n");
}
void game() {
	char board[ROW][LINE] = {0};
	InitBoard(board, ROW, LINE);//��ʼ�����̣�������ά���飬��ֵΪ' '��
	DisplayBorad(board, ROW, LINE);//��ʾ����
	char ret = 0;
	while (1)
	{
		PlayerMove(board);//����ƶ�
		DisplayBorad(board, ROW, LINE);
		ret = JudWin(board);//�ж��Ƿ����
		if (ret != 'c') 
		{
			break;
		}
		CompMove(board);//�����ƶ�
		DisplayBorad(board, ROW, LINE);
		JudWin(board);
		if (ret != 'c') {
			break;
		}
	}
	if (ret == '+') {
		printf("��һ�ʤ\n");
	}
	else if (ret == '#') {
		printf("���Ի�ʤ\n");
	}
	else if(ret=='-') {
		printf("ƽ��\n");
	}
}
int main() {
	srand((unsigned int)time(NULL));//ˢ����������
	int input = 0;
	do {//������Σ���ѡһ��
		menu();//��ʾѡ��˵�
		printf("�������֣�");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 2:
			printf("��Ϸ����\n");
			break;
		default:
			printf("������Ч����������\n");
			break;
		}
			
	} while (input !=2);
	return 0;
}