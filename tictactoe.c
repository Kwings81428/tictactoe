#include <stdio.h>
#include <stdbool.h>

#define ROW 5  
#define COLUMN 5
#define MAX_BOARD_SPACES 9

void printBoard(int array[ROW][COLUMN]); // Prints the tictactoe gameboard.
void playerinput(int row, int column,int player); // takes in the user input from terminal.
void mapping(int userinput, int* row, int* column); // maps coordinates of multi-dimentional array to an interger 

int checkUsedSpaces(int array[ROW][COLUMN]); // checks gameboard for the total used spaces

bool checkForWinner(int array[ROW][COLUMN],int usedspaces); // Checks for a winner or draw 
bool freeSpaceCheck(int row, int column); // checks if the slected user input location is free.

int gameBoard[ROW][COLUMN] = { 
        {'1','|','2','|','3'},
        {'_','_','_','_','_'},
        {'4','|','5','|','6'},
        {'_','_','_','_','_'},
        {'7','|','8','|','9'},
    };

/*Main Code that takes input from a player for Tic Tac Toe game*/
int main(){
	int userinput,row,column,usedspaces;
    int player = 1; 
    bool spaceAvailable;
    bool winner = false;

    printf("Welcome to Tick Tac Toe\n");
    printf("X always goes first... X's Turn\n");
    printf("Below is the input locations numbered 1-9\n");
    printBoard(gameBoard);
    
    while(winner == false)
    {	
		/* keeps user here until free slot selected */
		while (spaceAvailable != true) 
		{
			printf("Input a location(1-9): ");
			userinput = getchar();
			while (getchar() != '\n'){};
			mapping(userinput,&row,&column);
			spaceAvailable = freeSpaceCheck(row,column);
		}
		playerinput(row,column,player);
		player = 1 - player; // toggles between players 
		usedspaces = checkUsedSpaces(gameBoard);
		winner = checkForWinner(gameBoard,usedspaces);
		spaceAvailable = false;	
    }

}

/*  This prints the updated version of the gameboard */
void printBoard(int array[ROW][COLUMN]){
    for (int i = 0; i < ROW ; i++)
    {
        for(int j = 0; j < COLUMN ; j++)
        {
            putchar(array[i][j]);
        }
        printf("\n");
    }
}

bool freeSpaceCheck(int row, int column){	
	bool usedspaceFlag = true;
	if (gameBoard[row][column] == 'O' || gameBoard[row][column] == 'X')
	{
        printf("ERROR: Space already used or Invalid entry, try again.\n");
        usedspaceFlag = false;
    }
    return usedspaceFlag;
	
}

/* This intakes the row and column selection of player X and  also check if a space is already in use */
void playerinput(int row, int column,int player){
    if (player == 1)
    {
		gameBoard[row][column] = 'X';
		printf("O's Turn\n");
	}
	if (player == 0)
	{
        gameBoard[row][column] = 'O';
        printf("X's Turn\n");
    }
    printf("Result");
    printf("\n");
    printBoard(gameBoard);
}

/*  This checks the available spaces left free in the gameboard and returns the number of spaces used */
int checkUsedSpaces(int array[ROW][COLUMN])
{
    int usedspaces = 0;
    for (int i = 0; i < ROW ; i++)
    {
		for(int j = 0; j < COLUMN; j++)
		{
			if (array[i][j] == 'X' || array[i][j] == 'O')
				usedspaces++;
		}
    }
    return usedspaces;
}

/* This checks if player X has 3 X's in a line */
bool checkForWinner(int array[ROW][COLUMN], int usedspaces)
{
	bool winner = false; 
	bool winO = false;
    bool winX = false;
    for(int i = 0 ; i < 5 ; i=i+2 )
    {
        if (array[i][0] == 'X' && array[i][2] == 'X' && array[i][4] == 'X') {winX = true;} 
        if (array[0][i] == 'X' && array[2][i] == 'X' && array[4][i] == 'X') {winX = true;}
        if (array[0][0] == 'X' && array[2][2] == 'X' && array[4][4] == 'X') {winX = true;}
        if (array[4][0] == 'X' && array[2][2] == 'X' && array[0][4] == 'X') {winX = true;} 
    }
    for(int i = 0 ;i < 5 ; i=i+2)
    {
        if (array[i][0] == 'O' && array[i][2] == 'O' && array[i][4] == 'O') {winO = true;} 
        if (array[0][i] == 'O' && array[2][i] == 'O' && array[4][i] == 'O') {winO = true;}
        if (array[0][0] == 'O' && array[2][2] == 'O' && array[4][4] == 'O') {winO = true;}
        if (array[4][0] == 'O' && array[2][2] == 'O' && array[0][4] == 'O') {winO = true;}   
    }
    if (winO == true){
		printf("O WINS!!! \n");
		winner = true;
	} 
    if (winX == true){
		printf("X WINS!!! \n");
		winner = true;
	}
	if (usedspaces == 9 && winX == false && winO == false){ 
		printf("THIS GAME IS A DRAW\n");
		winner = true; 
	}
		
	return winner;
}

void mapping(int userinput, int* row, int* column)
{
	switch (userinput)
	{
		case '1':
			*row = 0;
			*column = 0;
			break;
		case '2':
			*row = 0;
			*column = 2;
			break;
		case '3':
			*row = 0;
			*column = 4;
			break;
		case '4':
			*row = 2;
			*column = 0;
			break;
		case '5':
			*row = 2;
			*column = 2;
			break;
		case '6':
			*row = 2;
			*column = 4;
			break;
		case '7':
			*row = 4;
			*column = 0;
			break;
		case '8':
			*row = 4;
			*column = 2;
			break;
		case '9':
			*row = 4;
			*column = 4;
			break;
		default:
			break;
	}			
		
}



