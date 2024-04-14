#include <stdio.h>
#include <stdlib.h>

// Function to display the game board
void display_board(char board[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a player has won
unsigned char check_board_for_winner(char board[][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0]; // Row win
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i]; // Column win
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0]; // Main diagonal win
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2]; // Secondary diagonal win
    }
    // No winner yet
    return 255;
}

int main() {

    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
    int turn = 1;
    char current_player = 'X';
    int move;
    unsigned char winner = 255;
    char pos;

    printf("*** Welcome to XO Game ***\n");

do{

    pos = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = pos++;
        }
    }
    turn = 1;
    current_player = 'X';
    winner = 255;

    // Game loop
    while (turn <= 9 && winner == 255) {
        // Display the board
        display_board(board);
        // Prompt player for input
        printf("Player %c's turn. Enter a position (1-9): ", current_player);
        scanf("%d", &move);

        // Update the board
        if (board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O') {
            printf("Invalid move! Position already taken.\n");
            continue;
        } else
            board[(move - 1) / 3][(move - 1) % 3] = current_player;

        // Check for a winner
        winner = check_board_for_winner(board);

        // Switch player
        current_player = (current_player == 'X') ? 'O' : 'X';

        turn++;
    }

    // Display final board
    display_board(board);

    // Print result
    if (winner == 'X' || winner == 'O')
        printf("Player %c wins!\n", winner);
    else
        printf("  It's a draw! \n=== New Game ===");


} while (winner == 255);

    return 0;
}
