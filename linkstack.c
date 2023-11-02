#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
	struct node *head=NULL;
void ins_end()
{
	int data;
	struct node *ptr,*temp;
	printf("\nEnter the value to input: ");
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
		printf("\n %d delected",dlt->data);
		if(dlt==head)
		{
		head=NULL;
		free(dlt);
		}
		else
		{
		pre->next=NULL;
		}
	}
	else
	printf("The Linked list is empty");
}
int main()
{
	int choice;
	do{
		printf("Choose an option\n");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1 : ins_end();
			break;
			case 2 : dlt_end();
			break;
			case 3 : display();
			break;
			case 4 : printf("exiting");
			break;
			default : printf("invalid choice");
		}
	}while(choice!=4);
	return 0;
}
