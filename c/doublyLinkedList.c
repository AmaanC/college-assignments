
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextLink;
    struct node *prevLink;
} *head, *root;

// List looks like this: root -> node -> node -> head


void init() {
    root = (struct node*)malloc(sizeof(struct node));
    root->nextLink = NULL;
    root->prevLink = NULL;
}

// Sets head to the last element
void setHead() {
    struct node *current;
    current = root;
    while(current->nextLink != NULL) {
        current = current->nextLink;
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
    newNode->nextLink = NULL;
    newNode->prevLink = NULL;

    setHead();
    if (pos < 0) {
        head->nextLink = newNode;
        newNode->prevLink = head;
        return;
    }

    prev = root;
    while (i < pos) {
        if (prev->nextLink == NULL) {
            printf("Overflow. Ignoring call.\n");
            return;
        }
        prev = prev->nextLink;
        i++;
    }
    if (prev->nextLink != NULL) {
        next = prev->nextLink;
        hasNext = 1;
    }

    prev->nextLink = newNode;
    newNode->prevLink = prev;
    if (hasNext == 1) {
        newNode->nextLink = next;
        next->prevLink = newNode;
    }
    setHead();
}

void rem(int pos) {
    struct node *prev, *next;
    int i = 0;

    prev = root;
    while (i < pos) {
        if (prev->nextLink == NULL) {
            printf("Overflow. Can't remove node.\n");
            return;
        }
        prev = prev->nextLink;
        i++;
    }

    if (prev->nextLink != NULL && prev->nextLink->nextLink != NULL) {
        next = prev->nextLink->nextLink;
        prev->nextLink = next;
        next->prevLink = prev;
    }
    else {
        prev->nextLink = NULL;
    }
    setHead();
}

void remByVal(int value) {
    struct node *current;
    int i = 0;

    current = root;
    while (current->value != value) {
        if (current->nextLink == NULL) {
            // The list is over, and we haven't broken the loop, so the value must not be in the list
            printf("Could not find node with value %d.\n", value);
            return;
        }
        current = current->nextLink;
        i++;
    }
    rem(i - 1);
}

void clear() {
    root->nextLink = NULL;
    head = root;
}

void display() {
    struct node *current;
    if (root->nextLink == NULL) {
        printf("Empty");
        return;
    }
    current = root->nextLink;
    while (current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->nextLink;
    }
}

void displayReverse() {
    struct node *current;

    setHead();
    if (head->prevLink == NULL) {
        printf("Empty");
        return;
    }
    current = head;
    while (current->prevLink != NULL) {
        printf("Value: %d\n", current->value);
        current = current->prevLink;
    }
}

int main() {
    int choice = 0;
    int value = 0, pos = 0;

    init();

    while (choice != 6) {
        printf("\n1) Add to pos (0 = start, -1 = end)\n2) Remove by pos (0-n)\n3) Remove by value\n4) Display\n5) Display reverse\n6) Clear\n7) Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);

                add(value, pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);

                rem(pos);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                remByVal(value);
                break;
            case 4:
                printf("\nDisplaying:\n");
                display();
                printf("\n\n");
                break;
            case 5:
                printf("\nDisplaying:\n");
                displayReverse();
                printf("\n\n");
                break;
            case 6:
                clear();
                break;
            default:
                printf("Exiting.\n");
                return 0;
        }
    }

    return 0;
}
