/*
 * ============================================
 *   Number Guessing Game in C
 *   Description: Guess the secret number with
 *                hints, difficulty levels & scoring
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int max_number;
    int max_attempts;
    char *label;
} Difficulty;

void print_banner() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║      NUMBER GUESSING GAME        ║\n");
    printf("╚══════════════════════════════════╝\n");
}

int calculate_score(int attempts, int max_attempts) {
    int base = 1000;
    int penalty = (attempts - 1) * (base / max_attempts);
    int score = base - penalty;
    return score > 0 ? score : 10;
}

int main() {
    srand((unsigned int)time(NULL));

    Difficulty levels[3] = {
        {50,  10, "EASY"},
        {100, 7,  "MEDIUM"},
        {500, 5,  "HARD"}
    };

    print_banner();

    int level_choice;
    printf("\nSelect Difficulty:\n");
    printf("  1. Easy   (1–50,  10 attempts)\n");
    printf("  2. Medium (1–100,  7 attempts)\n");
    printf("  3. Hard   (1–500,  5 attempts)\n");
    printf("Your choice: ");
    scanf("%d", &level_choice);

    if (level_choice < 1 || level_choice > 3) level_choice = 2;
    Difficulty d = levels[level_choice - 1];

    int secret = (rand() % d.max_number) + 1;
    int guess, attempts = 0;
    int won = 0;

    printf("\n[%s MODE] Guess a number between 1 and %d!\n", d.label, d.max_number);
    printf("You have %d attempts. Good luck!\n\n", d.max_attempts);

    while (attempts < d.max_attempts) {
        printf("Attempt %d/%d → Enter guess: ", attempts + 1, d.max_attempts);
        scanf("%d", &guess);
        attempts++;

        if (guess == secret) {
            won = 1;
            break;
        } else if (guess < secret) {
            int diff = secret - guess;
            if (diff > 50)       printf("  Way too LOW! 🔽🔽\n");
            else if (diff > 10)  printf("  Too LOW! 🔽\n");
            else                 printf("  Just a bit LOW! ↗\n");
        } else {
            int diff = guess - secret;
            if (diff > 50)       printf("  Way too HIGH! 🔼🔼\n");
            else if (diff > 10)  printf("  Too HIGH! 🔼\n");
            else                 printf("  Just a bit HIGH! ↘\n");
        }

        if (attempts < d.max_attempts)
            printf("  [%d attempts remaining]\n\n", d.max_attempts - attempts);
    }

    printf("\n══════════════════════════════════\n");
    if (won) {
        int score = calculate_score(attempts, d.max_attempts);
        printf("  🎉 CORRECT! The number was %d!\n", secret);
        printf("  You got it in %d attempt(s)!\n", attempts);
        printf("  🏆 Your Score: %d points\n", score);
    } else {
        printf("  💀 GAME OVER! The number was %d.\n", secret);
        printf("  Better luck next time!\n");
    }
    printf("══════════════════════════════════\n\n");

    return 0;
}
