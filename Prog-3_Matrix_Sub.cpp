#include<stdio.h>
void mSub(int a[10][10],int b[10][10],int n)//Def-1
{
	int i,j,c[10][10];
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			c[i][j]=a[i][j]-b[i][j];
	}
	printf("\nSubstraction Resultant Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[10][10],b[10][10],n,i,j;//declaration
	
	printf("\nEnter Order of the matrices:\n");
	scanf("%d",&n);
	
	printf("\nEnter data into Matrix-1:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	printf("\nEnter data into Matrix-2:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	mSub(a,b,n);//Call-1
	return 0;
}
