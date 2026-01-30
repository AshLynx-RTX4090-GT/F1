#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void radixSort(int *a, int n) 
{
	int bucket[10], dummy[n], max, i, index, lsd = 1;
	max = a[0];
/* find the largest key */
	for (i = 0; i< n; i++) 
		{
			if (a[i] > max)
 			max = a[i];
		}
	while (max / lsd> 0) 
		{
			memset(bucket, 0, sizeof(int) * 10);
			memset(dummy, 0 , sizeof(int) * n);
			for (i = 0; i< n; i++)
			{
				index = (a[i] / lsd) % 10;
				bucket[index]++;
			}
			for (i = 1; i< 10; i++)
				bucket[i] = bucket[i] + bucket[i-1];
/* sort the elements based on current significant digit */
			for (i = n-1; i>= 0; i--)
			{
				index = (a[i] / lsd) % 10;
				index = --bucket[index];
				dummy[index] = a[i];
			}
/* update original with dummy */
			for (i = 0; i< n; i++)
				a[i] = dummy[i];
			lsd = lsd * 10;
		}
}
int main() 
{
	int *a, i, n;
	printf("\nEnter the array size:\n");
	scanf("%d",&n);
	printf("\nEnter the array elements into the array:\n");
	a = (int *)malloc(sizeof (int) * n);
	for (i = 0; i< n; i++) 
	scanf("%d", &a[i]);
	printf("\n\nThe Array Before Sorting: ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	radixSort(a, n);
	printf("\n\nThe Array After Sorting: ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;  
}