#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define EMPTY ' '
#define HUMAN_VS_HUMAN 1
#define HUMAN_VS_COMPUTER 2

// Function prototypes
void displayBoard(char board[3][3]);
int checkWin(char board[3][3]);
void playerMove(char board[3][3], char symbol);
void computerMove(char board[3][3], char symbol);
bool isMoveValid(char board[3][3], int move);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int choice, result, turn = 0;
    char player1, player2;
    
    // Game Mode Selection
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("1. Human vs Human\n");
    printf("2. Human vs Computer\n");
    printf("Choose a mode (1/2): ");
    scanf("%d", &choice);

    // Player symbol selection
    printf("Do you want to be X or O? (Enter 'X' or 'O'): ");
    getchar();  // to consume the newline character
    scanf("%c", &player1);
    if (player1 == 'X' || player1 == 'x') {
        player1 = 'X';
        player2 = 'O';
    } else {
        player1 = 'O';
        player2 = 'X';
    }

    // Game loop
    do {
        displayBoard(board);
        if (turn % 2 == 0) {
            printf("Player 1's turn (%c)\n", player1);
            playerMove(board, player1);
        } else {
            if (choice == HUMAN_VS_HUMAN) {
                printf("Player 2's turn (%c)\n", player2);
                playerMove(board, player2);
            } else {
                printf("Computer's turn (%c)\n", player2);
                computerMove(board, player2);
            }
        }

        result = checkWin(board);
        turn++;
    } while (result == -1 && turn < 9); // Continue until win or draw

    displayBoard(board);

    if (result == 1) {
        if (turn % 2 == 0)
            printf("Player 2 Wins!\n");
        else
            printf("Player 1 Wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won the game
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return -1; // No winner yet
}

// Function to handle the player's move
void playerMove(char board[3][3], char symbol) {
    int move;
    bool valid = false;
    
    while (!valid) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        if (isMoveValid(board, move)) {
            valid = true;
            board[(move-1)/3][(move-1)%3] = symbol;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

// Function to handle the computer's move
void computerMove(char board[3][3], char symbol) {
    int move;
    bool valid = false;

    while (!valid) {
        move = (rand() % 9) + 1; // Random move between 1 and 9
        if (isMoveValid(board, move)) {
            valid = true;
            board[(move-1)/3][(move-1)%3] = symbol;
        }
    }
}

// Function to check if a move is valid (i.e., if the cell is empty)
bool isMoveValid(char board[3][3], int move) {
    if (move < 1 || move > 9)
        return false;

    return (board[(move-1)/3][(move-1)%3] != 'X' && board[(move-1)/3][(move-1)%3] != 'O');
}
