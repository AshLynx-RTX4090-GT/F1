#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } boool;

struct node {
    int info;
    int balance;
    struct node *lchild;
    struct node *rchild;
};

void display(struct node *ptr, int level) {
    int i;
    if (ptr != NULL) {
        display(ptr->rchild, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%d", ptr->info);
        display(ptr->lchild, level + 1);
    }
}

void inorder(struct node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->lchild);
        printf("%d  ", ptr->info);
        inorder(ptr->rchild);
    }
}

struct node* search(struct node *ptr, int info) {
    if (ptr != NULL) {
        if (info < ptr->info)
            ptr = search(ptr->lchild, info);
        else if (info > ptr->info)
            ptr = search(ptr->rchild, info);
    }
    return ptr;
}

struct node *rotateLeft(struct node *pptr) {
    struct node *aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}

struct node *rotateRight(struct node *pptr) {
    struct node *aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

struct node *insert(int info, struct node *pptr, boool *ht_inc) {
    struct node *aptr, *bptr;

    if (pptr == NULL) {
        pptr = (struct node *)malloc(sizeof(struct node));
        pptr->info = info;
        pptr->lchild = NULL;
        pptr->rchild = NULL;
        pptr->balance = 0;
        *ht_inc = TRUE;
        return pptr;
    }

    if (info < pptr->info) {
        pptr->lchild = insert(info, pptr->lchild, ht_inc);

        if (*ht_inc == TRUE) {
            switch (pptr->balance) {
            case -1: // Right heavy
                pptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0: // Balanced
                pptr->balance = 1;
                break;
            case 1: // Left heavy
                aptr = pptr->lchild;
                if (aptr->balance == 1) { // LL Rotation
                    printf("Left to Left Rotation\n");
                    pptr = rotateRight(pptr);
                    pptr->balance = 0;
                    pptr->rchild->balance = 0;
                } else { // LR Rotation
                    printf("Left to Right Rotation\n");
                    bptr = aptr->rchild;
                    aptr->rchild = bptr->lchild;
                    bptr->lchild = aptr;
                    pptr->lchild = bptr->rchild;
                    bptr->rchild = pptr;

                    if (bptr->balance == 1)
                        pptr->balance = -1;
                    else
                        pptr->balance = 0;

                    if (bptr->balance == -1)
                        aptr->balance = 1;
                    else
                        aptr->balance = 0;

                    bptr->balance = 0;
                    pptr = bptr;
                }
                *ht_inc = FALSE;
            }
        }
    } else if (info > pptr->info) {
        pptr->rchild = insert(info, pptr->rchild, ht_inc);

        if (*ht_inc == TRUE) {
            switch (pptr->balance) {
            case 1: // Left heavy
                pptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0: // Balanced
                pptr->balance = -1;
                break;
            case -1: // Right heavy
                aptr = pptr->rchild;
                if (aptr->balance == -1) { // RR Rotation
                    printf("Right to Right Rotation\n");
                    pptr = rotateLeft(pptr);
                    pptr->balance = 0;
                    pptr->lchild->balance = 0;
                } else { // RL Rotation
                    printf("Right to Left Rotation\n");
                    bptr = aptr->lchild;
                    aptr->lchild = bptr->rchild;
                    bptr->rchild = aptr;
                    pptr->rchild = bptr->lchild;
                    bptr->lchild = pptr;

                    if (bptr->balance == -1)
                        pptr->balance = 1;
                    else
                        pptr->balance = 0;

                    if (bptr->balance == 1)
                        aptr->balance = -1;
                    else
                        aptr->balance = 0;

                    bptr->balance = 0;
                    pptr = bptr;
                }
                *ht_inc = FALSE;
            }
        }
    }

    return pptr;
}

int main() {
    boool ht_inc;
    int info, choice;
    struct node *root = NULL;

    while (1) {
        printf("\n1.Insert\n");
        printf("2.Display\n");
        printf("3.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &info);
            if (search(root, info) == NULL)
                root = insert(info, root, &ht_inc);
            else
                printf("Duplicate value ignored\n");
            break;
        case 2:
            if (root == NULL) {
                printf("Tree is empty\n");
                continue;
            }
            printf("Tree is :\n");
            display(root, 1);
            printf("\n\n");
            printf("Inorder Traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}