#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *link;
} *head, *root;

// List looks like this: root -> node -> node -> head


void init() {
    root = (struct node*)malloc(sizeof(struct node));
    root->link = NULL;
}

// Sets head to the last element
void setHead() {
    struct node *current;
    current = root;
    while(current->link != NULL) {
        current = current->link;
    }
    head = current;
}

// When pos is 0, it means the node will be added right after root, 1 means 1 position after that and so on
// -1 or any negative number means it'll make it the head, i.e. it'll append it to the end of the list
void add(int value, int pos) {
    struct node *newNode, *prev, *next;
    int i = 0, hasNext = 0;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->link = NULL;

    setHead();
    if (pos < 0) {
        head->link = newNode;
        return;
    }

    prev = root;
    while (i < pos) {
        if (prev->link == NULL) {
            printf("Overflow. Ignoring call.\n");
            return;
        }
        prev = prev->link;
        i++;
    }
    if (prev->link != NULL) {
        next = prev->link;
        hasNext = 1;
    }

    prev->link = newNode;
    if (hasNext == 1) {
        newNode->link = next;
    }
    setHead();
}

int rem(int pos) {
    struct node *prev, *next;
    int i = 0;
    int val = -1;

    setHead();
    val = head->value;
    if (root->link == NULL) {
        return -1;
    }

    prev = root;
    while (i < pos) {
        if (prev->link == NULL) {
            printf("Overflow. Can't remove node.\n");
            return;
        }
        prev = prev->link;
        i++;
    }

    if (prev->link != NULL && prev->link->link != NULL) {
        val = prev->link->value;
        next = prev->link->link;
        prev->link = next;
    }
    else {
        prev->link = NULL;
    }
    setHead();

    return val;
}

void clear() {
    root->link = NULL;
    head = root;
}

void display() {
    struct node *current;
    if (root->link == NULL) {
        printf("Empty");
        return;
    }
    current = root->link;
    while (current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->link;
    }
}

int main() {
    int choice = 0;
    int value = 0;

    init();

    while (choice != 4) {
        printf("\n1) Push\n2) Pop\n3) Display\n4) Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                add(value, 0);
                break;
            case 2:
                value = rem(0);
                printf("Popped: %d", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
        }
    }

    return 0;
}
