/*
 * ============================================
 *   Advanced Calculator in C
 *   Author: Your Name
 *   Description: A fully functional calculator
 *                supporting basic & advanced ops
 * ============================================
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void display_menu() {
    printf("\n╔══════════════════════════════╗\n");
    printf("║      ADVANCED CALCULATOR     ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("║  1. Addition                 ║\n");
    printf("║  2. Subtraction              ║\n");
    printf("║  3. Multiplication           ║\n");
    printf("║  4. Division                 ║\n");
    printf("║  5. Modulus                  ║\n");
    printf("║  6. Power (x^y)              ║\n");
    printf("║  7. Square Root              ║\n");
    printf("║  8. Factorial                ║\n");
    printf("║  0. Exit                     ║\n");
    printf("╚══════════════════════════════╝\n");
    printf("Choose an option: ");
}

long long factorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

int main() {
    int choice;
    double a, b, result;

    printf("\n Welcome to Advanced C Calculator!\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\n Thanks for using the calculator! Bye!\n\n");
            break;
        }

        if (choice == 7) {
            printf("Enter number: ");
            scanf("%lf", &a);
            if (a < 0) { printf(" Error: Cannot take sqrt of negative number!\n"); continue; }
            printf(" Result: √%.2lf = %.4lf\n", a, sqrt(a));
            continue;
        }

        if (choice == 8) {
            int n;
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);
            long long f = factorial(n);
            if (f == -1) printf(" Error: Factorial not defined for negative numbers!\n");
            else printf(" Result: %d! = %lld\n", n, f);
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);

        switch (choice) {
            case 1: result = a + b; printf(" Result: %.2lf + %.2lf = %.4lf\n", a, b, result); break;
            case 2: result = a - b; printf(" Result: %.2lf - %.2lf = %.4lf\n", a, b, result); break;
            case 3: result = a * b; printf(" Result: %.2lf × %.2lf = %.4lf\n", a, b, result); break;
            case 4:
                if (b == 0) { printf(" Error: Division by zero!\n"); break; }
                result = a / b;
                printf(" Result: %.2lf ÷ %.2lf = %.4lf\n", a, b, result);
                break;
            case 5:
                if ((int)b == 0) { printf(" Error: Modulus by zero!\n"); break; }
                printf(" Result: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                break;
            case 6:
                result = pow(a, b);
                printf(" Result: %.2lf ^ %.2lf = %.4lf\n", a, b, result);
                break;
            default: printf(" Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
