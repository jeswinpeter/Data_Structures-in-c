#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[80];
top = -1;

char pop() {
    if(top == -1) {
        printf("Stack is EMPTY!!!!");
        exit(0);
    }
    else {
        return stack[top--];
    }
}

void push(char y) {
    if(top >= 80) {
        printf("!! Stack is Full !!");
    }
    else{
        stack[++top] = y;
    }
}

int priority(char y) {
    if( y == '(') {
        return 0;
    }
    else if (y == '+' || y == '-')
    {
        return 1;
    }
    else if (y == '*' || y == '/')
    {
        return 2;
    }
    else if (y == '^')
    {
        return 3;
    }
}

int main() {
    char expr[50];
    char *e,x;

    printf("Enter the Infix Expression: ");
    scanf("%s",&expr);

    e = expr;

    printf("\nThe postfix expression is :\n");

    while(*e != '\0') {
        if(isalnum(*e)) {
            printf("%c",*e);
        }
        else if (*e == '(') {
            push(*e);
        }
        else if (*e == ')') {
            while ((x = pop()) != '\0') {
                printf("%c",x);
            } 
        }
        else{
            while (priority(stack[top]) >= priority(*e)) {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }

    while(top != -1) {
		printf("%c",pop());
	}
	printf("\n");
    
    return 0;
}