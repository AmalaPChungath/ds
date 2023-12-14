#include<stdio.h>
int main()
{
	int adj[10][10],visited[10]={0,0,0,0,0,0,0,0,0,0},i,j,k,v,flag,count=0,visit;
	printf("Enter no of vertices : ");
	scanf("%d",&v);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	for(visit=0;visit<v;)
	{
		count++;
		if(count>50)
			printf("oops graph have loop!!");
		for(i=1;i<=v;i++)
		{
			if(!visited[i])
			{
				flag=0;
				for(j=1;j<=v;j++)
				{
					if(adj[j][i]==1)
						flag=1;
				}
				if(flag==0)
				{
					printf("%d ->",i);
					visited[i]=1;
					visit++;
					for(k=1;k<=v;k++)
						adj[i][k]=0;
				}
			}
		}
	}
	return 0;
}
