#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
//ADT for Stack.
struct Stack {
    int a[MAXSIZE],top;
};
typedef struct Stack STACK;
int isempty(STACK *s) {
    if(s->top == -1)
        return 1; // Stack is empty
    else
        return 0; // Stack is not empty
}
int isfull(STACK *s) {
    if(s->top ==MAXSIZE-1)
        return 1;
    else
        return 0;
}
void push(STACK *s, int item){
    if(isfull(s))
        printf("\nOVERFLOW\n");
    else {
        s->top++;
        s->a[s->top] = item;
    }

}
void pop(STACK *s){
    int item;
    if(isempty(s))
        printf("\nUNDERFLOW\n");
    else {
       
        item=s->a[s->top]; s->top--;
        printf("\nItem Deleted: %d\n", item);
    }
}
void peep(STACK *s) {
    int i;
    if(isempty(s)) {
        printf("\nEmpty Stack.\n");
    } else {
        printf("\nContent of the stack:\n");
        for(i=s->top; i>=0; i--)
            printf("\n%d\n", s->a[i]);
    }
}
int main() {
    STACK s;s.top=-1;
    int option, item;
    do
    {
        printf("\nMENU:\n1. Push\n2. Pop\n3. Peep\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:printf("\nEnter Item:\n");
                    scanf("%d", &item);
                    push(&s, item);
                    printf("\nAfter Push:\n");
                    peep(&s);
                    break;
            case 2:pop(&s);
                    printf("\nAfter Pop:\n");
                    peep(&s);
                    break;
            case 3:peep(&s);break;
            case 4:exit(0);
        }
    } while (option<5);
}