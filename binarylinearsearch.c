#include<stdio.h>
void linear();
void binary();
int main()
{
	int c;
	printf("\nchoose an option\n1.Linear search\n2.Binary search\nEnter your choice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:linear();
		break;
		case 2:binary();
		break;
	}
	return 0;
}
void linear()
{
	int a[20],i,item,n,flag=0;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d th element: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter item to be searched: ");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			printf("%d found at position %d",item,i+1);
			flag=1;
		}
	}
	if(flag==0)
	printf("%d not found",item);
}
void binary()
{
	int a[20],i,j,item,temp,n,flag=0,mid,low,high;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)
	{
		printf("%d th element: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]>a[i])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}	
		}
	}
	printf("\nArray\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nEnter item to be searched: ");
	scanf("%d",&item);
	low=0;
	high=n;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==item)
		{
			printf("%d found at position %d",item,mid+1);
			flag=1;
			break;
		}
		
		else if(item<a[mid])
		{
			high=mid+1;
		}
		else
		{
			low=mid+1;	
		}
	}
	if(flag==0)
	printf("%d not found",item);
}
