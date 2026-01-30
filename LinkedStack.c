//Linked Stack Program.
#include<stdio.h>
#include<stdlib.h>
//ADT for Linked Stack.
struct node
{
	int info;
	struct node * link;
};
struct node * push(struct node * top)
{
	struct node * new;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info=item;
		new->link=NULL;
		if(top==NULL)
			top=new;
		else
		{
			new->link=top;
			top=new;
		}
	}
	return top;
}
struct node * pop(struct node *top)
{
	struct node * ptr=top;
	if(top==NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nItem Deleted:%d\n",ptr->info);
		top=ptr->link;
		free(ptr);
	}
	return top;
}
void peep(struct node * top)
{
	struct node * ptr;
	if(top==NULL)
		printf("\nEmpty Stack.\n");
	else
	{
		printf("\nContent of Linked Stack:\n");
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
	}
}
int main()
{
	struct node * top=NULL;
	int option;
	do
	{
		printf("\nMENU:\n1.Push.\n2.Pop.\n3.Peep.\n4.Exit.\n");
		printf("\nEnter Your Choice:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:top=push(top);
				   printf("\nAfter Push:\n");
				   peep(top);break;
			case 2:top=pop(top);
				   printf("\nAfter Pop:\n");
				   peep(top);break;
			case 3:peep(top);break;
			case 4:exit(0); 	
		}	
	}while(option<5);
}
