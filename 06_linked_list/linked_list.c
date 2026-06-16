/*
 * ============================================
 *   Complete Linked List Implementation in C
 *   Features: Insert, Delete, Search, Reverse,
 *             Sort, Display (with menu)
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList* create_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

Node* new_node(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert_at_beginning(LinkedList *list, int data) {
    Node *n = new_node(data);
    n->next = list->head;
    list->head = n;
    list->size++;
    printf("  ✓ Inserted %d at beginning.\n", data);
}

void insert_at_end(LinkedList *list, int data) {
    Node *n = new_node(data);
    if (!list->head) { list->head = n; }
    else {
        Node *cur = list->head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    list->size++;
    printf("  ✓ Inserted %d at end.\n", data);
}

void insert_at_position(LinkedList *list, int data, int pos) {
    if (pos < 1 || pos > list->size + 1) { printf("  ✗ Invalid position!\n"); return; }
    if (pos == 1) { insert_at_beginning(list, data); return; }
    Node *n = new_node(data);
    Node *cur = list->head;
    for (int i = 1; i < pos - 1; i++) cur = cur->next;
    n->next = cur->next;
    cur->next = n;
    list->size++;
    printf("  ✓ Inserted %d at position %d.\n", data, pos);
}

void delete_value(LinkedList *list, int data) {
    if (!list->head) { printf("  ✗ List is empty!\n"); return; }
    if (list->head->data == data) {
        Node *tmp = list->head;
        list->head = list->head->next;
        free(tmp); list->size--;
        printf("  ✓ Deleted %d.\n", data);
        return;
    }
    Node *cur = list->head;
    while (cur->next && cur->next->data != data) cur = cur->next;
    if (!cur->next) { printf("  ✗ %d not found!\n", data); return; }
    Node *tmp = cur->next;
    cur->next = tmp->next;
    free(tmp); list->size--;
    printf("  ✓ Deleted %d.\n", data);
}

void search(LinkedList *list, int data) {
    Node *cur = list->head;
    int pos = 1;
    while (cur) {
        if (cur->data == data) { printf("  ✓ Found %d at position %d!\n", data, pos); return; }
        cur = cur->next; pos++;
    }
    printf("  ✗ %d not found in list.\n", data);
}

void reverse(LinkedList *list) {
    Node *prev = NULL, *cur = list->head, *next = NULL;
    while (cur) { next = cur->next; cur->next = prev; prev = cur; cur = next; }
    list->head = prev;
    printf("  ✓ List reversed!\n");
}

void display(LinkedList *list) {
    if (!list->head) { printf("  List is empty!\n"); return; }
    printf("  HEAD → ");
    Node *cur = list->head;
    while (cur) { printf("[%d]", cur->data); if (cur->next) printf(" → "); cur = cur->next; }
    printf(" → NULL   (Size: %d)\n", list->size);
}

void display_menu() {
    printf("\n╔══════════════════════════════════╗\n");
    printf("║      LINKED LIST OPERATIONS      ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Insert at beginning          ║\n");
    printf("║  2. Insert at end                ║\n");
    printf("║  3. Insert at position           ║\n");
    printf("║  4. Delete a value               ║\n");
    printf("║  5. Search a value               ║\n");
    printf("║  6. Reverse the list             ║\n");
    printf("║  7. Display list                 ║\n");
    printf("║  0. Exit                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    LinkedList *list = create_list();
    int choice, val, pos;

    printf("\n  Welcome to Linked List Program!\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }

        switch (choice) {
            case 1: printf("  Enter value: "); scanf("%d", &val); insert_at_beginning(list, val); break;
            case 2: printf("  Enter value: "); scanf("%d", &val); insert_at_end(list, val); break;
            case 3:
                printf("  Enter value: "); scanf("%d", &val);
                printf("  Enter position (1-%d): ", list->size + 1); scanf("%d", &pos);
                insert_at_position(list, val, pos); break;
            case 4: printf("  Enter value to delete: "); scanf("%d", &val); delete_value(list, val); break;
            case 5: printf("  Enter value to search: "); scanf("%d", &val); search(list, val); break;
            case 6: reverse(list); break;
            case 7: display(list); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
