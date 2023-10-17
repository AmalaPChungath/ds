#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
	struct node *head=NULL;
	struct node dummy;
void ins_strt()
{
	int data;
	struct node *temp;
	printf("\nEnter the value to input: ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=head;
	head=temp;
}
void ins_end()
{
	int data;
	struct node *ptr,*temp;
	printf("\nEnter the value to input: ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
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
	int data,pos,i,ptrnext;
	struct node *ptr,*swap,*temp;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	printf("\nEnter the value to input: ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		ptr=head;
		for(i=1;i<(pos-1)&&(ptr->next!=NULL);i++)
			ptr=ptr->next;
		if(i==pos-1)
		{
			temp->next=ptr->next;
			ptr->next=temp;
		}
		else
			printf("invalid position");		
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
			printf("%d th element\t %d \n",i,ptr->data);
			ptr=ptr->next;
			i++;
		}
		printf("%d th element\t %d \n",i,ptr->data);
	}
	else
	{
	printf("\n linked list is empty \n");
	}
}
void dlt_end()
{
	struct node *dlt,*pre;
	pre=NULL;
	dlt=head;
	int i;
	if(dlt!=NULL)
	{

		while(dlt->next!=NULL)
		{
			pre=dlt;
			dlt=dlt->next;
			i=i+1;

		}		
		printf("\n %d deleted",dlt->data);
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
	printf("The Linked list is empty");
}
void dlt_pos()

{

	int pos,i=1;
	struct node *dlt,*pre;
	dlt=head;
	printf("enter the postion of element to be deleted");
	scanf("%d",&pos);
	if(dlt!=NULL)
	{
		while(dlt->next!=NULL&&i<(pos))
		{
			i++;
			pre=dlt;
			dlt=dlt->next;
			printf("\n %d %d",i,dlt->data);

		}
		if(i==pos && dlt==head)
		{

			head=dlt->next;
			printf("\nhead is changed");
			printf("\n %d deleted ",dlt->data);
			free(dlt);

		}
		else if(i==pos)
		{

			pre->next=dlt->next;
			printf("\n %d deleted",dlt->data);
			free(dlt);
		}		
		else
		printf("invalid position");
	}
	else
	printf("the linked list is empty");

}
void dlt_strt()
{
	struct node *dlt;
	dlt=head;
	if(dlt!=NULL)
	{
		head=dlt->next;
		printf("\n %d deleted ",dlt->data);
		free(dlt);
	}
	else
	printf("the linked list is empty") ;
}
int main()
{
	int choice;
	do{
		printf("\nChoose an option\n");
		printf("\n1.Add at start\n2.Add at position\n3.Add at end\n4.Display\n5.Delete from end\n6.Delete from start\n7.Delete at position\n8.Exit");
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
			case 5 : dlt_end();
			break;
			case 6 : dlt_strt();
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
