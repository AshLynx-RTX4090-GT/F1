#include<stdio.h>
void mMul(int a[10][10],int b[10][10],int n)//Def-1
{
	int i,j,k,c[10][10];
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				c[i][j]=0;
				for(k=0;k<n;k++)
			        c[i][j]+=a[i][k]*b[k][j];
			}
	}
	printf("\nMultiplication Resultant Matrix:\n");
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
	mMul(a,b,n);//Call-1
	return 0;
}
