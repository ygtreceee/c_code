
//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�����Ķ���
#define ROW 3
#define COL 3


//����������


//��ʼ������
void Initboard(char board[ROW][COL],int row,int col);

//��ӡ���̵ĺ���
void Displayboard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col);