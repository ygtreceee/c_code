#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("1.play\n");
	printf("0.exit\n");
}

void game()
{
	//��������-��ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ���ո�
	Initboard(board, ROW, COL);
	//��ӡ����-�����Ǵ�ӡ��������
	Displayboard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("Player Win!\n");
	}
	else if (ret == '#')
	{
		printf("Computer Win!\n");
	}
	else
	{
		printf("Q.\n");  
	}
	Displayboard(board, ROW, COL);

}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));	//�������ֵ
	do
	{
		menu();
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			    game();
				break;
		case 0:
				printf("Quit the game\n");
				break;
		default :
				printf("Incorrect selection,please reselect\n");
				break;
		}
	} while (input);

	return 0;
}