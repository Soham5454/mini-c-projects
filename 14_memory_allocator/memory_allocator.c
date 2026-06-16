/*
 * ============================================
 *   Custom Memory Allocator in C (Advanced)
 *   Implements a simple heap with:
 *   - my_malloc(), my_free(), my_realloc()
 *   - Free list with coalescing
 *   - Memory usage stats
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE  (1024 * 64)   /* 64 KB heap */
#define ALIGN(x)   (((x) + 7) & ~7)
#define MAGIC      0xDEADBEEF

static char heap[HEAP_SIZE];
static int  initialized = 0;

typedef struct Block {
    size_t        size;
    int           free;
    unsigned int  magic;
    struct Block *next;
} Block;

#define BLOCK_SIZE ALIGN(sizeof(Block))
static Block *free_list = NULL;

void heap_init() {
    free_list = (Block*)heap;
    free_list->size  = HEAP_SIZE - BLOCK_SIZE;
    free_list->free  = 1;
    free_list->magic = MAGIC;
    free_list->next  = NULL;
    initialized = 1;
}

void split_block(Block *b, size_t size) {
    if (b->size >= size + BLOCK_SIZE + 8) {
        Block *new_b = (Block*)((char*)b + BLOCK_SIZE + size);
        new_b->size  = b->size - size - BLOCK_SIZE;
        new_b->free  = 1;
        new_b->magic = MAGIC;
        new_b->next  = b->next;
        b->next = new_b;
        b->size = size;
    }
}

void* my_malloc(size_t size) {
    if (!initialized) heap_init();
    if (size == 0) return NULL;
    size = ALIGN(size);

    Block *cur = free_list;
    while (cur) {
        if (cur->free && cur->size >= size) {
            split_block(cur, size);
            cur->free = 0;
            printf("  [my_malloc]  Allocated %zu bytes at offset %ld\n",
                   size, (char*)cur - heap);
            return (char*)cur + BLOCK_SIZE;
        }
        cur = cur->next;
    }
    printf("  [my_malloc]  ✗ Out of memory!\n");
    return NULL;
}

void coalesce() {
    Block *cur = free_list;
    while (cur && cur->next) {
        if (cur->free && cur->next->free) {
            cur->size += BLOCK_SIZE + cur->next->size;
            cur->next  = cur->next->next;
        } else cur = cur->next;
    }
}

void my_free(void *ptr) {
    if (!ptr) return;
    Block *b = (Block*)((char*)ptr - BLOCK_SIZE);
    if (b->magic != MAGIC) { printf("  [my_free]    ✗ Invalid pointer or corruption!\n"); return; }
    if (b->free)            { printf("  [my_free]    ✗ Double free detected!\n"); return; }
    b->free = 1;
    printf("  [my_free]    Freed %zu bytes at offset %ld\n",
           b->size, (char*)b - heap);
    coalesce();
}

void* my_realloc(void *ptr, size_t new_size) {
    if (!ptr) return my_malloc(new_size);
    Block *b = (Block*)((char*)ptr - BLOCK_SIZE);
    if (new_size <= b->size) { printf("  [my_realloc] Shrinking in place.\n"); return ptr; }
    void *new_ptr = my_malloc(new_size);
    if (!new_ptr) return NULL;
    memcpy(new_ptr, ptr, b->size);
    my_free(ptr);
    printf("  [my_realloc] Reallocated to %zu bytes.\n", new_size);
    return new_ptr;
}

void heap_stats() {
    Block *cur = free_list;
    size_t total_free = 0, total_used = 0, blocks_free = 0, blocks_used = 0;
    while (cur) {
        if (cur->free) { total_free += cur->size; blocks_free++; }
        else           { total_used += cur->size; blocks_used++; }
        cur = cur->next;
    }
    printf("\n  ╔══════════════════════════════╗\n");
    printf("  ║      HEAP STATISTICS         ║\n");
    printf("  ╠══════════════════════════════╣\n");
    printf("  ║  Total Heap  : %6d bytes  ║\n", HEAP_SIZE);
    printf("  ║  Used        : %6zu bytes  ║\n", total_used);
    printf("  ║  Free        : %6zu bytes  ║\n", total_free);
    printf("  ║  Used Blocks : %6zu        ║\n", blocks_used);
    printf("  ║  Free Blocks : %6zu        ║\n", blocks_free);
    printf("  ║  Utilization : %5.1f%%       ║\n", (double)total_used / HEAP_SIZE * 100);
    printf("  ╚══════════════════════════════╝\n");
}

int main() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║     CUSTOM MEMORY ALLOCATOR DEMO     ║\n");
    printf("╚══════════════════════════════════════╝\n\n");

    heap_init();
    printf("  Heap initialized: %d KB\n\n", HEAP_SIZE / 1024);

    // Demo allocations
    int   *arr  = (int*)my_malloc(10 * sizeof(int));
    char  *str  = (char*)my_malloc(50);
    float *flt  = (float*)my_malloc(5 * sizeof(float));

    if (arr) { for (int i = 0; i < 10; i++) arr[i] = i * i; }
    if (str) { strcpy(str, "Hello from custom allocator!"); }

    heap_stats();

    printf("\n  Freeing arr and str...\n");
    my_free(arr);
    my_free(str);

    heap_stats();

    printf("\n  Reallocating flt from 5 to 20 floats...\n");
    flt = (float*)my_realloc(flt, 20 * sizeof(float));

    heap_stats();

    my_free(flt);

    printf("\n  All memory freed.\n");
    heap_stats();

    printf("\n  Testing double-free protection:\n");
    int *x = (int*)my_malloc(4);
    my_free(x);
    my_free(x);  // Should detect double-free

    return 0;
}
