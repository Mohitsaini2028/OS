#include<iostream>
using namespace std;

void findWaitingTime(int processes[],int n,int bt[],int wt[])
{
	
	wt[0]=0;
	
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}


void findAverageTime(int processes[],int n,int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	
	findWaitingTime(processes,n,bt,wt);
	
	findTurnAroundTime(processes,n,bt,wt,tat);
	
	cout<<"processes "<<"Burst time "<<" waiting time "<<" turn around time"<<"\n";
	
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\t"<<i+1<<"      "<<bt[i]<<"       "<<wt[i]<<"        "<<tat[i]<<"\n";
			
	}
	
	
	cout<<"average waiting time "<<total_wt/4.0<<" ms \n";
	cout<<"average turn around time "<<total_tat/4.0<<" ms";
}

int main()
{
	int processes[]={1,2,3,4};
	int n=sizeof processes/sizeof processes[0];
	
	int burst_time[]={21,3,6,2};
	
	findAverageTime(processes,n,burst_time);
	
	return 0;
	
}
