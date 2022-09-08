#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("1.game\n");
	printf("2.exit\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息

	//初始化数组
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '* ');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	
	//布置雷
	SetMine(mine ,ROW,COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please make your choice.\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("Incorrect Selection,please re-enter.\n");
			break;
		}
	} while (input);
	return 0;
}