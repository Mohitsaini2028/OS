#include<iostream>
using namespace std;


//SHORTEST JOB FIRST
class SJF{
	
	int p[20],bt[20],wt[20],tat[20];
	float wtavg,tatavg;
	int i,k,n,temp;
	public:
		
	void takeBT()
	{
		//taking total number of processes from user
		cout<<"enter the no of processes ----\n";
		cin>>n;
		for (i=0;i<n;i++)
		{
			p[i]=i;
			//taking burst time from user
			cout<<"\nEnter Burst Time for process "<<i+1<<" ";
			cin>>bt[i];
		}
	}
	
	void sortBT()
	{
		//sorting burst time in ascending order through selection sort method
		for(i=0;i<n;i++)
			for(k=i+1;k<n;k++)
			if(bt[i]>bt[k])
			{
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
	}
	
	void findAverageTime() //method for calculating average waiting time and Turn Around Time
	{
		wt[0]=wtavg=0;
		tat[0]=tatavg=bt[0];
		
		for(i=1;i<n;i++)
		{
			wt[i]=wt[i-1]+bt[i-1];
			tat[i]=tat[i-1]+bt[i];
			wtavg=wtavg+wt[i];
			tatavg=tatavg+tat[i];
		}
		wtavg=wtavg/n;
		tatavg=tatavg/n;	
		
	}
	
	void display()
	{	//displaying data
		cout<<"\n\n----------------------------------------------------------------";
		cout<<"\n\nprocesses "<<"Burst time "<<" waiting time "<<" turn around time"<<"\n";	
			
		for(int i=0;i<n;i++)
		{
			cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n\n";
				
		}
		cout<<"-------------------------------------------------------------------\n\n";
		
		cout<<"average waiting time "<<wtavg<<" ms \n";
		cout<<"average turn around time "<<tatavg<<" ms\n\n";
		}
	
};


int main()
{
	SJF obj1;
	obj1.takeBT();
	obj1.sortBT();
	obj1.findAverageTime();
	obj1.display();
}
