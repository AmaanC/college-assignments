#include <stdio.h>

#define P_LEN 20
#define MAX 20

int s[MAX];
int top = -1;

void push(int val) {
    s[++top] = val;
}

int pop() {
    return s[top--];
}

int main() {
    char pExp[50] = "12+53*/";
    char c;
    int i = 0;
    int result = 0;
    int op1, op2;

    while (pExp[i] != '\0' && i < P_LEN) {
        c = pExp[i];
        
        if (isdigit(c)) {
            push(c - '0');
        }
        else {
            op1 = pop();
            op2 = pop();
            switch(c) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        }

        i++;
    }
    printf("%d\n", s[top]);
    return 0;
}