/*
 * ============================================
 *   Matrix Operations in C
 *   Features: Add, Subtract, Multiply,
 *             Transpose, Determinant, Trace
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct { int rows, cols; double data[MAX][MAX]; } Matrix;

void input_matrix(Matrix *m, char *name) {
    printf("  Enter rows and cols for Matrix %s (max %d): ", name, MAX);
    scanf("%d %d", &m->rows, &m->cols);
    printf("  Enter elements:\n");
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++) {
            printf("  [%d][%d]: ", i+1, j+1);
            scanf("%lf", &m->data[i][j]);
        }
}

void print_matrix(Matrix *m, char *label) {
    printf("\n  %s:\n", label);
    for (int i = 0; i < m->rows; i++) {
        printf("  │");
        for (int j = 0; j < m->cols; j++) printf(" %7.2f", m->data[i][j]);
        printf(" │\n");
    }
}

void add_matrices() {
    Matrix A, B, C;
    input_matrix(&A, "A");
    input_matrix(&B, "B");
    if (A.rows != B.rows || A.cols != B.cols) { printf("  ✗ Dimensions don't match!\n"); return; }
    C.rows = A.rows; C.cols = A.cols;
    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            C.data[i][j] = A.data[i][j] + B.data[i][j];
    print_matrix(&A, "Matrix A");
    print_matrix(&B, "Matrix B");
    print_matrix(&C, "A + B");
}

void subtract_matrices() {
    Matrix A, B, C;
    input_matrix(&A, "A"); input_matrix(&B, "B");
    if (A.rows != B.rows || A.cols != B.cols) { printf("  ✗ Dimensions don't match!\n"); return; }
    C.rows = A.rows; C.cols = A.cols;
    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            C.data[i][j] = A.data[i][j] - B.data[i][j];
    print_matrix(&C, "A - B");
}

void multiply_matrices() {
    Matrix A, B, C;
    input_matrix(&A, "A"); input_matrix(&B, "B");
    if (A.cols != B.rows) { printf("  ✗ Cannot multiply: A cols must equal B rows!\n"); return; }
    C.rows = A.rows; C.cols = B.cols;
    for (int i = 0; i < C.rows; i++)
        for (int j = 0; j < C.cols; j++) {
            C.data[i][j] = 0;
            for (int k = 0; k < A.cols; k++)
                C.data[i][j] += A.data[i][k] * B.data[k][j];
        }
    print_matrix(&A, "Matrix A");
    print_matrix(&B, "Matrix B");
    print_matrix(&C, "A × B");
}

void transpose_matrix() {
    Matrix A, T;
    input_matrix(&A, "A");
    T.rows = A.cols; T.cols = A.rows;
    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            T.data[j][i] = A.data[i][j];
    print_matrix(&A, "Original");
    print_matrix(&T, "Transpose");
}

double determinant(double mat[][MAX], int n) {
    if (n == 1) return mat[0][0];
    if (n == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    double det = 0;
    double sub[MAX][MAX];
    for (int c = 0; c < n; c++) {
        int si = 0;
        for (int i = 1; i < n; i++) {
            int sj = 0;
            for (int j = 0; j < n; j++) {
                if (j == c) continue;
                sub[si][sj++] = mat[i][j];
            }
            si++;
        }
        det += (c%2==0 ? 1 : -1) * mat[0][c] * determinant(sub, n-1);
    }
    return det;
}

void matrix_determinant() {
    Matrix A;
    input_matrix(&A, "A");
    if (A.rows != A.cols) { printf("  ✗ Determinant only for square matrices!\n"); return; }
    printf("  det(A) = %.4f\n", determinant(A.data, A.rows));
}

void matrix_trace() {
    Matrix A;
    input_matrix(&A, "A");
    if (A.rows != A.cols) { printf("  ✗ Trace only for square matrices!\n"); return; }
    double trace = 0;
    for (int i = 0; i < A.rows; i++) trace += A.data[i][i];
    printf("  Trace(A) = %.4f\n", trace);
}

void show_menu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║       MATRIX OPERATIONS          ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Add Matrices                 ║\n");
    printf("║  2. Subtract Matrices            ║\n");
    printf("║  3. Multiply Matrices            ║\n");
    printf("║  4. Transpose                    ║\n");
    printf("║  5. Determinant                  ║\n");
    printf("║  6. Trace                        ║\n");
    printf("║  0. Exit                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    int choice;
    printf("\n  Welcome to Matrix Operations!\n");
    while (1) {
        show_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        switch (choice) {
            case 1: add_matrices();        break;
            case 2: subtract_matrices();   break;
            case 3: multiply_matrices();   break;
            case 4: transpose_matrix();    break;
            case 5: matrix_determinant();  break;
            case 6: matrix_trace();        break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
