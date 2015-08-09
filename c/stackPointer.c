#include <stdio.h>

#define MAX 5

struct stack {
    int top;
    int arr[MAX];
} s;

void initialize(struct stack *s) {
    s->top = -1;
}

void push(struct stack *s, int value) {
    s->top++;
    int top = s->top;
    if (top >= MAX - 1) {
        printf("Cannot push, stack is full.\n");
        return;
    }
    s->arr[top] = value;
}

int pop(struct stack *s) {
    int top = s->top;
    if (top < 0) {
        printf("Underflow.\n");
        return;
    }
    int retVal = s->arr[top];
    //printf("%d", s->arr[0]);
    s->top--;
    return retVal;
}

int main() {
    initialize(&s);
    int choice = 0;
    int val;
    while(choice != 3) {
        printf("1) Push\n2) Pop\n3) Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(&s, val);
            break;
        case 2:
            printf("Popped value: %d\n", pop(&s));
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}
