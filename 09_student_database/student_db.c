/*
 * ============================================
 *   Student Database Management System in C
 *   Features: Add, View, Search, Update,
 *             Delete, Sort, Save to file
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

typedef struct {
    int  id;
    char name[50];
    int  age;
    float marks[5];
    float average;
    char grade;
} Student;

Student db[MAX_STUDENTS];
int count = 0;

char get_grade(float avg) {
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 45) return 'D';
    return 'F';
}

float calc_average(float marks[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += marks[i];
    return sum / n;
}

void print_header() {
    printf("\n  %-5s %-20s %-5s %-8s %-6s\n", "ID", "Name", "Age", "Average", "Grade");
    printf("  %s\n", "─────────────────────────────────────────────");
}

void print_student(Student *s) {
    printf("  %-5d %-20s %-5d %-8.2f %-6c\n", s->id, s->name, s->age, s->average, s->grade);
}

void add_student() {
    if (count >= MAX_STUDENTS) { printf("  ✗ Database full!\n"); return; }
    Student s;
    s.id = count + 1;
    printf("  Enter Name: "); scanf(" %[^\n]", s.name);
    printf("  Enter Age: "); scanf("%d", &s.age);
    printf("  Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("    Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
        if (s.marks[i] < 0 || s.marks[i] > 100) { printf("  ✗ Invalid marks!\n"); i--; }
    }
    s.average = calc_average(s.marks, 5);
    s.grade = get_grade(s.average);
    db[count++] = s;
    printf("  ✓ Student added! ID: %d | Average: %.2f | Grade: %c\n", s.id, s.average, s.grade);
}

void view_all() {
    if (count == 0) { printf("  No students found!\n"); return; }
    print_header();
    for (int i = 0; i < count; i++) print_student(&db[i]);
    printf("\n  Total students: %d\n", count);
}

void search_student() {
    char name[50];
    printf("  Enter name to search: ");
    scanf(" %[^\n]", name);
    int found = 0;
    print_header();
    for (int i = 0; i < count; i++) {
        if (strstr(db[i].name, name) != NULL) { print_student(&db[i]); found++; }
    }
    printf("\n  Found %d result(s).\n", found);
}

void update_student() {
    int id;
    printf("  Enter student ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("  Found: %s\n", db[i].name);
            printf("  Enter new Name: "); scanf(" %[^\n]", db[i].name);
            printf("  Enter new Age: "); scanf("%d", &db[i].age);
            printf("  Enter new marks for 5 subjects:\n");
            for (int j = 0; j < 5; j++) { printf("    Subject %d: ", j + 1); scanf("%f", &db[i].marks[j]); }
            db[i].average = calc_average(db[i].marks, 5);
            db[i].grade = get_grade(db[i].average);
            printf("  ✓ Student updated! New Average: %.2f | Grade: %c\n", db[i].average, db[i].grade);
            return;
        }
    }
    printf("  ✗ Student with ID %d not found!\n", id);
}

void delete_student() {
    int id;
    printf("  Enter student ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("  Deleting: %s\n", db[i].name);
            for (int j = i; j < count - 1; j++) db[j] = db[j + 1];
            count--;
            printf("  ✓ Student deleted!\n");
            return;
        }
    }
    printf("  ✗ Not found!\n");
}

void sort_by_average() {
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (db[j].average < db[j + 1].average) {
                Student tmp = db[j]; db[j] = db[j + 1]; db[j + 1] = tmp;
            }
    printf("  ✓ Sorted by average (highest first)!\n");
    view_all();
}

void save_to_file() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) { printf("  ✗ Could not open file!\n"); return; }
    fprintf(fp, "%-5s %-20s %-5s %-8s %-6s\n", "ID", "Name", "Age", "Average", "Grade");
    fprintf(fp, "%s\n", "─────────────────────────────────────────────");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%-5d %-20s %-5d %-8.2f %-6c\n",
                db[i].id, db[i].name, db[i].age, db[i].average, db[i].grade);
    fprintf(fp, "\nTotal: %d students\n", count);
    fclose(fp);
    printf("  ✓ Data saved to '%s'!\n", FILE_NAME);
}

void show_menu() {
    printf("\n╔════════════════════════════════════╗\n");
    printf("║    STUDENT DATABASE MANAGEMENT     ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1. Add Student                    ║\n");
    printf("║  2. View All Students              ║\n");
    printf("║  3. Search Student                 ║\n");
    printf("║  4. Update Student                 ║\n");
    printf("║  5. Delete Student                 ║\n");
    printf("║  6. Sort by Average                ║\n");
    printf("║  7. Save to File                   ║\n");
    printf("║  0. Exit                           ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    int choice;
    printf("\n  Welcome to Student Database System!\n");
    while (1) {
        show_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        switch (choice) {
            case 1: add_student(); break;
            case 2: view_all(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: sort_by_average(); break;
            case 7: save_to_file(); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
