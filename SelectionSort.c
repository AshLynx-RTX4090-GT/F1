#include<stdio.h>
void selection_sort(int a[], int n)
{
    int i, j, t;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    int a[10], n, i;
    printf("\nEnter the array size:\n");
    scanf("%d", &n);

    printf("\nEnter the array elements into the array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n\nThe Array Before Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);

    selection_sort(a, n);

    printf("\n\nThe Array After Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}
