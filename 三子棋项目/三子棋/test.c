#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu() {
	printf("++++++++++++++++++++++++++\n");
	printf("++ 1.开始游戏 2.结束游戏++\n");
	printf("++++++++++++++++++++++++++\n");
}
void game() {
	char board[ROW][LINE] = {0};
	InitBoard(board, ROW, LINE);//初始化棋盘（创建二维数组，赋值为' '）
	DisplayBorad(board, ROW, LINE);//显示棋盘
	char ret = 0;
	while (1)
	{
		PlayerMove(board);//玩家移动
		DisplayBorad(board, ROW, LINE);
		ret = JudWin(board);//判断是否结束
		if (ret != 'c') 
		{
			break;
		}
		CompMove(board);//电脑移动
		DisplayBorad(board, ROW, LINE);
		JudWin(board);
		if (ret != 'c') {
			break;
		}
	}
	if (ret == '+') {
		printf("玩家获胜\n");
	}
	else if (ret == '#') {
		printf("电脑获胜\n");
	}
	else if(ret=='-') {
		printf("平局\n");
	}
}
int main() {
	srand((unsigned int)time(NULL));//刷新随机数起点
	int input = 0;
	do {//无论如何，先选一次
		menu();//显示选择菜单
		printf("输入数字：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 2:
			printf("游戏结束\n");
			break;
		default:
			printf("内容无效，重新输入\n");
			break;
		}
			
	} while (input !=2);
	return 0;
}