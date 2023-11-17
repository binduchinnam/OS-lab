// FCFS Scheduling algorithm
#include <stdio.h>
#include <stdlib.h>

int sum=0;

void bubble_sort(int at[],int bt[],int pr[], int n) { 
      int i, j,temp; 
      for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
          if (at[j] > at[j + 1]) {
         
            temp=pr[j];
            pr[j]=pr[j+1];
            pr[j+1]=temp;
           
            temp = at[j]; 
            at[j] = at[j + 1]; 
            at[j + 1] = temp;
           
            temp=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
           
            
          } 
        } 
      } 
    } 
   

int find_CT(int bt[],int ct[],int at[],int pr[],int n){
	sum=at[0];
	int h;
	if(at[0]!=0){
			printf("0 \t");
			printf("IDLE \t");
			printf("%d \t", sum);
		}
	for(int i=0;i<n;i++){
		/**/	
		if(at[i]>ct[i-1]){
			printf("IDLE \t");
			sum=at[i];
			printf("%d \t",sum);
			ct[i]=sum+bt[i];
			printf("P%d", pr[i]);
			sum=ct[i];
			printf("\t %d \t",sum);
		}		
		else{       
			
			sum=sum+bt[i];
			printf("P%d \t", pr[i]);
			printf("%d \t",sum);
			ct[i]=sum;
			
		}
	}
	
	return sum;
}

int find_total_AT(int at[], int ct[],int tat[], int n){
	int f=0;
	printf("\nThe TAT's are:\n");
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		printf("%d \t",tat[i]);
		f=f+tat[i];
		
	}
	printf("%d \t",f);
	return f;
}

int find_WT(int tat[], int bt[],int wt[], int n){
	int s=0;
	printf("\nThe WT's are:\n");
		for(int i=0;i<n;i++){
			wt[i]=tat[i]-bt[i];
			printf("%d \t",wt[i]);

			s=s+wt[i];
		}

	return s;
}

int main(){
	int n,atat,awt;

	printf("Enter no'r of processors:\n");
	scanf("%d",&n);
	int pr[n],at[n],bt[n],tat[n],ct[n],wt[n];
	printf("Enter Processor name and it respective Arrival time and Burst times:\n");
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &pr[i],&at[i],&bt[i]);
	}

	bubble_sort(at,bt,pr,n);

	int x=find_CT(bt,ct,at,pr, n);
	printf("\nThe completion time is:%d" , x);

	int y=find_total_AT(at, ct, tat, n);
	atat=y/n;
	printf("\nThe ATAT is:%d", atat);

	int z=find_WT(tat, bt,wt, n);
	awt=z/n;
	printf("\nThe AWT is:%d", awt);

}





   
