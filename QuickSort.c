#include<stdio.h>
void quick_sort(int a[], int low, int high)
{
	int pivot, i, j, temp;
	if (low < high)
 		{
			pivot = low;
			i = low;
			j = high;
			while (i< j) 
				{
					while (i<= high && a[i] <= a[pivot])
						i++;
					while (j >= low && a[j] > a[pivot])
						j--;
					if (i< j)
						{
							temp = a[i];
							a[i] = a[j];
							a[j] = temp;
						}
				}	
			temp = a[j];
			a[j] = a[pivot];
			a[pivot] = temp;
			quick_sort(a, low, j - 1);
			quick_sort(a, j + 1, high);
 }
}
int main()
{
	int a[10],n,i,j;
	printf("\nEnter the array size:\n");
	scanf("%d",&n);
	printf("\nEnter the array elements into the array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\n\nThe Array Before Sorting: ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	quick_sort(a,0,n-1);
	printf("\n\nThe Array After Sorting: ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;
}
