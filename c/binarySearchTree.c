/*
Experiment 8, binary search tree
Insertion
Deletion
Search for node
*/

#include <stdio.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

void init(struct node *root, int value) {
    root->value = value;
    root->left = NULL;
    root->right = NULL;
};

void add(struct node *root, int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("\n");
    if (value <= root->value) {
        if (root->left == NULL) {
            root->left = newNode;
            printf("Left assigned %d", value);
        }
        else {
            printf("Left subtree");
            add(root->left, value);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = newNode;
            printf("Right assigned");
        }
        else {
            add(root->right, value);
            printf("Right subtree");
        }
    }
};

// Returns 0 if not found. 1 if found.
int search(struct node *root, int value) {
    if (root == NULL) {
        printf("\n%d not found in BST.", value);
        return 0;
    }
    if (root->value == value) {
        printf("\n%d found in BST.", value);
        return 1;
    }
    else if (value < root->value) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
};

void traverseInOrder(struct node* root) {
    if (root->left != NULL) {
        traverseInOrder(root->left);
    }
    printf(" %d ", root->value);
    if (root->right != NULL) {
        traverseInOrder(root->right);
    }
};

void traversePreOrder(struct node* root) {
    printf(" %d ", root->value);
    if (root->left != NULL) {
        traversePreOrder(root->left);
    }
    if (root->right != NULL) {
        traversePreOrder(root->right);
    }
};

void traversePostOrder(struct node* root) {
    if (root->left != NULL) {
        traversePostOrder(root->left);
    }
    if (root->right != NULL) {
        traversePostOrder(root->right);
    }
    printf(" %d ", root->value);
};

// Should delete only the node itself, not the entire subtree
void rem(struct node *root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        if (root->left->value == value) {
            root->left = NULL;
            free(root->left);
        }
        else {
            rem(root->left, value);
        }
    }
    else if (root->right) {
        if (root->right->value == value) {
            root->right = NULL;
            free(root->right);
        }
        else {
            rem(root->right, value);
        }
    }
};

int main() {
    struct node *root1;
    root1 = (struct node*)malloc(sizeof(struct node));
    init(root1, 10);
    add(root1, 5);
    add(root1, 12);
    add(root1, 7);
    search(root1, 4);
    search(root1, 7);

    printf("\nIn order: ");
    traverseInOrder(root1);
    printf("\nPre order: ");
    traversePreOrder(root1);
    printf("\nPost order: ");
    traversePostOrder(root1);

    rem(root1, 5);
    printf("\nPost order, after deletion: ");
    traversePostOrder(root1);
    return 0;
};
