#include <stdio.h>
void insertion_sort(int a[], int n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int a[10], n, i;
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nArray before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    insertion_sort(a, n);
    printf("\n\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}
