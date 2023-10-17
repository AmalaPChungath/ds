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
  ptr=head;
  while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
  ptr->next=temp;
}
void display()
{
  int i=1;
  struct node *ptr;
  ptr=head;
  while(ptr->next!=NULL)
    {
      printf("%d th element: %d",i,ptr->data);
      i++;
    }
  printf("%d th element: %d",i,ptr->data);
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
