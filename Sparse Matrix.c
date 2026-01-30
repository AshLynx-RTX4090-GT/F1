#include<stdio.h>

#include<stdlib.h>

int M,N,NZ;//Global declaration

void triplet_convert(int a[10][10],int trip[50][3])

{

int i,j,k=1;

trip[0][0]=M;

trip[0][1]=N;

trip[0][2]=NZ;

for(i=0;i<M;i++)

{

for(j=0;j<N;j++)

{

if(a[i][j]!=0)

{

trip[k][0]=i;trip[k][1]=j;trip[k][2]=a[i][j];

k++;

}  }  }

printf("\nTRIPLET MATRIX:\n");

for(i=0;i<=NZ;i++)

printf("\n%d\t%d\t%d\n",trip[i][0],trip[i][1],trip[i][2]);

}

void display_original(int trip[50][3])

{

int i,j,k=1;

printf("\nORIGINAL MATRIX:\n");

for(i=0;i<M;i++)

{

for(j=0;j<N;j++)

{

if(trip[k][0]==i&&trip[k][1]==j)

{

printf("%d\t",trip[k][2]);

k++;

}

else

printf("0\t");

}

printf("\n\n");

}

}

void transpose(int trip[50][3],int trans[50][3])

{

int i,j,k=1;

trans[0][0]=trip[0][1];     

trans[0][1]=trip[0][0];     

trans[0][2]=trip[0][2];     

for(i=0;i<N;i++)

{

for(j=1;j<=NZ;j++)

{

if(trip[j][1]==i)

{

trans[k][0]=trip[j][1];     

trans[k][1]=trip[j][0];     

trans[k][2]=trip[j][2];     

k++;           

}

}

} 
printf("\nTRIPLET TRANSPOSE MATRIX:\n");

for(i=0;i<=NZ;i++)

printf("\n%d\t%d\t%d\n",trans[i][0],trans[i][1],trans[i][2]);

}

void display_transpose(int trans[50][3])

{

int i,j,k=1;

printf("\nORIGINAL TRANSPOSE MATRIX:\n");

for(j=0;j<N;j++)

{

for(i=0;i<M;i++)

{

if(trans[k][0]==j&&trans[k][1]==i)

{

printf("%d\t",trans[k][2]);

k++;

}

else

printf("0\t");

}

printf("\n\n");

}

}

int main()

{

int a[10][10],trip[50][3],trans[50][3],i,j;      

NZ=0;

printf("\nEnter M and N:\n");

scanf("%d%d",&M,&N);

printf("\nEnter elements into array:\n");

for(i=0;i<M;i++)

{

for(j=0;j<N;j++)

{

scanf("%d",&a[i][j]);

if(a[i][j]!=0)

NZ++;

} 
}

if(NZ<(M*N)/2)

{

printf("\nIT'S A SPARSE MATRIX\n");

triplet_convert(a,trip);

display_original(trip);

transpose(trip,trans);

display_transpose(trans);

}

else

{

printf("\nMATRIX IS NOT SPARSE\n");

exit(0);

}
return 0;
}

