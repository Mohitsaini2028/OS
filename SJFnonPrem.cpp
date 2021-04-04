// C++ program to implement Shortest Job first with different Arrival Time

#include<iostream>
using namespace std;

float pros[10][6]; //declaring globally



void swap(float *a, float *b) {
		float z = *a;
		*a = *b;
		*b = z;
	}

class SJFNonPrem {
	int num;
	
public:

	int takeInput()
	{
		cout<<"Enter number of Process: ";
		cin>>num;
		//NOTE:process id should be number
		for(int i=0; i<num; i++) {
			cout<<"\n Process "<<i+1<<" \n";
			cout<<"Enter Process Id: ";
			cin>>pros[i][0];
			cout<<"Enter Arrival Time: ";
			cin>>pros[i][1];
			cout<<"Enter Burst Time: ";
			cin>>pros[i][2];
		}	
	}

	void display(int n)
	{
		if(n==0) //0 means processes are not arranged yet.
		{
			cout<<"\n--------------------Before Arrange------------------\n\n";
			cout<<"Process ID\tArrival Time\tBurst Time\n";
			for(int i=0; i<num; i++)
			 {
				cout<<pros[i][0]<<"\t\t"<<pros[i][1]<<"\t\t"<<pros[i][2]<<"\n";
			 }
		}
		else{ // display this when procceses are arranged.
			cout<<"\n-----------------------Final Result--------------------\n\n";
			cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
			for(int i=0; i<num; i++)
			 {
				cout<<pros[i][0]<<"\t\t"<<pros[i][1]<<"\t\t"<<pros[i][2]<<"\t\t"<<pros[i][4]<<"\t\t"<<pros[i][5]<<"\n";
			 }
			
			}
	}
	
	
	

	void setArrival(float pros[][6]) {
		for(int i=0; i<num; i++) {
			for(int j=0; j<num-i-1; j++) {
				//comparing arrival time
				if(pros[j][1] > pros[j+1][1]) {
					//sorting whole data according to the arrival time
					for(int k=0; k<5; k++) {
						swap(pros[j][k], pros[j+1][k]);  //swapping data of one process with another
					}
				}
			}
		}
	}

	void completionTime(float pros[][6]) {
		float tempCt;
		int val;

		//first process
		pros[0][3] = pros[0][1] + pros[0][2]; // setting waiting time of the process which come first
		//arrival time  +  burst time
		pros[0][5] = pros[0][3] - pros[0][1]; // setting Turn Around Time
		//completion time  -  arrival time
		pros[0][4] = pros[0][5] - pros[0][2]; // setting completion time
		//TAT - burst time

		for(int i=1; i<num; i++) {
			tempCt = pros[i-1][3]; //assigning CT of i-1(last) process
			float lowestBt = pros[i][2]; // BT of current process (assumption it is smallest BT)

			for(int j=i; j<num; j++) {
				if(tempCt >= pros[j][1] && lowestBt >= pros[j][2]) { //checking all the process till CT of last process>AT
					lowestBt = pros[j][2];
					val = j;
				}
			}
			pros[val][3] = tempCt + pros[val][2];			 // CT of current process
			//CT of last process + BT of current process
			pros[val][5] = pros[val][3] - pros[val][1]; 	// TAT of current process
			//CT of current process - AT of current process
			pros[val][4] = pros[val][5] - pros[val][2];	// WT of current process
			//TAT of current process - BT of current process

			for(int k=0; k<6; k++) {
				swap(pros[val][k], pros[i][k]);
			}
		}
	}


};




int main() {
	
	SJFNonPrem obj;
	
	obj.takeInput();
	obj.display(0);
	obj.setArrival(pros);
	obj.completionTime(pros);
	obj.display(1);
	
}



