/*
 * ============================================
 *   Binary Search Tree (BST) in C
 *   Features: Insert, Delete, Search,
 *             Inorder/Preorder/Postorder,
 *             Height, Min/Max
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* new_node(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

Node* insert(Node *root, int val) {
    if (!root) return new_node(val);
    if (val < root->data)      root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    else printf("  ✗ %d already exists!\n", val);
    return root;
}

Node* min_node(Node *root) {
    while (root->left) root = root->left;
    return root;
}

Node* delete_node(Node *root, int val) {
    if (!root) { printf("  ✗ %d not found!\n", val); return NULL; }
    if (val < root->data) root->left  = delete_node(root->left,  val);
    else if (val > root->data) root->right = delete_node(root->right, val);
    else {
        if (!root->left)  { Node *tmp = root->right; free(root); return tmp; }
        if (!root->right) { Node *tmp = root->left;  free(root); return tmp; }
        Node *tmp = min_node(root->right);
        root->data = tmp->data;
        root->right = delete_node(root->right, tmp->data);
    }
    return root;
}

Node* search(Node *root, int val) {
    if (!root || root->data == val) return root;
    if (val < root->data) return search(root->left,  val);
    return search(root->right, val);
}

void inorder(Node *root)   { if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); } }
void preorder(Node *root)  { if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); } }
void postorder(Node *root) { if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); } }

int height(Node *root) {
    if (!root) return 0;
    int l = height(root->left), r = height(root->right);
    return 1 + (l > r ? l : r);
}

void print_tree(Node *root, int space) {
    if (!root) return;
    space += 4;
    print_tree(root->right, space);
    printf("\n");
    for (int i = 4; i < space; i++) printf(" ");
    printf("[%d]\n", root->data);
    print_tree(root->left, space);
}

void show_menu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║       BINARY SEARCH TREE             ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. Insert Node                      ║\n");
    printf("║  2. Delete Node                      ║\n");
    printf("║  3. Search Node                      ║\n");
    printf("║  4. Inorder   Traversal (sorted)     ║\n");
    printf("║  5. Preorder  Traversal              ║\n");
    printf("║  6. Postorder Traversal              ║\n");
    printf("║  7. Tree Height                      ║\n");
    printf("║  8. Min / Max Value                  ║\n");
    printf("║  9. Visualize Tree                   ║\n");
    printf("║  0. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("  Choice: ");
}

int main() {
    Node *root = NULL;
    int choice, val;

    printf("\n  Welcome to Binary Search Tree!\n");
    while (1) {
        show_menu();
        scanf("%d", &choice);
        if (choice == 0) { printf("\n  Goodbye!\n\n"); break; }
        switch (choice) {
            case 1:
                printf("  Enter value: "); scanf("%d", &val);
                root = insert(root, val);
                printf("  ✓ Inserted %d.\n", val); break;
            case 2:
                printf("  Enter value to delete: "); scanf("%d", &val);
                root = delete_node(root, val);
                if (root) printf("  ✓ Deleted %d.\n", val); break;
            case 3:
                printf("  Enter value to search: "); scanf("%d", &val);
                if (search(root, val)) printf("  ✓ Found %d in tree!\n", val);
                else printf("  ✗ %d not in tree.\n", val); break;
            case 4:
                printf("  Inorder   : "); inorder(root); printf("\n"); break;
            case 5:
                printf("  Preorder  : "); preorder(root); printf("\n"); break;
            case 6:
                printf("  Postorder : "); postorder(root); printf("\n"); break;
            case 7:
                printf("  Tree Height: %d\n", height(root)); break;
            case 8:
                if (!root) { printf("  Tree is empty!\n"); break; }
                printf("  Min: %d | Max: %d\n", min_node(root)->data, min_node(root)->data);
                Node *cur = root; while (cur->right) cur = cur->right;
                printf("  Min: %d | Max: %d\n", min_node(root)->data, cur->data); break;
            case 9:
                printf("  Tree Structure:\n"); print_tree(root, 0); printf("\n"); break;
            default: printf("  Invalid choice!\n");
        }
    }
    return 0;
}
