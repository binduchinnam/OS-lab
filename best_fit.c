#include<stdio.h>
/*input:
processes:4
blocks:4
processors:20 40 70 10 
blocks:30 20 90 70

o/p:
1->2
2->4
3->3
4->1
*/
struct pro
{
	int id,mem,bid,bs;
};
void bf(struct pro p[],int b[],int n,int m)
{
	int visit[20];
	for(int i=1;i<=m;i++)
	{
		visit[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int min=999,ind=-1;
		for(int j=1;j<=m;j++)
		{
			if(visit[j]!=1 && b[j]>=p[i].mem)
			{
				if(min>b[j])
				{
					min=b[j];
					ind=j;
				}
			}
		}
		p[i].bid=ind;
		p[i].bs=b[ind];
		visit[ind]=1;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d->%d\n",p[i].id,p[i].bid);
	}
}
void main()
{
	int n,m;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	printf("Enter no.of blocks:");
	scanf("%d",&m);
	struct pro p[20];
	printf("Enter size of processes:");
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		scanf("%d",&p[i].mem);
	}
	int block[20];
	printf("Enter size of blocks:");
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&block[i]);
	}
	bf(p,block,n,m);
	
}
