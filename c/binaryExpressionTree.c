
#include <stdio.h>

#define MAX 10

struct node {
    char val;
    struct node *left;
    struct node *right;
};

struct nodeStack {
    int top;
    struct node* arr[MAX];
} s;

void initialize(struct nodeStack *s) {
    s->top = -1;
}

void push(struct nodeStack *s, struct node *node) {
    s->top++;
    int top = s->top;
    if (top >= MAX - 1) {
        printf("Cannot push, stack is full.\n");
        return;
    }
    s->arr[top] = node;
}

struct node* pop(struct nodeStack *s) {
    int top = s->top;
    struct node *retNode;
    retNode = (struct node*)malloc(sizeof(struct node));

    if (top < 0) {
        printf("Underflow.\n");
        return;
    }
    retNode = s->arr[top];
    //printf("%d", s->arr[0]);
    s->top--;
    return retNode;
}

struct node* createNode(char val) {
    struct node *retNode;
    retNode = (struct node*)malloc(sizeof(struct node));
    retNode->val = val;
    return retNode;
};

int operand(char c) {
    // Returns 0 if c is an operator
    // Returns 1 if c is an operand (like a or c)
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}


void traverseInOrder(struct node* root) {
    if (root->left != NULL) {
        traverseInOrder(root->left);
    }
    printf(" %c ", root->val);
    if (root->right != NULL) {
        traverseInOrder(root->right);
    }
}

void traversePreOrder(struct node* root) {
    printf(" %c ", root->val);
    if (root->left != NULL) {
        traversePreOrder(root->left);
    }
    if (root->right != NULL) {
        traversePreOrder(root->right);
    }
}

void traversePostOrder(struct node* root) {
    if (root->left != NULL) {
        traversePostOrder(root->left);
    }
    if (root->right != NULL) {
        traversePostOrder(root->right);
    }
    printf(" %c ", root->val);
}

int main() {
    char postOrderEqn[] = "ab+cd+*";
    int i = 0;
    char c;
    struct node *temp;
    initialize(&s);

    while (postOrderEqn[i] != '\0') {
        c = postOrderEqn[i];

        temp = createNode(c);
        if (operand(c)) {
            temp->left = NULL;
            temp->right = NULL;
            push(&s, temp);
        }
        else {
            temp->right = pop(&s);
            temp->left = pop(&s);
            push(&s, temp);
        }
        i++;
    }
    traverseInOrder(temp);
    printf("\n");
    traversePreOrder(temp);
    printf("\n");
    traversePostOrder(temp);
    return 0;
}
