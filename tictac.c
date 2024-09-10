#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

/* Declared global variables */
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


/* Declared functions before main */
void resetBoard();
void printBoard();
void checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

/* Main in program */
int main()
{
    char winner = ' ';

    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();
    }


    return 0;
}


/* Adding functions for my program*/

void resetBoard()
{
    for(int i = 0; i < 3; i++)
    {   
        for(int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;

    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid Move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{

}

char checkWinner()
{

}

void printWinner(char)
{

}

