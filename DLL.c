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
		printf("\nEnter Item:\n");
		scanf("%d",&item);
		new->info = item;
		new->prev = NULL;
		new->next = NULL;
		start = new;
	}
	return (start);
}
void traverse(struct node *start)
{
	struct node *ptr = start;
	printf("\n DLL Contains:\n");
	while(ptr != NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
struct node * insert_beg(struct node * start)
{
	struct node *new;
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
			new->next = start;
			start->prev = new;
			start = new;
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
		start-> prev = NULL;
		traverse(start);
		free(ptr);
	}
	return(start);
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
			ptr = start;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next = new;
			new->prev = ptr;
		}
		traverse(start);
	}
	return (start);
}
struct node * delete_end(struct node *start)
{
	struct node *ptr;
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		ptr = start;
		while(ptr->next != NULL)
			ptr=ptr->next;
		printf("\nItem Deleted:%d\n",ptr->info);
		ptr->prev->next = NULL;
		ptr->prev = NULL;
		traverse(start);
		free(ptr);
	}
	return(start);
}
void search(struct node *start)
{
	struct node *ptr = start;
	int item,loc=1;
	printf("\nEnter Item to be Searched:\n");
	scanf("%d",&item);
	while(ptr != NULL && ptr->info != item)
	{
		ptr=ptr->next;loc++;
	}
	if(ptr == NULL)
		printf("\nUnsuccessful Search\n");
	else
		printf("\nSucceseful Search at %d node.\n",loc);
}
void sorting(struct node * start)
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next != NULL)
	{
		ptr2=ptr1->next;
		while(ptr2 != NULL)
		{
			if(ptr1->info > ptr2->info)
			{
				ptr1->info = ptr1->info + ptr2->info;
				ptr2->info = ptr1->info - ptr2->info;
				ptr1->info = ptr1->info - ptr2->info;
				
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next; 
	}
	traverse(start);
}
main()
{
	struct node *start = NULL;//SLL not exist
	int op;
	start=create(start);//Call to Create function.
    do
    {
    	printf("\nMenu:\n1.Traverse.\n2.Insert_Beg\n3.Delete_Beg\n4.Insert_End\n5.Delete_End\n6.Linear Search\n7.Sorting\n8.Exit.\n");
    	printf("\nEnter Your Choice:\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:traverse(start);break;
    		case 2:start=insert_beg(start);break;
    		case 3:start=delete_beg(start);break;
    		case 4:start=insert_end(start);break;
    		case 5:start=delete_end(start);break;
			case 6:search(start);break;
			case 7:sorting(start);break;
			case 8:exit(0);
		}
	}while(op<9);
}
      
