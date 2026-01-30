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
void insert(int a[10],int *n, int item, int pos)
{
	int i=*n-1;
	while(i>=pos-1)
	{
		a[i+1]=a[i];i--;
	}
	a[pos-1]=item;
	(*n)++;
	printf("\nAfter Insertion:\n");
	traverse(a,0,*n-1);
}
void deletion(int a[10], int *n, int pos)
{
	int i, item=a[pos-1];
	for(i=pos-1;i<*n;i++)
		a[i]=a[i+1];
	(*n)--;
	printf("\nItem Deleted:%d\n",item);
	printf("\nAfter Deletion:\n");
	traverse(a,0,*n-1);
}
void Lsearch(int a[10], int n, int item)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			printf("\nSuccessful Search.\n%d found at %d Pos.",item, i+1);
			break;
		}
	}
	if(i==n)
	printf("\nSearch Unsuccesful");
}
void bubbleSort(int a[10], int n)
{
	int i,j,temp;
	printf("\nBefore Sorting:\n");
	traverse(a,0,n-1);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-i)-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];a[j]=a[j+1];a[j+1]=temp;
			}
		}
	}	
	printf("\nAfter Sorting:\n");
	traverse(a,0,n-1);
}
int main()
{
	int a[10],n,option,item,pos;
	create(a,&n);//call to Create Function.
	do
	{
		printf("\nMenu:\n1.Traverse\n2.Insertion\n3.Deletion\n4.Linear Search\n5.Bubble Sort\n6.Exit\nEnter Your Choice:\n");	
		scanf("%d",&option);
		switch(option)
		{
			case 1:traverse(a,0,n-1);break;
			case 2:printf("\nEnter Item and Pos:\n");
				   scanf("%d%d",&item,&pos);
				   insert(a,&n,item,pos);break;
			case 3:printf("\nEnter Pos:\n");
				   scanf("%d",&pos);
				   deletion(a,&n,pos);break;
			case 4:printf("\nEnter item to be Searched :\n");
				   scanf("%d",&item);
				   Lsearch(a,n,item);break;	   
			case 5:bubbleSort(a,n);break;
			case 6:exit(0);
		}
	}while(option<7);
	return 0;
}
