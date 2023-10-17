#include<stdio.h>
int main()
{
	int a[20],i,item,n,flag=0,mid,low,high;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements of sorted array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d th element: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter item to be searched: ");
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
			high=mid=1;
		}
		else
		{
			low=mid+1;	
		}
	}
	if(flag==0)
	printf("%d not found",item);
	return 0;
}
