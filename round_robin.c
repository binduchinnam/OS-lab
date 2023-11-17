#include<stdio.h>
/*Sample Input:
Enter no.of processes:6
Enter process id,Arrival time,Burst time of each process:
1 0 4
2 1 5
3 2 6
4 3 3 
5 4 1
6 5 4
Enter time Quantum:6
4	9	15	18	19	23	
*/
struct process
{
	int id;
	int at,bt,ct;
};
int Q[100];
int front=-1;int rear=-1;

int isEmpty()
{
	if(front==-1 && rear==-1)
		return 1;
	return 0;
}

void enq(int val)
{
	if(front==-1 && rear==-1)
	{
		front=0;rear=0;
		Q[rear]=val;
	}
	else
	{
		rear++;	
		Q[rear]=val;
	}
}

int dq()
{
	if(isEmpty()==0)
	{
		if(front==rear)
		{
			int res=Q[front];
			front=rear=-1;
			//printf("%d",res);
			return res;
		}
		else
		{
			//printf("%d",Q[front]);
			return Q[front++];
		}
		//front++;
	}
}

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
void rdrr(struct process p[],int n,int tq)
{
	enq(0);
	int tempct=p[0].at;
	int visit[n];
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
	}
	visit[0]=1;
	while(isEmpty()==0)
	{
		int dqd=dq();
		if(p[dqd].bt>tq)
		{
			p[dqd].bt-=tq;
			tempct+=tq;
		}
		else if(p[dqd].bt==tq)
		{
			p[dqd].bt-=tq;
			//p[dqd].ct=p[dqd].at+tq;
			tempct+=tq;
			p[dqd].ct=tempct;
		}
		else
		{
			//p[dqd].bt-=tq;
			
			tempct+=p[dqd].bt;
			p[dqd].ct=tempct;
			p[dqd].bt=0;
		}
		for(int i=0;i<n;i++)
		{
			if(visit[i]!=1 && p[i].at<=tempct)
			{
				enq(i);
				visit[i]=1;
			}
		}
		if(p[dqd].bt>0)
			enq(dqd);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\t",p[i].ct);
	}
}

void main()
{
	int n;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter process id,Arrival time,Burst time of each process:\n");
	for(int i=0;i<n;i++)
	{
		//printf("Enter details of process:%d",i);
		scanf("%d %d %d",&p[i].id,&p[i].at,&p[i].bt);
	}
	sort(p,n);
	
	int dbt[n];
	int tq;
	printf("Enter time Quantum:");
	scanf("%d",&tq);
	
	for(int i=0;i<n;i++)
	{
		dbt[i]=p[i].bt;
	}
	
	rdrr(p,n,tq);
	
}


