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
void lsearchNonRec(int a[10], int n, int item)
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
int lsearchRec(int a[10],int n,int item,int index)
{
    if(index >= n)
    return -1; // Base case: item not found
    if(a[index] == item)
    return index; // Item found
    else
    return lsearchRec(a, n, item, index + 1); // Recursive call
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
void binarySearchNonRec(int a[10], int n, int item)
{
    int low = 0, high = n - 1, mid, found = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == item)
        {
            printf("\nSuccessful Search.\n%d found at %d Pos.", item, mid + 1);
            found = 1;
            break;
        }
        else if (a[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        printf("\nSearch Unsuccessful");
}
int binarySearchRec(int a[10], int low, int high, int item) {
    if (low > high)
        return -1; // Not found

    int mid = (low + high) / 2;
    if (a[mid] == item)
        return mid;
    else if (item < a[mid])
        return binarySearchRec(a, low, mid - 1, item);
    else
        return binarySearchRec(a, mid + 1, high, item);
}
int main()
{
	int a[10],n,option,item,pos;
	create(a,&n);//call to Create Function.
	do
	{
		printf("\nMenu:\n1.Traverse.\n2.Linear Search Non-Recursive.\n");
		printf("3.Linear Search Recursive.\n4.Binary Search Non-Recursive.\n5.Binary Search Recursive.\n6.Exit\nEnter Your Choice:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:traverse(a,0,n-1);break;
			case 2:printf("\nEnter item to be Searched :\n");
				   scanf("%d",&item);
				   lsearchNonRec(a,n,item);break;	   
			case 3:printf("\nEnter item to be Searched :\n");
				   scanf("%d",&item);
				   pos=lsearchRec(a,n,item,0);
				if(pos==-1)
				   printf("\nUnsuccessful Search.");
				else
					printf("\nSuccessful Search.\n%dfound found at %d Pos.", item, pos + 1);
				   break;
            case 4:printf("\nEnter item to be Searched :\n");
				   scanf("%d",&item);
				   binarySearchNonRec(a,n,item);break;
            case 5:printf("\nEnter item to be Searched :\n");
                   scanf("%d", &item);
    pos = binarySearchRec(a, 0, n - 1, item);
    if (pos == -1)
        printf("\nSearch Unsuccessful");
    else
        printf("\nSuccessful Search.\n%d found at %d Pos.", item, pos + 1);
    break;
			case 6:exit(0);
		}
	}while(option<6);
	return 0;
}