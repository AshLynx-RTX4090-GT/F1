#include<stdio.h>
#include<stdlib.h>
struct node // Self-referential structure.
{
	int info;
	struct node *prev,*next;
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
		new->prev = start;
		new->next = start;
	}
	return (start);
}
void traverse(struct node *start)
{
	struct node *ptr = start;
	printf("\n CDLL Contains:\n");
	printf("%d\t",ptr->info);
	ptr=ptr->next;
	while(ptr != start)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
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
		new->prev = NULL;
		new->next = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr = start -> prev;//Jump to Last Node.
			ptr->next = new;//last connected to new node.
			new->prev = ptr;//new connected to last node.
			new->next = start;//new connected to 1st node.
			start -> prev = new;//1st node connected to new node.
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
		new->prev = NULL;
		new->next = NULL;
		if(start == NULL)
		start = new;
		else
		{
			ptr = start -> prev;//Jump to Last Node.
			ptr->next = new;//last connected to new node.
			new->prev = ptr;//new connected to last node.
			new->next = start;//new connected to 1st node.
			start -> prev = new;//1st node connected to new node.
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
		start= ptr->next;
		ptr->next->prev = ptr->prev;//2nd node connected to last node.
		ptr->prev->next = ptr -> next;//last node connected to 2nd node.
		traverse(start);
		free(ptr);
	}
	return(start);
}

struct node * delete_end(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start ->prev;
		printf("\nItem Deleted:%d\n",ptr->info);
		ptr->prev->next = start;//2nd last node connected to 1st node.
		start->prev = ptr -> prev;
		traverse(start);
		free(ptr);
	}
	return(start);
}
main()
{
	struct node *start = NULL;//SLL not exist
	int op;
	start=create(start);//Call to Create function.
    do
    {
    	printf("\nMenu:\n1.Traverse.\n2.Insert_Beg\n3.Delete_Beg\n4.Insert_End\n5.Delete_End\n6.Exit.\n");
    	printf("\nEnter Your Choice:\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:traverse(start);break;
    		case 2:start=insert_beg(start);break;
    		case 3:start=delete_beg(start);break;
    		case 4:start=insert_end(start);break;
    		case 5:start=delete_end(start);break;
			case 6:exit(0);
		}
	}while(op<7);
}
      
