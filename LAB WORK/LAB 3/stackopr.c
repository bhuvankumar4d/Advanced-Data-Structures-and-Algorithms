#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int evalStack[MAX];
int evalTop = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void pushEval(int val) {
    evalStack[++evalTop] = val;
}

int popEval() {
    return evalStack[evalTop--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        } 
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            pushEval(c - '0');
        } 
        else {
            int b = popEval();
            int a = popEval();
            switch (c) {
                case '+': pushEval(a + b); break;
                case '-': pushEval(a - b); break;
                case '*': pushEval(a * b); break;
                case '/': pushEval(a / b); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < b; j++) res *= a;
                    pushEval(res);
                    break;
                }
            }
        }
    }
    return popEval();
}

int main() {
    
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}