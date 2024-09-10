#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* Declaração de variáveis globais */
char board[3][3];  // Matriz para representar o tabuleiro
const char PLAYER = 'X';  // Jogador humano usa 'X'
const char COMPUTER = 'O';  // Computador usa 'O'

/* Declaração de funções */
void resetBoard();
void printBoard();
int checkFreeSpaces();  // Função retorna um int para contar espaços livres
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

/* Função principal */
int main() {
    char winner = ' ';  // Variável para armazenar o vencedor

    resetBoard();  // Inicializa o tabuleiro

    // Loop principal do jogo
    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();  // Imprime o tabuleiro

        playerMove();  // Jogador faz a jogada
        winner = checkWinner();  // Verifica se há vencedor
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;  // Sai do loop se houver vencedor ou não houver mais espaços livres
        }

        computerMove();  // Computador faz sua jogada
        winner = checkWinner();  // Verifica novamente o vencedor
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;  // Sai do loop se houver vencedor ou não houver mais espaços livres
        }
    }

    printBoard();  // Mostra o tabuleiro final
    printWinner(winner);  // Exibe o vencedor

    return 0;
}

/* Função para reiniciar o tabuleiro (preencher com espaços vazios) */
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';  // Preenche o tabuleiro com espaços
        }
    }
}

/* Função para imprimir o tabuleiro atual */
void printBoard() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/* Função que conta os espaços livres no tabuleiro */
int checkFreeSpaces() {
    int freeSpaces = 9;  // Começamos com 9 espaços livres

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {  // Diminui se o espaço já estiver ocupado
                freeSpaces--;
            }
        }
    }
    return freeSpaces;  // Retorna o número de espaços livres
}

/* Função para a jogada do jogador */
void playerMove() {
    int x, y;

    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);  // Lê a linha
        x--;  // Ajusta o índice (de 1-3 para 0-2)
        
        printf("Enter column #(1-3): ");
        scanf("%d", &y);  // Lê a coluna
        y--;  // Ajusta o índice (de 1-3 para 0-2)

        if (board[x][y] != ' ') {  // Verifica se o espaço está ocupado
            printf("Invalid Move!\n");  // Mensagem de erro se o espaço não estiver livre
        } else {
            board[x][y] = PLAYER;  // Marca a jogada do jogador no tabuleiro
            break;
        }
    } while (board[x][y] != ' ');  // Continua até o jogador escolher um espaço livre
}

/* Função para a jogada do computador */
void computerMove() {
    srand(time(0));  // Cria uma semente baseada no tempo atual
    int x, y;

    if (checkFreeSpaces() > 0) {  // Verifica se há espaços disponíveis
        do {
            x = rand() % 3;  // Escolhe uma linha aleatória
            y = rand() % 3;  // Escolhe uma coluna aleatória
        } while (board[x][y] != ' ');  // Repete até encontrar um espaço livre

        board[x][y] = COMPUTER;  // Marca a jogada do computador no tabuleiro
    } else {
        printWinner(' ');  // Se não houver espaços, imprime empate
    }
}

/* Função para verificar se há um vencedor */
char checkWinner() {
    // Verifica as linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];  // Retorna o símbolo vencedor
        }
    }
    // Verifica as colunas
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];  // Retorna o símbolo vencedor
        }
    }
    // Verifica as diagonais
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];  // Retorna o símbolo vencedor da diagonal principal
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];  // Retorna o símbolo vencedor da diagonal secundária
    }

    return ' ';  // Retorna espaço se não houver vencedor
}

/* Função para imprimir o vencedor */
void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN!\n");  // O jogador ganhou
    } else if (winner == COMPUTER) {
        printf("YOU LOSE!\n");  // O computador ganhou
    } else {
        printf("IT'S A TIE!\n");  // Empate
    }
}

// Credits for Channel in Youtube CODE BRO