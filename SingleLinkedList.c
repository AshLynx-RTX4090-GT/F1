#include <stdio.h>
#include <stdlib.h>
// ADT for SLL : Self-Referential Structure
struct node
{
    int info;
    struct node *link;
};
struct node *create_sll(struct node *start)
{
    struct node *new;
    int item;
    printf("\nEnter item:\n");
    scanf("%d", &item);
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        new->info = item;
        new->link = NULL;
        start = new;
    }
    return start;
}
void traverse(struct node *start)
{
    struct node *ptr = start;
    printf("\nContent of the Single Linked List:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    }
}
struct node *insert_beg(struct node *start)
{
    struct node *new;
    int item;
    printf("\nEnter item:\n");
    scanf("%d", &item);
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        new->info = item;
        new->link = start;
        if (start == NULL)
        {
            start = new;
        }
        else
        {
            new->link = start;
            start = new;
        }
    }
    traverse(start);
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *new, *ptr;
    int item;
    printf("\nEnter item:\n");
    scanf("%d", &item);
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        new->info = item;
        new->link = NULL;
        if (start == NULL)
        {
            start = new;
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = new;
        }
    }
    traverse(start);
    return start;
}
struct node *insert_loc(struct node *start)
{
    struct node *new, *ptr, *prev;
    int item, i = 1, loc;
    printf("\nEnter item and loc:\n");
    scanf("%d %d", &item, &loc);
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    new->info = item;
    new->link = NULL;
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        ptr = start;
        while (i < loc && ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
            i++;
        }
        if (ptr == NULL)
        {
            printf("\nLocation not found\n");
        }
        else
        {
            prev->link = new;
            new->link = ptr;
        }
    }
    traverse(start);
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        ptr = start;
        start = start->link;
        traverse(start);
        free(ptr);
    }
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *prev;
    if (start == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        traverse(start);
        free(ptr);
    }
    return start;
}
struct node *delete_loc(struct node *start)
{
    struct node *ptr, *prev;
    int loc, i = 1;
    printf("\nEnter location to delete:\n");
    scanf("%d", &loc);
    if (start == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        ptr = start;
        while (ptr != NULL && i < loc)
        {
            prev = ptr;
            ptr = ptr->link;
            i++;
        }
        prev->link = ptr->link;
        traverse(start);
        free(ptr);
    }
    return start;
}
void searching_sll(struct node *start, int item)
{
    struct node *ptr=start;
    int loc = 1;
    while(ptr!=NULL && ptr->info != item)
        {ptr = ptr->link;loc++;}
        if (ptr==NULL)
        printf("\nUnsuccessful search\n");
        else
        printf("\n%d found at %d Node.\n",item,loc);
}
void sorting_sll(struct node *start)
{
    struct node *ptr1 = start, *ptr2;
    int temp;
    while (ptr1 != NULL && ptr1->link != NULL)
    {
        ptr2 = ptr1->link;
        while (ptr2 != NULL)
        {
            if (ptr1->info > ptr2->info)
            {
                temp = ptr1->info;
                ptr1->info = ptr2->info;
                ptr2->info = temp;
            }
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}
void reversal_sll(struct node **start)
{
    struct node *ptr = *start, *prev = NULL, *temp;
    while(ptr != NULL)
    {
        temp = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = temp;
    }
    *start = prev;
}
int main()
{
    struct node *start = NULL;
    int option,item;
    start = create_sll(start);
    do
    {
        printf("\nMenu:\n1.Traversal\n2.Insert_Beg\n3.Insert_End\n4.Insert_LOC\n5.Delete_Beg\n6.Delete_End\n7.Delete_LOC\n8.Searching_sll\n9.Sorting_sll\n10.Reversal_sll\n11.Exit\nEnter your choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            traverse(start);
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = insert_loc(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_loc(start);
            break;
        case 8:
        printf("\nEnter item to be searched:\n");
        scanf("%d", &item);
            searching_sll(start, item);
            break;
        case 9:
            printf("\nBefore Sorting:\n");
            traverse(start);
            sorting_sll(start);
            printf("\nAfter Sorting:\n");
            traverse(start);
            break;
        case 10:
            printf("\nBefore Reversal:\n");
            traverse(start);
            reversal_sll(&start);
            printf("\nAfter Reversal:\n");
            traverse(start);
            break;
        case 11:
            exit(0);
        default:
            printf("\nInvalid option\n");
        }
    } while (option < 11);
    return 0;
}