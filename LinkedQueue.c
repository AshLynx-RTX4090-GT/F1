#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
void traverse(struct node *front) {
    struct node *ptr = front;
    printf("\nLinked Queue Contains:\n");
    while(ptr != NULL) {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

void enqueue(struct node **front, struct node **rear) 
{
    struct node *new;
    int item;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Item:\n");
        scanf("%d", &item);
        new->info = item;
        new->link = NULL;
        if (*front == NULL && *rear == NULL) {
            *front = *rear = new;
        } else {
            (*rear)->link = new;
            *rear = new;
        }
        traverse(*front);
    }
}

void dequeue(struct node **front, struct node **rear) {
    struct node *ptr;
    if (*front == NULL && *rear == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        ptr = *front;
        printf("\nItem Deleted: %d\n", ptr->info);
        if (*front == *rear) {
            *front = *rear = NULL;
        } else {
            *front = (*front)->link;
        }
        traverse(*front);
        free(ptr);
    }
}

int main() {
    struct node *front = NULL, *rear = NULL;
    int op;
    do {
        printf("\nMENU:\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n");
        printf("\nEnter Your Choice:\n");
        scanf("%d", &op);
        switch(op) {
            case 1: enqueue(&front, &rear); break;
            case 2: dequeue(&front, &rear); break;
            case 3: traverse(front); break;
            case 4: exit(0);
            default: printf("\nInvalid Choice\n");
        }
    } while(op != 4);

    return 0;
}

