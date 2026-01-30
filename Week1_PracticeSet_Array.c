#include<stdio.h>
#include<stdlib.h>
void create(int a[10],int *n)//Definition of Create Function.
{
	int i;
	printf("\nEnter n:\n");
	scanf("%d",n);
	printf("\nEnter Data into Array:\n");
	for(i=0;i<*n;i++)
		scanf("%d",&a[i]);
}
void traverse(int a[], int lb, int ub)//Definition of Traverse Function.
{
	int i=lb;
	printf("\nContent of the Array:\n");
	while(i<=ub)
	{
		printf("%d\t",a[i]);
		i++;
	}
} 
void PrintIndexValue(int a[10], int n, int index)
{
	if(index>=0 && index<=n-1)
		printf("Index Element=%d\t",a[index]);
	else
		printf("\nInvalid Index");
}
void PrintPairs(int a[10], int n)
{
	int i,j;
	printf("\n Pairs Are:\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		printf("\n(%d,%d)\n",a[i],a[j]);
	}
}
void MaxMinArray(int a[10], int n)
{
	int max,min,i;
	max=min=a[0];
	for(i=1;i<n;i++)
	{
	if(a[i]> max)
		max=a[i];
	if(a[i]< min)
		min=a[i];
	}
	printf("\nMax=%d\nMin=%d\n", max,min);
}
void secondLargest(a[10],int n)
{
	int first,second,found=0,i;
	first=second=a[0];
	for(i=1;i<n;i++)
	if(a[i]> first)
		first=a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]<first)
		{
			if(!found || a[i]>second)
			{
				second=a[i];
				found=1;
			}
		}
	}
	if(found)
	printf("\nSecond Largest=%d\n",second);
	else
	printf("\nNo Second Largest.");
	
}
int main()
{
	int a[10],n,option,index;
	create(a,&n);//call to Create Function.
	do
	{
		printf("\nMenu:\n1.Traverse\n2.PrintIndexValue\n");
		printf("3.PrintPairs\n4.Max-MinPrint\n");
		printf("5.Second Largest\n6.Exit\nEnter Your Choice:\n");	
		scanf("%d",&option);
		switch(option)
		{
			case 1:traverse(a,0,n-1);break;
			case 2:printf("\nEnter Index Value:\n");
				   scanf("%d",&index);
				   PrintIndexValue(a,n,index);break;
			case 3:PrintPairs(a,n);break;
			case 4:MaxMinArray(a,n);break;
			case 5:secondLargest(a,n);break;
			case 6:exit(0);
		}
	}while(option<5);  
	return 0;
}
