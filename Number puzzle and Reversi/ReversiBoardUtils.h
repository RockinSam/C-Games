#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;

int checkReversiGameOver(ReversiGame *);
void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);
void getCounts(ReversiGame *);
void modify(ReversiGame *game);
void hasMoveAndModifyTurn(ReversiGame *);

/*

Create a new ReversiGame By allocating memory from Heap , Let it be game;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to game->board;

Note : Return NULL for Invalid Inputs
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy player1name,player2name.
*/

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	if (player1 == NULL || player2 == NULL)
		return NULL;
	if (player1[0] == 0 || player2[0] == 0)
		return NULL;
	if (rows < 1 || cols < 1)
		return NULL;
	if (rows != cols)
		return NULL;
	ReversiGame *game = (ReversiGame *)malloc(sizeof(ReversiGame) * 100);
	char **board = (char **)malloc(sizeof(char *) * 100);
	for (int i = 0; i < rows + 1; i++)
		board[i] = (char *)malloc(sizeof(char) * 100);
	game->board = board;
	game->rows = rows;
	game->cols = cols;
	game->player1name = player1;
	game->player2name = player2;
	return game;
}


/*
Copy the tobeCopied Array into game->board .
Learn how to Copy a 2D array when address of first row is given.
Note this function is called in the following way

Also Initialize the turn variable, whiteCount with no of white coins and same for black.

Do Nothing for Invalid Inputs
*/

void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	if (game == NULL || tobeCopiedBoard == NULL)
		return;
	if (rows < 1 || cols < 1)
		return;
	char *tmp;
	for (int i = 0; i < rows; i++){
		tmp = tobeCopiedBoard + i * cols + i;
		game->board[i] = tmp;
	}
	game->turn = turn;
	game->blackCount = 0;
	game->whiteCount = 0;
	game->NumberofMoves = 0;
	game->state = 0;
	game->rows = rows;
	game->cols = cols;
	getCounts(game);
	checkReversiGameOver(game);
	hasMoveAndModifyTurn(game);
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)

*/

int checkReversiGameOver(ReversiGame *game){
	if (game == NULL){
		endGame(game);
		return 0;
	}
	if (game->blackCount + game->whiteCount == game->cols * game->rows){
		endGame(game);
		return 0;
	}
	if (hasMove(game) == 0){
		modifyTurn(game);
		if (hasMove(game) == 0){
			modifyTurn(game);
			endGame(game);
			return 0;
		}
		modifyTurn(game);
	}
	return 1;
}

void printMoves(ReversiGame *game){
	/*
	Sample output :
	Whites Count : 5
	Black Count : 4
	Move Count : 9
	*/
	if (game == NULL)
		return;
	char *str;
	printf("\n	White count : %d\n", game->whiteCount);
	printf("\n	Black count : %d\n", game->blackCount);
	printf("\n	Move count : %d\n\n\n", game->NumberofMoves);
	if (game->turn == 1)
		str = game->player1name;
	else
		str = game->player2name;
	printf("---------------------------------------\n	%s's chance : ", str);
	return;
}

/*
Print the Board in a Good Way.Make sure Each Number is properly formatted and Seperated, and Row lines too .
Print Empty Space when you encounter 0.Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking / UI Skills .
See the link we shared for sample screenshots for inspiration.
*/

void drawBoardOnScreen(ReversiGame *game){
	if (game == NULL)
		return;
	int x, y;
	printf("\n\n\n\n	");
	for (x = 0; x < game->cols; x++)
		printf("	%d", x + 1);
	printf("\n\n\n\n");
	for (x = 0; x < game->rows; x++)
	{
		printf("	%d", x + 1);
		for (y = 0; y < game->cols; y++)
		{
			if (game->board[x][y] == ' ')
				printf("	.");
			else
				printf("	%c", game->board[x][y]);
		}
		printf("\n\n\n\n");
	}
	return;
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/

void clearScreen(ReversiGame *game){
	if (game == NULL)
		return;
	system("cls");
}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/

void clearAndRedrawScreen(ReversiGame *game){
	if (game == NULL)
		return;
	clearScreen(game);
	drawBoardOnScreen(game);
}
