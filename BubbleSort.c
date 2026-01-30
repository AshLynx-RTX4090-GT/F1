#include <stdio.h>
void bubble_sort(int a[], int n)
{
    int i, j, t;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1]) 
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main()
{
    int a[10], n, i;
    printf("\nEnter the array size: ");
    scanf("%d", &n);
    printf("\nEnter the array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nThe Array Before Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    bubble_sort(a, n);
    printf("\n\nThe Array After Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}
