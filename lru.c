#include<stdio.h>

int front=-1,rear=-1,pf=0,h=0;

int isFull(int n)
{
	if(rear==n-1)
	{
		return 1;
	}
	return 0;
}
void enq(int q[],int val)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		q[rear]=val;
	}
	else
	{
		
		rear++;
		q[rear]=val;

	}
}
int dq(int q[])
{
	if(front!=-1)
	{
		if(front==rear)
		{
			
			int t=q[front];
			front=-1;rear=-1;
			return t;
		}
		else
		{
			return q[front++];
		}
	}
}
int Contains(int q[],int val,int n)
{
	for(int i=0;i<n;i++)
	{
		if(q[i]==val)
			return i;
	}
	return -1;
}
int lru(int rf[],int ind,int s,int q[],int n)
{
	int mp[n][2];
	for(int i=0;i<n;i++)
	{
		mp[i][1]=0;
	}
	int k=0;
	for(int i=ind-n;i<ind;i++)
	{
		if(Contains(q,rf[i],n)==-1)
			continue;
		else if(Contains(q,rf[i],n)!=-1)
		{
			mp[k][0]=rf[i];
			mp[k][1]++;
			k+=1;
		}
	}
	int min=999,in=-1;
	for(int i=0;i<n;i++)
	{
		if(min>mp[i][1])
		{
			min=mp[i][1];
			in=Contains(q,mp[i][0],n);
		}
	}
	return in;
}
void main()
{
	int n;
	printf("Enter no.of frames:");
	scanf("%d",&n);
	int q[n];
	for(int i=0;i<n;i++)
	{
		q[i]=-1;
	}
	int s;
	printf("Enter size of reference string:");
	scanf("%d",&s);
	int rf[20];
	printf("Enter reference string:");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&rf[i]);
	}
	int i=0;
	int h=0,f=0;
	while(i<s)
	{
		if(Contains(q,rf[i],n)!=-1)
			h++;
		else if(!isFull(n))
		{
			enq(q,rf[i]);
			f++;
		}
		else
		{
			int ind=lru(rf,i,s,q,n);
			q[ind]=rf[i];
			f++;
		}
		i++;
	}
	printf("Page faults:%d",f);
	printf("\nPage hits:%d",h);
}

