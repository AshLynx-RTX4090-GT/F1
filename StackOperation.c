#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct stack
{
	int items[MAXSIZE];
	int top;
};
typedef struct stack STACK;

int isempty(STACK *s)
{
if(s->top == -1)
	return 1;
else
	return 0;	
} 
int isfull(STACK *s)
{
if(s->top == MAXSIZE-1)
	return 1;
else
	return 0;	
} 
void push(STACK *s, int item)
{
if(isfull(s))
	printf("\nOVERFLOW\n");
else
	{
		s->top++;
		s->items[s->top] = item;
	}				
} 
void pop(STACK *s)
{
	int item;
if(isempty(s))
	printf("\nUNDERFLOW\n");
else
	{
		item=s->items[s->top];
		s->top--;
		printf("\nItem Deleted=%d",item);
	}				
}
void peep(STACK *s)
{
int i;
if(isempty(s))
	printf("\nEmpty Stack.\n");
else
	{
		printf("\nContent of Stack:\n");
		for(i=s->top;i>=0;i--)
		printf("%d\t",s->items[i]);
	}				
}
main()
{
	STACK s;
	int item,op;
	s.top = -1;
	do
	{
		printf("\nMenu:\n1.PUSH.\n2.POP.\n3.PEEP.\n4.Exit.\n");
		printf("\nEnter your Choice:\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:printf("\nEnter item:\n");
				   scanf("%d",&item);
				   push(&s,item);break;
			case 2:pop(&s);break;
			case 3:peep(&s);break;
			case 4:exit(0);
		}
		
	}while(op<5);
}
