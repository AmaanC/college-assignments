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
    while(current->link != NULL && current->link != root) {
        current = current->link;
    }
    head = current;
    head->link = root;
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
        setHead();
        return;
    }

    prev = root;
    while (i < pos) {
        if (prev->link == root) {
            printf("Overflow. Ignoring call.\n");
            return;
        }
        prev = prev->link;
        i++;
    }
    if (prev->link != root) {
        next = prev->link;
        hasNext = 1;
    }

    prev->link = newNode;
    if (hasNext == 1) {
        newNode->link = next;
    }
    setHead();
}

void rem(int pos) {
    struct node *prev, *next;
    int i = 0;

    prev = root;
    while (i < pos) {
        if (prev->link == root) {
            printf("Overflow. Can't remove node.\n");
            return;
        }
        prev = prev->link;
        i++;
    }

    if (prev->link != root && prev->link->link != root) {
        next = prev->link->link;
        prev->link = next;
    }
    else {
        prev->link = NULL;
    }
    setHead();
}

void remByVal(int value) {
    struct node *current;
    int i = 0;

    current = root;
    while (current->value != value) {
        if (current->link == root) {
            // The list is over, and we haven't broken the loop, so the value must not be in the list
            printf("Could not find node with value %d.\n", value);
            return;
        }
        current = current->link;
        i++;
    }
    rem(i - 1);
}

void clear() {
    root->link = NULL;
    head = root;
}

void display() {
    struct node *current;
    if (root->link == NULL || root->link == root) {
        printf("Empty");
        return;
    }
    current = root->link;
    while (current != root) {
        printf("Value: %d\n", current->value);
        current = current->link;
    }
}

int main() {
    int choice = 0;
    int value = 0, pos = 0;

    init();

    while (choice != 6) {
        printf("\n1) Add to pos (0 = start, -1 = end)\n2) Remove by pos (0-n)\n3) Remove by value\n4) Display\n5) Clear\n6) Exit\n");
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
                clear();
                break;
            default:
                printf("Exiting.\n");
                return 0;
        }
    }

    return 0;
}