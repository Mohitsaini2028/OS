#include<iostream>
using namespace std;

void findWaitingTime(int processes[],int n,float bt[],float wt[],float at[],float ct[])
{

	wt[0]=0;
	
	for(int i=0;i<n;i++)
	{	
		wt[i]=ct[i]-bt[i]-at[i];
		
	}
}

void findTurnAroundTime(int processes[],int n,float bt[],float wt[],float tat[],float at[],float ct[])
{
	tat[0]=21;
	for(int i=1;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		
		
	}
}


void findAverageTime(int processes[],int n,float bt[],float at[])
{
	float wt[n],tat[n],total_wt=0,total_tat=0;
	
	float ct[4];
	ct[0]=bt[0];
	
	for(int i=1;i<4;i++)
	{	
		ct[i]=bt[i]+ct[i-1];
	}
	
	findWaitingTime(processes,n,bt,wt,at,ct);
	
	findTurnAroundTime(processes,n,bt,wt,tat,at,ct);
	
	cout<<"processes "<<"Burst time "<<" waiting time "<<" turn around time"<<"\n";
	
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\t"<<i+1<<"      "<<bt[i]<<"       "<<wt[i]<<"        "<<tat[i]<<"\n";
			
	}
	
	
	cout<<"average waiting time "<<total_wt/3.0<<" ms \n";
	cout<<"average turn around time "<<total_tat/3.0<<" ms \n";
}

int main()
{
	int processes[]={1,2,3};
	float n=sizeof processes/sizeof processes[0];
	
 	float burst_time[]={8,4,1};
	float arrivalTime[]={0.0,0.4,1.0};
	
	findAverageTime(processes,n,burst_time,arrivalTime);
	
	return 0;
	
}
