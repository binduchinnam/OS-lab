#include<stdio.h>
//First fit memory allocation
/*Input:
No.of processes:4
no.of blocks:4
p:20 40 70 10
b:30 20 90 70
o/p:
1->1
2->3
3->4
4->2*/
struct pro{
	int id,mem,bid,bs;
};
void ff(struct pro p[],int b[],int n,int bls)
{
	int visit[20];
	for(int i=1;i<=bls;i++)
	{
		visit[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(visit[i]!=1 && p[i].mem<=b[i])
		{
			p[i].bid=i;
			p[i].bs=b[i];
			visit[i]=1;
		}
		else
		{
			for(int j=1;j<=bls;j++)
			{
				if(visit[j]!=1 && b[j]>=p[i].mem)
				{
					p[i].bid=j;
					p[i].bs=b[j];
					visit[j]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d->%d\n",p[i].id,p[i].bid);
	}
}
void main()
{
	struct pro p[20];
	int block[20];
	int n,bls;
	printf("Enter no.of processors:");
	scanf("%d",&n);
	printf("Enter no.of pages:");
	scanf("%d",&bls);
	printf("Enter size of processes:");
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		scanf("%d",&p[i].mem);
	}
	printf("Enter sizes of pages:");
	for(int i=1;i<=bls;i++)
	{
		scanf("%d",&block[i]);
	}
	ff(p,block,n,bls);
	
}

