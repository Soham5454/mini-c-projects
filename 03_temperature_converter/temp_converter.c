/*
 * ============================================
 *   Temperature Converter in C
 *   Converts between Celsius, Fahrenheit,
 *   Kelvin, and Rankine
 * ============================================
 */

#include <stdio.h>

void display_menu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║      TEMPERATURE CONVERTER       ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Celsius    → All             ║\n");
    printf("║  2. Fahrenheit → All             ║\n");
    printf("║  3. Kelvin     → All             ║\n");
    printf("║  4. Rankine    → All             ║\n");
    printf("║  0. Exit                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Choice: ");
}

void from_celsius(double c) {
    double f = c * 9.0 / 5.0 + 32;
    double k = c + 273.15;
    double r = (c + 273.15) * 9.0 / 5.0;
    printf("\n  %.2f°C =\n", c);
    printf("    🌡  Fahrenheit : %.4f °F\n", f);
    printf("    🌡  Kelvin     : %.4f K\n",  k);
    printf("    🌡  Rankine    : %.4f °R\n", r);
}

void from_fahrenheit(double f) {
    double c = (f - 32) * 5.0 / 9.0;
    double k = (f + 459.67) * 5.0 / 9.0;
    double r = f + 459.67;
    printf("\n  %.2f°F =\n", f);
    printf("    🌡  Celsius    : %.4f °C\n", c);
    printf("    🌡  Kelvin     : %.4f K\n",  k);
    printf("    🌡  Rankine    : %.4f °R\n", r);
}

void from_kelvin(double k) {
    if (k < 0) { printf("  ✗ Kelvin cannot be negative!\n"); return; }
    double c = k - 273.15;
    double f = k * 9.0 / 5.0 - 459.67;
    double r = k * 9.0 / 5.0;
    printf("\n  %.2f K =\n", k);
    printf("    🌡  Celsius    : %.4f °C\n", c);
    printf("    🌡  Fahrenheit : %.4f °F\n", f);
    printf("    🌡  Rankine    : %.4f °R\n", r);
}

void from_rankine(double r) {
    if (r < 0) { printf("  ✗ Rankine cannot be negative!\n"); return; }
    double k = r * 5.0 / 9.0;
    double c = (r - 491.67) * 5.0 / 9.0;
    double f = r - 459.67;
    printf("\n  %.2f°R =\n", r);
    printf("    🌡  Celsius    : %.4f °C\n", c);
    printf("    🌡  Fahrenheit : %.4f °F\n", f);
    printf("    🌡  Kelvin     : %.4f K\n",  k);
}

int main() {
    int choice;
    double temp;
    printf("\n  Welcome to Temperature Converter!\n");
    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        printf("  Enter temperature value: ");
        scanf("%lf", &temp);
        switch (choice) {
            case 1: from_celsius(temp);    break;
            case 2: from_fahrenheit(temp); break;
            case 3: from_kelvin(temp);     break;
            case 4: from_rankine(temp);    break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
