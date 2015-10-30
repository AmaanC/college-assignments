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

int getValueForOperator(char op) {
    // Using BODMAS
    int val = 0;
    switch(op) {
        case '/':
            val = 4;
            break;
        case '*':
            val = 3;
            break;
        case '+':
            val = 2;
            break;
        case '-':
            val = 1;
            break;
        default:
            val = 0;
            break;
    }
    return val;
}

int higherPrecedence(char op1, char op2) {
    // Returns 1 if op1 has higher precedence. 0 otherwise
    int val1 = getValueForOperator(op1);
    int val2 = getValueForOperator(op2);
    return val1 > val2;
}

int main() {
    char eqn[] = "(a+b)*(c+d/e)";
    char result[10] = "";
    int eqI = 0, resI = 0;
    char c;
    char temp;

    initialize(&s);
    // push(&s, 'a');
    // printf("%c", seeTop(&s));
    // printf("%c", pop(&s));

    while (eqn[eqI] != '\0') {
        c = eqn[eqI];
        eqI++;

        if (operand(c)) {
            result[resI] = c;
            resI++;
        }
        else {
            // It is an operator
            if (c == '(') {
                push(&s, c);
            }
            else if (c == ')') {
                temp = pop(&s);
                while (temp != '(' && s.top >= 0) {
                    result[resI] = temp;
                    resI++;
                    temp = pop(&s);
                }
            }
            else if (s.top < 0 || seeTop(&s) == '(' || higherPrecedence(c, seeTop(&s)) == 1) {
                // If the stack is empty, or if there's a ( on the top or if the current operator
                // has a higher precedence than the top of the stack, push the current operator
                push(&s, c);
            }
            else {
                while (higherPrecedence(c, seeTop(&s)) == 0 && s.top >= 0) {
                    printf("Popping: %c\n", seeTop(&s));
                    result[resI] = pop(&s);
                    resI++;
                }
                push(&s, c);
            }
        }
    }
    // Pop all the elements remaining
    while (s.top >= 0) {
        result[resI] = pop(&s);
        resI++;
    }
    printf("%s\n", result);
    return 0;
}
