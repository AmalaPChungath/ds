#include<stdio.h>
int universal[10]={1,2,3,4,5,6,7,8,9,10};
void display(int *p);
int main()
{
	int u[10]={1,1,1,1,1,1,1,1,1,1};
	int a[10]={1,1,0,0,1,0,1,0,0,1};
	int b[10]={0,1,0,1,0,1,1,0,1,1};
	int a_union_b[10],a_inter_b[10],a_diff_b[10],b_diff_a[10],i;
	printf("Universal set = ");
	display(u);
	printf("\nA = ");
	display(a);
	printf("\nB = ");
	display(b);
	printf("\nA union B = ");
	for(i=0;i<10;i++)
	{
		a_union_b[i]=a[i]||b[i];
	}
	display(a_union_b);
	printf("\nA intersection B = ");
	for(i=0;i<10;i++)
	{
		a_inter_b[i]=a[i]&&b[i];
	}
	display(a_inter_b);
	printf("\nA-B = ");
	for(i=0;i<10;i++)
	{
		if(a[i]>=b[i])
		   a_diff_b[i]=a[i]-b[i];
		else
		   a_diff_b[i]=0;
	}
	display(a_diff_b);
	printf("\nB-A = ");
	for(i=0;i<10;i++)
	{
		if(b[i]>=a[i])
		   b_diff_a[i]=b[i]-a[i];
		else
		   b_diff_a[i]=0;
	}
	display(b_diff_a);
	
	return 0;
}
void display(int *p)
{
	int *t=p,i;
	for(i=0;i<10;i++)
	{
		if(*t==1)
		  printf("%d   ",universal[i]);
		t++;
	}
}
