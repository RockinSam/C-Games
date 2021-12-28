
int isvalidCoordinate(ReversiGame *, int, int);
void getCounts(ReversiGame *);

/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	if (x < 1 || y < 1)
		return NULL;
	ReversiMove *move = (ReversiMove *)malloc(sizeof(ReversiGame) * 100);
	move->x = x - 1;
	move->y = y - 1;
	return move;
}

/*
Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	if (game == NULL)
		return NULL;
	int x, y;
	do{
		fflush(stdin);
		scanf_s("%d", &x);
		scanf_s("%d", &y);
	} while (!isvalidCoordinate(game, x - 1, y - 1));
	ReversiMove *move = createMove(x, y);
	return move;
}


/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if (game == NULL)
		return 0;
	if (x < 0 || y < 0)
		return 0;
	if (x > game->rows || y > game->cols)
		return 0;
	return 1;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move) {
	if (game == NULL)
		return 0;
	if (move == NULL)
		return 0;
	char piece;
	char **board = game->board;
	int x = move->x;
	int y = move->y;
	int i, j;
	if (board[x][y] != ' ')
		return 0;
	if (game->turn == 1)
		piece = 'b';
	else
		piece = 'w';
	if (y < game->cols - 2 && board[x][y + 1] == piece)
	{
		for (j = y + 2; board[x][j] == piece && j < game->cols; j++);
		if (j < game->cols && board[x][j] != ' ')
			return 1;
	}
	if (x < game->rows - 2 && y < game->cols - 2 && board[x + 1][y + 1] == piece)
	{
		for (i = x + 2, j = y + 2; (i < game->rows || j < game->cols) && board[i][j] == piece; i++, j++);
		if (i < game->rows && j < game->cols && board[i][j] != ' ')
			return 1;
	}
	if (x < game->rows - 2 && board[x + 1][y] == piece)
	{
		for (i = x + 2; i < game->rows && board[i][y] == piece; i++);
		if (i < game->rows && board[i][y] != ' ')
			return 1;
	}
	if (x < game->rows - 2 && y > 1 && board[x + 1][y - 1] == piece)
	{
		for (i = x + 2, j = y - 2; (i < game->rows || j >= 0) && board[i][j] == piece; i++, j--);
		if ((i < game->rows || j >= 0) && board[i][j] != ' ')
			return 1;
	}
	if (y > 1 && board[x][y - 1] == piece)
	{
		for (j = y - 2; j >= 0 && board[x][j] == piece; j--);
		if (j >= 0 && board[x][j] != ' ')
			return 1;
	}
	if (x > 1 && y > 1 && board[x - 1][y - 1] == piece)
	{
		for (i = x - 2, j = y - 2; (i >= 0 || j >= 0) && board[i][j] == piece; i--, j--);
		if ((i >= 0 || j >= 0) && board[i][j] != ' ')
			return 1;
	}
	if (x > 1 && board[x - 1][y] == piece)
	{
		for (i = x - 2; i >= 0 && board[i][y] == piece; i--);
		if (i >= 0 && board[i][y] != ' ')
			return 1;
	}
	if (x > 1 && y < game->cols - 2 && board[x - 1][y + 1] == piece)
	{
		for (i = x - 2, j = y + 2; (i >= 0 || j < game->cols) && board[i][j] == piece; i--, j++);
		if ((i >= 0 || j < game->cols) && board[i][j] != ' ')
			return 1;
	}
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	if (game == NULL)
		return 0;
	int x, y, flg = 0;
	ReversiMove *move = (ReversiMove *)malloc(sizeof(ReversiMove) * 100);
	for (x = 0; x < game->rows; x++)
	{
		move->x = x;
		for (y = 0; y < game->cols; y++)
		{
			move->y = y;
			if (game->board[x][y] == ' ')
			{
				if (isValidMove(game, move)){
					flg = 1;
					break;
				}
			}
		}
		if (flg == 1)
			break;
	}
	if (flg == 0)
		return 0;
	else
		return 1;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	if (game == NULL)
		return;
	game->NumberofMoves++;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game == NULL)
		return;
	game->turn *= -1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	if (game == NULL)
		return;
	game->state = 1;
	getCounts(game);
	if (game->blackCount > game->whiteCount)
		game->winner = -1;
	else if (game->blackCount < game->whiteCount)
		game->winner = 1;
	else
		game->winner = 0;
	return;
}

/*
Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	if (game == NULL)
		return;
	getCounts(game);
	incrementMoves(game);
	modifyTurn(game);
}


/*
This function performs move action on the board
Note : call validity check performs using above functions before making a move
returns :
true on move sucess
false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	if (game == NULL)
		return false;
	if (move == NULL)
		return false;
	if (!isValidMove(game, move))
		return false;
	char piece, repiece;
	char **board = game->board;
	int x = move->x;
	int y = move->y;
	int i, j;
	if (game->turn == 1){
		piece = 'b';
		repiece = 'w';
	}
	else{
		piece = 'w';
		repiece = 'b';
	}
	board[x][y] = repiece;
	if (y < game->cols - 2 && board[x][y + 1] == piece)
	{
		for (j = y + 2; j < game->cols && board[x][j] == piece; j++);
		if (j < game->cols && board[x][j] != ' ')
		{
			for (j = y + 1; board[x][j] == piece; j++)
			{
				board[x][j] = repiece;
			}
		}
	}
	if (x < game->rows - 2 && y < game->cols - 2 && board[x + 1][y + 1] == piece)
	{
		for (i = x + 2, j = y + 2; (i < game->rows && j < game->cols) && board[i][j] == piece; i++, j++);
		if ((i < game->rows && j < game->cols) && board[i][j] != ' ')
		{
			for (i = x + 1, j = y + 1; board[i][j] == piece; i++, j++)
			{
				board[i][j] = repiece;
			}
		}
	}
	if (x < game->rows - 2 && board[x + 1][y] == piece)
	{
		for (i = x + 2; i < game->rows && board[i][y] == piece; i++);
		if (i < game->rows && board[i][y] != ' ')
		{
			for (i = x + 1; board[i][y] == piece; i++)
			{
				board[i][y] = repiece;
			}
		}
	}
	if (x < game->rows - 2 && y > 1 && board[x + 1][y - 1] == piece)
	{
		for (i = x + 2, j = y - 2; (i < game->rows && j >= 0) && board[i][j] == piece; i++, j--);
		if ((i < game->rows && j >= 0) && board[i][j] != ' ')
		{
			for (i = x + 1, j = y - 1; board[i][j] == piece; i++, j--)
			{
				board[i][j] = repiece;
			}
		}
	}
	if (y > 1 && board[x][y - 1] == piece)
	{
		for (j = y - 2; j >= 0 && board[x][j] == piece; j--);
		if (j >= 0 && board[x][j] != ' ')
		{
			for (j = y - 1; board[x][j] == piece; j--)
			{
				board[x][j] = repiece;
			}
		}
	}
	if (x > 1 && y > 1 && board[x - 1][y - 1] == piece)
	{
		for (i = x - 2, j = y - 2; (i >= 0 && j >= 0) && board[i][j] == piece; i--, j--);
		if ((i >= 0 && j >= 0) && board[i][j] != ' ')
		{
			for (i = x - 1, j = y - 1; board[i][j] == piece; i--, j--)
			{
				board[i][j] = repiece;
			}
		}
	}
	if (x > 1 && board[x - 1][y] == piece)
	{
		for (i = x - 2; i >= 0 && board[i][y] == piece; i--);
		if (i >= 0 && board[i][y] != ' ')
		{
			for (i = x - 1; board[i][y] == piece; i--)
			{
				board[i][y] = repiece;
			}
		}
	}
	if (x > 1 && y < game->cols - 2 && board[x - 1][y + 1] == piece)
	{
		for (i = x - 2, j = y + 2; (i >= 0 && j < game->cols) && board[i][j] == piece; i--, j++);
		if ((i >= 0 && j < game->cols) && board[i][j] != ' ')
		{
			for (i = x - 1, j = y + 1; board[i][j] == piece; i--, j++)
			{
				board[i][j] = repiece;
			}
		}
	}
	modify(game);
	hasMoveAndModifyTurn(game);
	return true;
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 1)
		printf("\n%s has won. \n", game->player1name);
	else if (game->winner == -1)
		printf("\n%s has won. \n", game->player2name);
	else
		printf("\nGame Drawn. \n");
}

void getCounts(ReversiGame *game)
{
	int x, y;
	game->whiteCount = 0;
	game->blackCount = 0;
	for (x = 0; x < game->rows; x++)
	{
		for (y = 0; y < game->cols; y++)
		{
			if (game->board[x][y] == 'w')
				game->whiteCount++;
			if (game->board[x][y] == 'b')
				game->blackCount++;
		}
	}
}

void hasMoveAndModifyTurn(ReversiGame *game)
{
	if (!hasMove(game))
		modifyTurn(game);
}
