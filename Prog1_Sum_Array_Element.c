#include<stdio.h>
int sumArrayElement(int a[], int n)//Def
{
	int sum=0,i;
	for(i=0;i<n;i++)
		sum=sum+a[i];
	return(sum);
}
int main()
{
	int a[10],n,i,sum;//declaration
	printf("\nEnter n:\n");
	scanf("%d",&n);
	printf("\nEnter data into Array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sum=sumArrayElement(a,n);//Call
	printf("\nSum=%d\n",sum);
	return 0;
}
