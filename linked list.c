#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head=NULL;
void ins_strt()
{
  int data;
  struct node *temp;
  printf("Enter value to input: ");
  scanf("%d",&data);
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=head;
  head=temp;
}
void ins_end()
{
  int data;
  struct node *temp,*ptr;
  printf("Enter value to input: ");
  scanf("%d",&data);
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)
  {
  	head=temp;
  }
  else
  {
  	ptr=head;
  while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
  ptr->next=temp;
  }
}
void ins_pos()
{
	int data,pos,i;
	struct node *temp,*ptr;
	printf("Enter position: ");
	scanf("%d",&pos);
	printf("Enter value to input: ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		ptr=head;
		for(i=1;(i<pos-1)&&(ptr->next!=NULL);i++)
			ptr=ptr->next;
		if(i==pos-1)
		{
			temp->next=ptr->next;
			ptr->next=temp;
		}
		else
			printf("Invalid position");
	}
}
void display()
{
  int i=1;
  struct node *ptr;
  ptr=head;
  if(ptr!=NULL)
  {
  while(ptr->next!=NULL)
    {
      printf("\n%d th element: %d",i,ptr->data);
      ptr=ptr->next;
      i++;
    }
  printf("\n%d th element: %d",i,ptr->data);
  }
  else
  {
    printf("linkedlist empty");
  }
}
void dlt_start()
{
	struct node *dlt;
	dlt=head;
	if(dlt!=NULL)
	{
		head=dlt->next;
		printf("\n%d deleted",dlt->data);
		free(dlt);
	}
	else
	{
		printf("\nlinked list empty");
	}
}
void dlt_end()
{
	struct node *dlt,*pre;
	pre=NULL;
	dlt=head;
	if(dlt!=NULL)
	{
		while(dlt->next!=NULL)
		{
			pre=dlt;
			dlt=dlt->next;
		}
		printf("%d deleted",dlt->data);
		if(dlt==head)
		{
			head=NULL;
			free(dlt);
		}
		else
		{
			pre->next=NULL;
			free(dlt);
		}
	}
	else
		printf("Linkedlist is empty");
}
void dlt_pos()
{
	int pos,i=1;
	struct node *dlt,*pre;
	dlt=head;
	printf("Enter position to be deleted: ");
	scanf("%d",&pos);
	if(dlt!=NULL)
	{
		while((dlt->next!=NULL)&&(i<pos))
		{
			pre=dlt;
			dlt=dlt->next;
			i++;
		}
		if((i==pos)&&(dlt==head))
		{
			head=dlt->next;
			printf("\nHead changed");
			printf("\n%d deleted",dlt->data);
			free(dlt);
		}
		else if(i==pos)
		{
			pre->next=dlt->next;
			printf("\n%d deleted",dlt->data);
			free(dlt);
		}
		else
			printf("Invalid position");
	}
	else
		printf("Linkedlist empty");
}
int main()
{
	int choice;
	do{
		printf("\nChoose an option\n");
		printf("\n1.Add at start\n2.Add at position\n3.Add at end\n4.Display\n5.Delete from start\n6.Delete from end\n7.Delete at position\n8.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : ins_strt();
			break;
			case 2 : ins_pos();
			break;
			case 3 : ins_end();
			break;
			case 4 : display();
			break;
			case 5 : dlt_start();
			break;
			case 6 : dlt_end();
			break;
			case 7 : dlt_pos();
			break;
			case 8 : printf("exiting");
			break;
			default : printf("invalid choice");
		}
	}while(choice!=8);
	return 0;
}
