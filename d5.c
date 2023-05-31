#include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #define MAX_SIZE 100
    int stack[MAX_SIZE];
    int top = -1;
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            printf("Stack Overflow\n");
            exit(1);
        }
        stack[++top] = value;
    }
    int pop() {
        if (top == -1) {
            printf("Stack Underflow\n");
            exit(1);
        }
        return stack[top--];
    }
    int evaluatePostfixExpression(char postfix[]) {
        int i, a, b, result;
        char ch;
        for (i = 0; postfix[i] != '\0'; i++) {
            ch = postfix[i];
            if (isdigit(ch)) {
                push(ch - '0');
            } 
            else {
                b = pop();
                a = pop();
                switch(ch) {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = a / b;
                        break;
                    default:
                        printf("Invalid operator\n");
                        exit(1);
                }
                push(result);
            }
        }
        return pop();
    }
    int main() {
        char postfix[20];
        printf("Enter a postfix expression: ");
        scanf("%s", postfix);
        int result = evaluatePostfixExpression(postfix);
        printf("Result: %d\n", result);
        return 0;
    }
