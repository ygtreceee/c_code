#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
 void Initboard(char board[ROW][COL], int row, int col)
{
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 board[i][j] = ' ';
		 }
	 }
}


 void Displayboard(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 for (i = 0; i < row; i++)
	 {
		 int j = 0;
		 for (j = 0; j < col;j++)
		 {
			 printf(" %c ",board[i][j]);
			 if (j < col - 1)
				 printf("|");
		 }
		 printf("\n");
		 if (i < row - 1)
		 {
			 int j = 0;
			 for (j = 0; j < col; j++)
			 {
				 printf("---");
				 if (j < col - 1)
					 printf("|");
			 }
		 }
		 printf("\n");
	 }
 }



 void PlayerMove(char board[ROW][COL], int row, int col)
 {
	 int x = 0;
	 int y = 0;
	 printf("Player Move\n");
	 printf("Please enter coordinates\n");
	 while (1)
	 {
		 scanf("%d %d", &x, &y);
		 //�ж�����Ϸ���
		 if (x >= 1 && x <= row && y >= 1 && y <= col)
		 {
			 //����
			 //�ж��Ƿ�ռ��
			 if (board[x - 1][y - 1]==' ')
			 {
				 board[x - 1][y - 1] = '*';
				 break;
			 }
			 else
			 {
				 printf("Coordinates have been occupied,please re-enter.\n");
			 }
		 }
		 else
		 {
			 printf("The coordinates are illegal,please re-enter.\n");
		 }
	 }
 }

 void ComputerMove(char board[ROW][COL], int row, int col)
 {
	 printf("Turn to computer\n");
	 while (1)
	 {
		 int x = rand() % row;
		 int y = rand() % col;
		 //�ж�ռ��
		 if (board[x][y] == ' ')
		 {
			 board[x][y] = '#';
			 break;
		 }
	 }
 }




 Isfull(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 if (board[i][j] == ' ')
				 return 0;//����û��
		 }
	 }
	 return 1;//��������
 }

 char Iswin(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 //�ж���
	 for (i = 0; i < row; i++)
	 {
		 if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		 {
			 return board[i][1];
		 }
	 }
	 //�ж���
	 for (i = 0; i< col; i++)
	 {
		 if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		 {
			 return board[1][i];
		 }
	 }
	 //�ж϶Խ���
	 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	 {
		 return board[0][0];
	 }
	 if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	 {
		 return board[0][2];
	 }
	 //�ж��Ƿ�ƽ��
	 int ret=Isfull(board, row, col);
	 if (ret == 1)
	 {
		 return 'Q';
	 }
	 return 'c';
 }