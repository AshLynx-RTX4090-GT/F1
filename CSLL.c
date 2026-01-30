#include<stdio.h>
#include<stdlib.h>
//ADT for CSLL Node.
struct node
{
	int info;
	struct node *link;
};
struct node * create(struct node * start)
{
	struct node *new;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item for 1st Node:\n");
		scanf("%d",&item);
		new->info = item;
		start = new;
		new->link = start;
	}
	return (start);
}
void traverse(struct node *start)
{
	struct node *ptr = start;
	printf("\n CSLL Contains:\n");
	printf("%d\t",ptr->info);
	ptr=ptr->link;
	while(ptr != start)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
}
struct node * insert_beg(struct node * start)
{
	struct node *new,*ptr;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info = item;
		new->link = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr=start;
			while(ptr->link!= start)
				ptr=ptr->link;
			ptr->link = new;
			new->link = start;
			start = new;
		}
		traverse(start);
	}
	return (start);
}
struct node * insert_end(struct node * start)
{
	struct node *new,*ptr;
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL)
		printf("\nOVERFLOW\n");
	else
	{
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info = item;
		new->link = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr=start;
			while(ptr->link != start)
				ptr=ptr->link;
			ptr->link = new;
			new->link = start;
		}
		traverse(start);
	}
	return (start);
}
struct node * delete_beg(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start;
		printf("\nItem Deleted:%d\n",ptr->info);
		while(ptr->link != start)
			ptr=ptr->link;
		ptr->link = start->link;
		ptr = start;
		start= ptr->link;
		traverse(start);
		free(ptr);
	}
	return(start);
}
struct node * delete_end(struct node *start)
{
	struct node *ptr,*prev;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start;
		while(ptr->link != start)
		{
			prev = ptr;
			ptr=ptr->link;
		}	
		printf("\nItem Deleted:%d\n",ptr->info);	
		prev->link = start;
		traverse(start);
		free(ptr);
	}
	return(start);
}
int main()
{
	struct node*start=NULL;
	int option;
	start = create(start);
	do
	{
		printf("\nMENU:\n1.Traversal\n2.Insert_Beg\n3.Insert_End\n4.Delete_Beg\n5.Delete_End\n6.Exit\n");
		printf("\nEnter Your Choice:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:traverse(start);break;
			case 2:start = insert_beg(start);break;
			case 3:start = insert_end(start);break;
			case 4:start = delete_beg(start);break;
			case 5:start = delete_end(start);break;
			case 6:exit(0);
		}
	}while(option<7);
}






