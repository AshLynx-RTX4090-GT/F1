#include<stdio.h>
void merge_sort(int a[],int low,int mid,int high)
{
	int i, mi, k, lo, temp[50];
	lo = low;i = low;mi = mid + 1;
	while ((lo <= mid) && (mi <= high))
		{
			if (a[lo] <= a[mi])
				{
					temp[i] = a[lo];
					lo++;
				}
			else
				{
					temp[i] = a[mi];
					mi++;
				}
			i++;
		}
	if (lo > mid)
		{
			for (k = mi; k <= high; k++)
				{
					temp[i] = a[k];
					i++;
				}
		}
	else
		{
			for (k = lo; k <= mid; k++)
				{
					temp[i] = a[k];
					i++;
				}
		}
	for (k = low; k <= high; k++)
		{
			a[k] = temp[k];
		}
}
void partition(int a[],int low,int high)
{
	int mid;
	if(low < high)
		{
			mid = (low + high) / 2;
			partition(a, low, mid);
			partition(a, mid + 1, high);
			merge_sort(a, low, mid, high);
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
	partition(a,0,n-1);
	printf("\n\nThe Array After Sorting: ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;
}
