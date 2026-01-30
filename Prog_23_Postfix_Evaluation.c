#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()
#define MAXSIZE 100
// Stack ADT for integers
typedef struct 
{
    int items[MAXSIZE];
    int top;
} STACK;
// Stack Operations
int isEmpty(STACK *s) 
{
    return s->top == -1;
}

int isFull(STACK *s) 
{
    return s->top == MAXSIZE - 1;
}

void push(STACK *s, int item) 
{
    if (isFull(s)) 
    	printf("Stack Overflow!\n");
	else
        s->items[++(s->top)] = item;
}
int pop(STACK *s) 
{
    if (isEmpty(s)) 
	{
        printf("Stack Underflow!\n");
        return -1;
    } 
	else 
        return s->items[(s->top)--];
}
// Function to evaluate postfix expression
int evaluatePostfix(char expr[]) 
{
    STACK s;
	int i, val1, val2, result;
    s.top = -1;
    for (i = 0; expr[i] != '\0'; i++) 
	{
        char ch = expr[i];
        if (isdigit(ch)) 
		{
            // Convert char to int and push
            push(&s, ch - '0');
        } 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
		{
            val2 = pop(&s);
            val1 = pop(&s);
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (i = 0; i < val2; i++)
                        result *= val1;
                    break;
                }
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }

            push(&s, result);
        }
    }

    return pop(&s);
}
int main() 
{
    char postfix[MAXSIZE];
    printf("Enter postfix expression (digits and operators only, no spaces): ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result of the postfix expression = %d\n", result);
    return 0;
}

