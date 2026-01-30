#include<stdio.h>
int sumArrayElement(int a[],int n) //Def
{
    int sum=0,i;
    for(i=0;i<n;i++)
    sum=sum+i;
    return(sum);
}
int main()
{
    int a[10],n,i,sum; //Declaration
    printf("\nEnter size of array:\n");
    printf("\nEnter n:\n");
    scanf("%d",&n);
    printf("\nEnter data into:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum=sumArrayElement(a,n); //Call
    printf("\nSum of array elements is: %d\n",sum);
    return 0;
}