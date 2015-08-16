#include <stdio.h>

#define MAX 10

struct stack {
    int top;
    char arr[MAX];
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

char seeTop(struct stack *s) {
    int top = s->top;
    if (top < 0) {
        printf("Underflow.\n");
        return;
    }
    char retVal = s->arr[top];
    return retVal;
}

char pop(struct stack *s) {
    int top = s->top;
    if (top < 0) {
        printf("Underflow.\n");
        return;
    }
    char retVal = s->arr[top];
    //printf("%d", s->arr[0]);
    s->top--;
    return retVal;
}

int operand(char c) {
    // Returns 0 if c is an operator
    // Returns 1 if c is an operand (like a or c)
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int main() {
    char eqn[] = "a+b*c";
    char result[10] = "ab";
    int eqI = 0, resI = 0;
    char c;

    initialize(&s);
    // push(&s, 'a');
    // printf("%c", seeTop(&s));
    // printf("%c", pop(&s));

    while (eqn[eqI] != '\0') {
        c = eqn[eqI];
        eqI++;

        if (operand(c)) {
            // If it isn't an operator, right it down as it is
            result[resI] = c;
            resI++;
        }
        else {
            // Push operator to stack
            push(&s, c);
        }
    }
    //printf("%s", result);
    return 0;
}
