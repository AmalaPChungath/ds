#include<stdio.h>
int uni[10]={1,2,3,4,5,6,7,8,9,10};
void display(int *p);
int find(int *p);
int main()
{
	int u[10]={1,1,1,1,1,1,1,1,1,1};
	int a[10]={1,1,1,1,1,0,0,0,0,0};
	int b[10]={0,0,0,0,0,1,1,1,1,1};
	int a_union_b[10],i,p_a=0,p_b=0;
	printf("Universal set = ");
	display(u);
	printf("\nA = ");
	display(a);
	printf("\nB = ");
	display(b);
	p_a=find(a);
	printf("\n Parent of A = %d",p_a);
	p_b=find(b);
	printf("\n Parent of B = %d",p_b);
	if(p_a!=p_b)
	{
		printf("\nA union B = ");
		for(i=0;i<10;i++)
		{
			a_union_b[i]=a[i]||b[i];
		}
		display(a_union_b);
	}
	else
	   printf("\nUnion not possible");
	return 0;
}
void display(int *p)
{
	int *t=p,i;
	for(i=0;i<10;i++)
	{
		if(*t==1)
		  printf("%d   ",uni[i]);
		t++;
	}
}
int find(int *p)
{
	int *t=p,i;
	for(i=0;i<10;i++)
	{
		if(*t==1)
		   return uni[i];
		t++;
	}
	return 0;
}
