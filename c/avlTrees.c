#include <stdio.h>
#include <stdlib.h>

struct node {
    int bf;
    int value;
    struct node *left;
    struct node *right;
};


void init(struct node *root, int value) {
    root->value = value;
    root->bf = 0;
    root->left = NULL;
    root->right = NULL;
}

void add(struct node *root, int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    //printf("\n");
    if (value <= root->value) {
        if (root->left == NULL) {
            root->left = newNode;
            //printf("Left assigned %d", value);
        }
        else {
            //printf("Left subtree");
            add(root->left, value);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = newNode;
            //printf("Right assigned");
        }
        else {
            add(root->right, value);
            //printf("Right subtree");
        }
    }
}

int getMaxDepth(struct node *someNode) {
    int depth = 0;
    int leftDepth = 0;
    int rightDepth = 0;
    if (someNode != NULL) {
        depth = 1;
        leftDepth = getMaxDepth(someNode->left);
        rightDepth = getMaxDepth(someNode->right);
        //printf("%d\n", leftDepth);
        depth += (rightDepth > leftDepth) ? rightDepth : leftDepth;
    }
    return depth;
}

void setBf(struct node *root) {
    root->bf = getMaxDepth(root->left) - getMaxDepth(root->right);
    // TODO: Set bf of descendants
}

struct node* rightRotate(struct node *root) {
    struct node *newRoot;
    struct node *temp;
    newRoot = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));

    newRoot = root->left;
    temp = newRoot->right;
    newRoot->right = root;
    root->left = temp;

    return newRoot;
}

struct node* leftRotate(struct node *root) {
    struct node *newRoot;
    struct node *temp;
    newRoot = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));

    newRoot = root->right;
    temp = newRoot->left;
    newRoot->left = root;
    root->right = temp;

    return newRoot;
}

struct node* balance(struct node *root) {
    if (root->bf == 2) {
        root = rightRotate(root);
    }
    else if (root->bf == -2) {
        root = leftRotate(root);
    }
    return root;
}

void traversePreOrder(struct node* root) {
    printf(" %d ", root->value);
    if (root->left != NULL) {
        traversePreOrder(root->left);
    }
    if (root->right != NULL) {
        traversePreOrder(root->right);
    }
};

int main() {
    struct node *root;
    struct node *root2;
    root = malloc(sizeof(struct node));
    root2 = malloc(sizeof(struct node));
    init(root, 20);
    add(root, 10);
    add(root, 25);
    add(root, 5);
    add(root, 15);
    add(root, 4);

    init(root2, 20);
    add(root2, 25);
    add(root2, 20);
    add(root2, 22);
    add(root2, 28);
    add(root2, 30);

    printf("Binary trees before (preorder):\n");
    traversePreOrder(root);
    printf("\n");
    traversePreOrder(root2);
    printf("\n");

    setBf(root);
    setBf(root2);

    root = balance(root);
    root2 = balance(root2);

    printf("Binary trees after balancing (preorder):\n");
    traversePreOrder(root);
    printf("\n");
    traversePreOrder(root2);
    printf("\n");
    return 0;
}
