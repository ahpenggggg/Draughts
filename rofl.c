#include <stdio.h>
#include <stdbool.h>

void printinit(char p1[50], char p2[50])
{
	printf("  -------------------- DRAUGHTS -------------------\n\n");
	
	printf(" --------------Previous Players\' Scores\'--------------");
	
	printf("\n\nInput player 1 name: ");
	scanf("%s", &*p1);
	
	printf("Input player 2 name: ");
	scanf("%s", &*p2);
	
	printf("\nPlayer 1: %s", p1);
	printf("\nPlayer 2: %s", p2);
	
	printf("\n\nGood Luck Have Fun!\n");
}

void display(int i, int j, char dboard[8][8])
{
	printf(" ----------------------------------------------- \n");
	for (i = 0; i < 8 ;i++)
	{	
		printf("\n|");
		for (j = 0; j < 8; j++)
		{
			
			printf("  %c  |", dboard[i][j]);
		}
		
		printf("\n\n ----------------------------------------------- \n");
	}
}

void printboard(int i, int j, char dboard[8][8], char *tokenx, char *tokeno, char *token0)
{
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (((i+j) % 2 == 0))
			{
				dboard[i][j] = *tokeno;
			}
			else
			{
				dboard[i][j] = *token0;
			}
		}
	}
	
	for (i = 3; i < 5; i++)
	{
		for (j = 0; j < 8; j++)
		{
			dboard[i][j] = *token0;
		}
	}
	
	for (i = 5; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (((i+j) % 2 == 0))
			{
				dboard[i][j] = *tokenx;
			}
			else
			{
				dboard[i][j] = *token0;
			}
		}
	}

display(i,j, dboard);	
	
}

void p1select(char player1[50])
{
	printf("\n%s\'s turn. (TOKEN: X)\n", player1);
}

bool p1move(bool app_run, char x, int i, int j, int oi, int oj, char dboard[8][8], char *tokenx, char *token0, char *tokeno)
{
	printf("Enter coordinates of token you want to move: ");
	scanf("%c %i %i", &oi, &oj);
	
	if(x == 'x')
	{
		app_run = false;
	}
	else
	{
		printf("Enter Coordinates of the position: ");
		scanf("%i %i", &i, &j);
	}
	
	while ((i == oi && j == oj + 1) || (i == oi && j == oj - 1) || (i == oi + 1 && j == oj) || (i == oi - 1 && j == oj) || (i == oi + 1 && j == oj +1) || (i == oi + 1 && j == oj - 1))
	{
		printf("Invalid movement. Reenter coordinates of token you want to move: ");
		scanf("%i %i", &oi, &oj);
			
		printf("Enter Coordinates of the position: ");
		scanf("%i %i", &i, &j);
	}
	
	if(dboard[i][j] != *tokeno)
	{
		system("cls");
		dboard[oi][oj] = *token0;
		dboard[i][j] = *tokenx;
		display(i, j, dboard);
	}	
	else
	{
		if(dboard[i-1][j-1] == *tokenx || dboard[i-1][j-1] == *tokeno)
		{
			p1move(app_run, x, i, j, oi, oj, dboard, tokenx, token0, tokeno);
		}
		else
		{
		system("cls");
		dboard[oi][oj] = *token0;
		dboard[i][j] = *token0;
		dboard[i-1][j-1] = *tokenx;
		display(i, j, dboard);
		}
	}		
	return app_run;
}

void p2select(char player2[50])
{
	printf("\n%s\'s turn. (TOKEN: O)\n", player2);
}

bool p2move(bool app_run, char x, int i, int j, int oi, int oj, char dboard[8][8], char *tokeno, char *token0, char *tokenx)
{
	printf("Enter coordinates of token you want to move: ");
	scanf("%i %i", &oi, &oj);
		
	if(x == 'x')
	{
		app_run = false;
	}
	else
	{
		printf("Enter Coordinates of the position: ");
		scanf("%i %i", &i, &j);
	
		while ((i == oi && j == oj + 1) || (i == oi && j == oj - 1) || (i == oi + 1 && j == oj) || (i == oi - 1 && j == oj) || (i == oi - 1 && j == oj - 1) || (i == oi - 1 && j == oj + 1))
		{
		printf("Invalid movement. Reenter coordinates of token you want to move: ");
		scanf("%i %i", &oi, &oj);
			
		printf("Enter Coordinates of the position: ");
		scanf("%i %i", &i, &j);
		}
	}
		
	if(dboard[i][j] != *tokenx)
	{
		system("cls");
		dboard[oi][oj] = *token0;
		dboard[i][j] = *tokeno;
		display(i, j, dboard);
	}	
	else
	{
		if(dboard[i+1][j+1] == *tokenx || dboard[i+1][j+1] == *tokeno)
		{
			p2move(app_run, x, i, j, oi, oj, dboard, tokeno, token0, tokenx);
		}
		else
		{
			system("cls");
			dboard[oi][oj] = *token0;
			dboard[i][j] = *token0;
			dboard[i+1][j+1] = *tokeno;
			display(i, j, dboard);
		}
	}	
	return app_run;
}

int main()
{
	char player1[50];
	char player2[50];
	char dboard[8][8];
	char tokenx = 'X';
	char tokeno = 'O';
	char token0 = ' ';
	char x;
	
	int i, j, oi, oj;
	int p1 = 0;
	int p2 = 0;
	
	bool app_run = true;
	
	printinit(player1, player2);
	
	printboard(i, j, dboard, &tokenx, &tokeno, &token0);

	while (app_run == true)
	{
		p1select(player1);
		app_run = p1move(app_run, x, i, j, oi, oj, dboard, &tokenx, &token0, &tokeno);
			
		p2select(player2);
		app_run = p2move(app_run, x, i, j, oi, oj, dboard, &tokeno, &token0, &tokenx);
	}
	
	
	
}
