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

}

int checkFreeSpaces()
{

}

void playerMove()
{

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

