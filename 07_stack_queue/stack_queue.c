/*
 * ============================================
 *   Stack & Queue Implementation in C
 *   Features: Push/Pop/Peek for Stack,
 *             Enqueue/Dequeue/Peek for Queue
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

/* ─────────── STACK ─────────── */
typedef struct {
    int data[MAX];
    int top;
} Stack;

void stack_init(Stack *s) { s->top = -1; }
int stack_is_empty(Stack *s) { return s->top == -1; }
int stack_is_full(Stack *s)  { return s->top == MAX - 1; }

void stack_push(Stack *s, int val) {
    if (stack_is_full(s)) { printf("  ✗ Stack Overflow!\n"); return; }
    s->data[++(s->top)] = val;
    printf("  ✓ Pushed %d onto stack.\n", val);
}

void stack_pop(Stack *s) {
    if (stack_is_empty(s)) { printf("  ✗ Stack Underflow!\n"); return; }
    printf("  ✓ Popped: %d\n", s->data[(s->top)--]);
}

void stack_peek(Stack *s) {
    if (stack_is_empty(s)) { printf("  Stack is empty!\n"); return; }
    printf("  Top element: %d\n", s->data[s->top]);
}

void stack_display(Stack *s) {
    if (stack_is_empty(s)) { printf("  Stack is empty!\n"); return; }
    printf("  Stack (top→bottom): ");
    for (int i = s->top; i >= 0; i--) printf("[%d]%s", s->data[i], i > 0 ? " → " : "");
    printf("\n  Size: %d/%d\n", s->top + 1, MAX);
}

/* ─────────── QUEUE ─────────── */
typedef struct {
    int data[MAX];
    int front, rear, size;
} Queue;

void queue_init(Queue *q) { q->front = 0; q->rear = -1; q->size = 0; }
int queue_is_empty(Queue *q) { return q->size == 0; }
int queue_is_full(Queue *q)  { return q->size == MAX; }

void enqueue(Queue *q, int val) {
    if (queue_is_full(q)) { printf("  ✗ Queue is full!\n"); return; }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    q->size++;
    printf("  ✓ Enqueued %d.\n", val);
}

void dequeue(Queue *q) {
    if (queue_is_empty(q)) { printf("  ✗ Queue is empty!\n"); return; }
    printf("  ✓ Dequeued: %d\n", q->data[q->front]);
    q->front = (q->front + 1) % MAX;
    q->size--;
}

void queue_peek(Queue *q) {
    if (queue_is_empty(q)) { printf("  Queue is empty!\n"); return; }
    printf("  Front element: %d\n", q->data[q->front]);
}

void queue_display(Queue *q) {
    if (queue_is_empty(q)) { printf("  Queue is empty!\n"); return; }
    printf("  Queue (front→rear): FRONT → ");
    for (int i = 0; i < q->size; i++)
        printf("[%d]%s", q->data[(q->front + i) % MAX], i < q->size - 1 ? " → " : "");
    printf(" → REAR\n  Size: %d/%d\n", q->size, MAX);
}

void show_menu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        STACK & QUEUE DEMO            ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  --- STACK ---                       ║\n");
    printf("║  1. Push       2. Pop                ║\n");
    printf("║  3. Peek       4. Display            ║\n");
    printf("║  --- QUEUE ---                       ║\n");
    printf("║  5. Enqueue    6. Dequeue            ║\n");
    printf("║  7. Peek       8. Display            ║\n");
    printf("║  0. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    Stack s; Stack stack_init_val = {.top = -1}; s = stack_init_val;
    Queue q; queue_init(&q);
    int choice, val;

    printf("\n  Welcome to Stack & Queue Demo!\n");
    while (1) {
        show_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        switch (choice) {
            case 1: printf("  Enter value: "); scanf("%d", &val); stack_push(&s, val); break;
            case 2: stack_pop(&s); break;
            case 3: stack_peek(&s); break;
            case 4: stack_display(&s); break;
            case 5: printf("  Enter value: "); scanf("%d", &val); enqueue(&q, val); break;
            case 6: dequeue(&q); break;
            case 7: queue_peek(&q); break;
            case 8: queue_display(&q); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
