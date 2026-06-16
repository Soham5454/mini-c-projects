/*
 * ============================================
 *   Sorting Algorithms Visualizer in C
 *   Description: Bubble, Selection, Insertion,
 *                Merge & Quick Sort with step count
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

void print_array(int arr[], int n, char *label) {
    printf("  %-12s: [", label);
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]);
        if (i < n - 1) printf(",");
    }
    printf(" ]\n");
}

void copy_array(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

long long bubble_sort(int arr[], int n) {
    long long steps = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = tmp;
            }
        }
    return steps;
}

long long selection_sort(int arr[], int n) {
    long long steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) { steps++; if (arr[j] < arr[min_idx]) min_idx = j; }
        int tmp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = tmp;
    }
    return steps;
}

long long insertion_sort(int arr[], int n) {
    long long steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) { steps++; arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
    return steps;
}

long long merge_steps = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[MAX], R[MAX];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) { merge_steps++; arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort_helper(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort_helper(arr, l, m);
        merge_sort_helper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

long long quick_steps = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        quick_steps++;
        if (arr[j] < pivot) { i++; int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp; }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

int main() {
    int original[MAX], arr[MAX];
    int n;

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║     SORTING ALGORITHMS SHOWCASE      ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) { printf("Invalid size!\n"); return 1; }

    printf("Choose input method:\n  1. Manual input\n  2. Random array\nChoice: ");
    int method; scanf("%d", &method);

    if (method == 1) {
        printf("Enter %d numbers: ", n);
        for (int i = 0; i < n; i++) scanf("%d", &original[i]);
    } else {
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++) original[i] = rand() % 100 + 1;
    }

    printf("\n");
    print_array(original, n, "Original");
    printf("\n  %-18s %-35s %s\n", "Algorithm", "Sorted Array", "Steps");
    printf("  %s\n", "──────────────────────────────────────────────────────────────");

    // Bubble Sort
    copy_array(original, arr, n);
    long long s1 = bubble_sort(arr, n);
    printf("  %-18s ", "Bubble Sort");
    print_array(arr, n, "");
    printf("  %-18s Steps: %lld | Complexity: O(n²)\n\n", "", s1);

    // Selection Sort
    copy_array(original, arr, n);
    long long s2 = selection_sort(arr, n);
    printf("  %-18s ", "Selection Sort");
    print_array(arr, n, "");
    printf("  %-18s Steps: %lld | Complexity: O(n²)\n\n", "", s2);

    // Insertion Sort
    copy_array(original, arr, n);
    long long s3 = insertion_sort(arr, n);
    printf("  %-18s ", "Insertion Sort");
    print_array(arr, n, "");
    printf("  %-18s Steps: %lld | Complexity: O(n²)\n\n", "", s3);

    // Merge Sort
    copy_array(original, arr, n);
    merge_steps = 0;
    merge_sort_helper(arr, 0, n - 1);
    printf("  %-18s ", "Merge Sort");
    print_array(arr, n, "");
    printf("  %-18s Steps: %lld | Complexity: O(n log n)\n\n", "", merge_steps);

    // Quick Sort
    copy_array(original, arr, n);
    quick_steps = 0;
    quick_sort_helper(arr, 0, n - 1);
    printf("  %-18s ", "Quick Sort");
    print_array(arr, n, "");
    printf("  %-18s Steps: %lld | Complexity: O(n log n) avg\n\n", "", quick_steps);

    return 0;
}
