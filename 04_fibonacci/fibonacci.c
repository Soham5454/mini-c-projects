/*
 * ============================================
 *   Fibonacci Explorer in C
 *   Features: Series, Nth term, Golden Ratio,
 *             Recursive vs Iterative comparison
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fib_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) { c = a + b; a = b; b = c; }
    return b;
}

long long fib_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

void print_series(int n) {
    printf("\n  Fibonacci Series (first %d terms):\n  ", n);
    long long a = 0, b = 1, c;
    printf("%lld", a);
    if (n > 1) printf(", %lld", b);
    for (int i = 2; i < n; i++) {
        c = a + b; a = b; b = c;
        printf(", %lld", b);
    }
    printf("\n");
}

void golden_ratio(int n) {
    printf("\n  Golden Ratio approximations (φ ≈ 1.6180339...):\n");
    long long a = 1, b = 1, c;
    for (int i = 2; i <= n && i <= 20; i++) {
        c = a + b;
        printf("  F(%2d)/F(%2d) = %lld/%lld = %.10f\n", i, i - 1, c, b, (double)c / b);
        a = b; b = c;
    }
}

void compare_methods(int n) {
    if (n > 40) { printf("  ✗ Too large for recursive (max 40)!\n"); return; }
    clock_t s1 = clock();
    long long r1 = fib_iterative(n);
    clock_t e1 = clock();

    clock_t s2 = clock();
    long long r2 = fib_recursive(n);
    clock_t e2 = clock();

    printf("\n  Fibonacci(%d) = %lld\n", n, r1);
    printf("  ┌──────────────┬──────────────┬───────────────────┐\n");
    printf("  │ Method       │ Result       │ Time (µs)         │\n");
    printf("  ├──────────────┼──────────────┼───────────────────┤\n");
    printf("  │ Iterative    │ %-12lld │ %-17ld │\n", r1, (e1 - s1));
    printf("  │ Recursive    │ %-12lld │ %-17ld │\n", r2, (e2 - s2));
    printf("  └──────────────┴──────────────┴───────────────────┘\n");
    printf("  Iterative is O(n), Recursive is O(2^n) — much slower!\n");
}

void display_menu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║       FIBONACCI EXPLORER         ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Print Fibonacci Series       ║\n");
    printf("║  2. Find Nth Fibonacci Number    ║\n");
    printf("║  3. Golden Ratio Approximation   ║\n");
    printf("║  4. Compare Iterative vs Recurse ║\n");
    printf("║  0. Exit                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    int choice, n;
    printf("\n  Welcome to Fibonacci Explorer!\n");
    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        printf("  Enter N: ");
        scanf("%d", &n);
        if (n <= 0) { printf("  ✗ Please enter a positive number!\n"); continue; }
        switch (choice) {
            case 1: print_series(n); break;
            case 2: printf("\n  Fibonacci(%d) = %lld\n", n, fib_iterative(n)); break;
            case 3: golden_ratio(n); break;
            case 4: compare_methods(n); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
