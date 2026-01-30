#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int f, r, a[MAX];
} queue;
int isempty(queue *q) {
    if (q->f == -1)
        return 1;
    else
        return 0;
}
int isfull(queue *q) {
    if (q->r == MAX - 1)
        return 1;
    else
        return 0;
}
void display(queue *q) {
    int i;
    if (isempty(q))
        printf("\nQueue Empty\n");
    else {
        printf("\nElements in the queue are:\n");
        for (i = q->f; i <= q->r; i++)
            printf("%d\t", q->a[i]);
        printf("\n");
    }
}
void qinsert(queue *q, int x) {
    if (isfull(q))
        printf("\nOVERFLOW\n");
    else if (q->f == -1 && q->r == -1) {
        q->f = 0;
        q->r = 0;
        q->a[q->r] = x;
    } else {
        q->r++;
        q->a[q->r] = x;
    }
    display(q);
}
void qdelete(queue *q) {
    int x;
    if (isempty(q)) {
        printf("\nUNDERFLOW\n");
        return;
    } else {
        x = q->a[q->f];
        if (q->f == q->r)
            q->f = q->r = -1;
        else
            q->f++;
        printf("Deleted Item = %d\n", x);
        display(q);
    }
}
int main() {
    queue q;
    int item, option;
    q.f = -1;
    q.r = -1;
    do {
        printf("\nPRESS :\n1-> INSERT\n2-> DELETE\n3-> DISPLAY\n4-> EXIT\nEnter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nEnter Item: ");
                scanf("%d", &item);
                qinsert(&q, item);
                break;
            case 2:
                qdelete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    } while (option < 5);
    return 0;
}