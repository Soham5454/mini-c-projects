/*
 * ============================================
 *   Tic Tac Toe in C
 *   Features: 2-player mode, AI mode,
 *             score tracking, replay
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int score_x = 0, score_o = 0, draws = 0;

void init_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j;
}

void print_board() {
    printf("\n");
    printf("     1   2   3\n");
    printf("   ┌───┬───┬───┐\n");
    for (int i = 0; i < 3; i++) {
        printf(" %d │", i + 1);
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')       printf(" X ");
            else if (board[i][j] == 'O')  printf(" O ");
            else printf(" %c ", board[i][j]);
            if (j < 2) printf("│");
        }
        printf("│\n");
        if (i < 2) printf("   ├───┼───┼───┤\n");
    }
    printf("   └───┴───┴───┘\n");
}

int check_win(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return 1;
        if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return 1;
    }
    if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return 1;
    if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return 1;
    return 0;
}

int is_full() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
    return 1;
}

int make_move(int cell, char player) {
    int row = (cell - 1) / 3, col = (cell - 1) % 3;
    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') return 0;
    board[row][col] = player;
    return 1;
}

void ai_move() {
    // Try to win
    for (int i = 1; i <= 9; i++) {
        int r = (i-1)/3, c = (i-1)%3;
        if (board[r][c]!='X' && board[r][c]!='O') {
            board[r][c]='O';
            if (check_win('O')) return;
            board[r][c]='1'+i-1;
        }
    }
    // Block player
    for (int i = 1; i <= 9; i++) {
        int r = (i-1)/3, c = (i-1)%3;
        if (board[r][c]!='X' && board[r][c]!='O') {
            board[r][c]='X';
            if (check_win('X')) { board[r][c]='O'; return; }
            board[r][c]='1'+i-1;
        }
    }
    // Take center
    if (board[1][1]!='X' && board[1][1]!='O') { board[1][1]='O'; return; }
    // Random
    srand((unsigned)time(NULL));
    int cell;
    do { cell = rand()%9+1; } while (!make_move(cell, 'O'));
}

void print_scores() {
    printf("\n  ┌─────────────────────┐\n");
    printf("  │  SCORES             │\n");
    printf("  │  X: %-3d  O: %-3d     │\n", score_x, score_o);
    printf("  │  Draws: %-3d         │\n", draws);
    printf("  └─────────────────────┘\n");
}

int main() {
    int mode, cell, move_count;
    char current;
    char play_again = 'y';

    printf("\n╔══════════════════════════════╗\n");
    printf("║        TIC TAC TOE           ║\n");
    printf("╚══════════════════════════════╝\n");

    printf("\nSelect Mode:\n  1. Two Player\n  2. vs AI\nChoice: ");
    scanf("%d", &mode);

    while (play_again == 'y' || play_again == 'Y') {
        init_board();
        current = 'X';
        move_count = 0;
        int game_over = 0;

        while (!game_over) {
            print_board();
            print_scores();

            if (mode == 2 && current == 'O') {
                printf("\n  AI is thinking...\n");
                ai_move();
            } else {
                printf("\n  Player %c's turn. Enter cell (1-9): ", current);
                scanf("%d", &cell);
                if (!make_move(cell, current)) { printf("  ✗ Invalid move! Try again.\n"); continue; }
            }

            move_count++;

            if (check_win(current)) {
                print_board();
                printf("\n  🎉 Player %c WINS!\n", current);
                if (current == 'X') score_x++; else score_o++;
                game_over = 1;
            } else if (is_full()) {
                print_board();
                printf("\n  🤝 It's a DRAW!\n");
                draws++;
                game_over = 1;
            } else {
                current = (current == 'X') ? 'O' : 'X';
            }
        }

        print_scores();
        printf("\n  Play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("\n  Thanks for playing!\n\n");
    return 0;
}
