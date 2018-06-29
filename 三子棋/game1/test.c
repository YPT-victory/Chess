#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("***************************\n");
    printf("******** 1.play ***********\n");
    printf("******** 0.exit ***********\n");
    printf("***************************\n");
}
enum Option
{
	EXIT,
	PLAY
};

void game()
{
	char board[ROWS][COLS] = {0};
	char ret = 0;
    init_board(board, ROWS, COLS);
	display_board(board, ROWS, COLS);
	while(1)
	{
		player_move(board,ROWS,COLS);
		display_board(board,ROWS,COLS);
		ret = check_win(board,ROWS,COLS);
		if(ret != ' ')
			break;
		printf("电脑走：—————\n");
		computer_move(board,ROWS,COLS);
		display_board(board,ROWS,COLS);
		ret = check_win(board,ROWS,COLS);
		if(ret != ' ')
			break;
 	}
	if(ret == 'X')
	{
		printf("玩家赢！\n");
	}
	else if(ret == '0')
	{
		printf("电脑赢!\n");
	}
	else
	{
		printf("平局!\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch(input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("选择错误，请重新选择！！！\n");
			break;
		}
	}while(input);
	return 0;
}
