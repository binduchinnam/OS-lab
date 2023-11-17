#include<stdio.h>

struct process
{
	int id;
	int at,bt,ct;
	int pri;
};


void sort(struct process p[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			else if(p[j].at==p[j+1].at)
			{
				if(p[j].id>p[j+1].id)
				{	
					struct process temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp; 
				}
			}
		}
	}
}
void pri(struct pro p[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=p[i].bt;
	}
	sum+=p[0].at;
	int temp=p[0].at;
	int temp_prior=p[0].pri;
	p[0].bt=p[0].bt-1;
	temp=temp+1;
	while(temp<=sum)
	{
		
		temp++;
	}
}
void main()
{
	int n;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter process id,Arrival time,Burst time,priority of each process:\n");
	for(int i=0;i<n;i++)
	{
		//printf("Enter details of process:%d",i);
		scanf("%d %d %d %d",&p[i].id,&p[i].at,&p[i].bt,&p[i].pri);
	}
	sort(p,n);
	
	int dbt[n];
	
	
	for(int i=0;i<n;i++)
	{
		dbt[i]=p[i].bt;
	}
	
}
