/*
 * ============================================
 *   File Manager in C
 *   Features: Create, Read, Write, Append,
 *             Copy, Delete, Word Count
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

void create_file() {
    char filename[100];
    printf("  Enter filename to create: ");
    scanf(" %[^\n]", filename);
    FILE *fp = fopen(filename, "w");
    if (!fp) { printf("  ✗ Could not create file!\n"); return; }
    fclose(fp);
    printf("  ✓ File '%s' created successfully!\n", filename);
}

void write_file() {
    char filename[100], content[BUFFER];
    printf("  Enter filename: ");
    scanf(" %[^\n]", filename);
    FILE *fp = fopen(filename, "w");
    if (!fp) { printf("  ✗ Could not open file!\n"); return; }
    printf("  Enter content (type END on a new line to finish):\n");
    while (1) {
        fgets(content, BUFFER, stdin);
        if (strcmp(content, "END\n") == 0) break;
        fputs(content, fp);
    }
    fclose(fp);
    printf("  ✓ Content written to '%s'!\n", filename);
}

void read_file() {
    char filename[100], line[BUFFER];
    printf("  Enter filename to read: ");
    scanf(" %[^\n]", filename);
    FILE *fp = fopen(filename, "r");
    if (!fp) { printf("  ✗ File not found!\n"); return; }
    printf("\n  ── Content of '%s' ──\n", filename);
    int linenum = 1;
    while (fgets(line, BUFFER, fp))
        printf("  %3d │ %s", linenum++, line);
    printf("\n  ── End of file ──\n");
    fclose(fp);
}

void append_file() {
    char filename[100], content[BUFFER];
    printf("  Enter filename to append to: ");
    scanf(" %[^\n]", filename);
    FILE *fp = fopen(filename, "a");
    if (!fp) { printf("  ✗ Could not open file!\n"); return; }
    printf("  Enter content to append (type END on a new line):\n");
    while (1) {
        fgets(content, BUFFER, stdin);
        if (strcmp(content, "END\n") == 0) break;
        fputs(content, fp);
    }
    fclose(fp);
    printf("  ✓ Content appended to '%s'!\n", filename);
}

void copy_file() {
    char src[100], dst[100];
    char buf[BUFFER];
    printf("  Enter source filename: ");
    scanf(" %[^\n]", src);
    printf("  Enter destination filename: ");
    scanf(" %[^\n]", dst);
    FILE *in = fopen(src, "r"), *out = fopen(dst, "w");
    if (!in)  { printf("  ✗ Source file not found!\n"); return; }
    if (!out) { printf("  ✗ Cannot create destination file!\n"); fclose(in); return; }
    while (fgets(buf, BUFFER, in)) fputs(buf, out);
    fclose(in); fclose(out);
    printf("  ✓ Copied '%s' → '%s'!\n", src, dst);
}

void word_count() {
    char filename[100], line[BUFFER];
    printf("  Enter filename: ");
    scanf(" %[^\n]", filename);
    FILE *fp = fopen(filename, "r");
    if (!fp) { printf("  ✗ File not found!\n"); return; }
    int lines = 0, words = 0, chars = 0;
    while (fgets(line, BUFFER, fp)) {
        lines++;
        chars += strlen(line);
        int in_word = 0;
        for (int i = 0; line[i]; i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') in_word = 0;
            else if (!in_word) { in_word = 1; words++; }
        }
    }
    fclose(fp);
    printf("\n  ── Word Count: '%s' ──\n", filename);
    printf("  Lines : %d\n  Words : %d\n  Chars : %d\n", lines, words, chars);
}

void delete_file() {
    char filename[100];
    printf("  Enter filename to delete: ");
    scanf(" %[^\n]", filename);
    char confirm;
    printf("  Are you sure? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        if (remove(filename) == 0) printf("  ✓ File '%s' deleted!\n", filename);
        else printf("  ✗ Could not delete file!\n");
    } else printf("  Cancelled.\n");
}

void show_menu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║         FILE MANAGER             ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Create File                  ║\n");
    printf("║  2. Write to File                ║\n");
    printf("║  3. Read File                    ║\n");
    printf("║  4. Append to File               ║\n");
    printf("║  5. Copy File                    ║\n");
    printf("║  6. Word / Line Count            ║\n");
    printf("║  7. Delete File                  ║\n");
    printf("║  0. Exit                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    int choice;
    printf("\n  Welcome to C File Manager!\n");
    while (1) {
        show_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        switch (choice) {
            case 1: create_file(); break;
            case 2: write_file();  break;
            case 3: read_file();   break;
            case 4: append_file(); break;
            case 5: copy_file();   break;
            case 6: word_count();  break;
            case 7: delete_file(); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
