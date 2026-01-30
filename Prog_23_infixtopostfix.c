#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isalpha and isdigit
#include <string.h>
#define MAXSIZE 100
// Stack ADT for characters
typedef struct 
{
    char items[MAXSIZE];
    int top;
} STACK;
// Stack operations
int isEmpty(STACK *s) 
{
    return s->top == -1;
}
int isFull(STACK *s) 
{
    return s->top == MAXSIZE - 1;
}
void push(STACK *s, char item) 
{
    if (isFull(s)) 
        printf("Stack Overflow!\n");
	else 
        s->items[++(s->top)] = item;
}

char pop(STACK *s) 
{
    if (isEmpty(s)) 
     return '\0';  // Indicates stack underflow
	else 
     return s->items[(s->top)--];
}
char peek(STACK *s) 
{
    if (isEmpty(s)) 
	  return '\0';
    else 
      return s->items[s->top];
}
// Function to check precedence of operators
int precedence(char op) 
{
    switch (op) 
	{
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}


// Function to check if character is an operator
int isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) 
{
    STACK s;
    s.top = -1;
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') 
	{
        if (isalnum(ch)) 
		{
            postfix[j++] = ch;
        } 
		else if (ch == '(') 
		{
            push(&s, ch);
        } 
		else if (ch == ')') 
		{
            while (!isEmpty(&s) && peek(&s) != '(') 
			{
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') 
			{
                pop(&s);  // Remove '('
            }
        } else if (isOperator(ch)) 
		{
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) 
			{
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) 
	{
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
// Driver code
int main() 
{
    char infix[MAXSIZE], postfix[MAXSIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

