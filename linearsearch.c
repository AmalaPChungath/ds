#include<stdio.h>
int main()
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
	return 0;
}
