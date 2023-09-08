#include <stdio.h>
#include <stdbool.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check if the game is over
bool isGameOver(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }

    // Check for a tie (no empty spaces left)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // The game is not over yet
            }
        }
    }

    return true; // It's a tie
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    int row, col;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (true) {
        printBoard(board);
        printf("Player %c's turn. Enter row (0-2) and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (isGameOver(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }

        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}
