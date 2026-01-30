#include <stdio.h>
#include <stdlib.h>

void create(int a[10], int *n)
{
    int i;
    printf("\nEnter n:\n");
    scanf("%d", n);
    printf("\nEnter Data into array:\n");
    for (i = 0; i < *n; i++)
        scanf("%d", &a[i]);
}

void traverse(int a[10], int lb, int ub)
{
    int i = lb;
    printf("\nContent of the Array:\n");
    while (i <= ub)
    {
        printf("%d\t", a[i]);
        i++;
    }
}
void PrintIndexValue(int a[10], int n, int index)
{
    if (index>=0 && index<= n-1)
    print("%d\t", a[index]);
    else
        printf("\nInvalid Index\n");

}
int main()
{
    int a[10], n, option, index;
    create(a, &n); // Call to Create Function

    do
    {
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. PrintIndexValue\n");
        printf("3. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            traverse(a, 0, n - 1);
            break;
        case 2:
            printf("\nEnter Index Value:\n");
            scanf("%d", &pos);
            PrintIndexValue(a, n, index);
            break;
        case 3:
            exit(0);
        }
    } while (option < 4);
    return 0;
}