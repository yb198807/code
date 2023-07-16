#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void printboard(char board[3][3])
{
	printf(" %c | %c | %c\n---|---|---\n %c | %c | %c\n---|---|---\n %c | %c | %c\n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
}
char win(char board[3][3])
{
	int x;
	for (x = 0; x < 3; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] != ' ')
			return board[x][0];
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x] && board[0][x] != ' ')
			return board[0][x];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	for (x = 0; x < 3; x++)
	{
		int y;
		for (y = 0; y < 3; y++)
		{
			if (board[x][y] == ' ')
				return 'C';
		}
	}
	return 'P';
}
int main()
{
	while (1)
	{
		int input;
		srand((unsigned int)time(NULL));
		char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
		printf("*****  1:play   0:quit  *****\n请选择：");
		scanf("%d", &input);
		if (input == 1)
		{
			printboard(board);
			while (1)
			{
				int x, y;
				printf("玩家下子：");
				scanf("%d%d", &x, &y);
				if (x <= 3 && x >= 1 && y <= 3 && y >= 1)
				{
					if (board[x - 1][y - 1] == ' ')
						board[x - 1][y - 1] = 'O';
					else
					{
						printf("输入错误，重新输入\n");
						continue;
					}
				}
				else
				{
					printf("输入错误，重新输入\n");
					continue;
				}
				printboard(board);
				char w = win(board);
				if (w == 'O')
				{
					printf("玩家赢！\n");
					break;
				}
				if (w == 'P')
				{
					printf("平局！\n");
					break;
				}
				printf("电脑下子：\n");
				while (1)
				{
					x = rand() % 3;
					y = rand() % 3;
					if (board[x][y] == ' ')
					{
						board[x][y] = 'X';
						break;
					}
					else
						continue;
				}
				printboard(board);
				w = win(board);
				if (w == 'X')
				{
					printf("电脑赢！\n");
					break;
				}
				if (w == 'P')
				{
					printf("平局！\n");
					break;
				}
			}
		}
		else if (input == 0)
			break;
		else
			printf("输入错误\n");
	}
	return 0;
}
