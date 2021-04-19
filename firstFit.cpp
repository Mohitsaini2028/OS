#include <iostream>

using namespace std;

int main()
{

	//variable initialization and allocation

	int blocksize[10], processsize[10], blockno, processno, flags[10], allocation[10], i, j;
	
	for(i=0; i<10; i++)
	{
		flags[i] = 0;
		
		allocation[i] = -1;
	
	}
	
	//entering blocks
	
		cout<<"Fill the number of blocks: ";
	
	cin>>blockno;
	
	cout<<"\nFill size of each block: \n";
	
	for(i = 0; i<blockno; i++)
	
		cin>>blocksize[i];
	
	//Entering processes
	
	cout<<"\nFill the number of processes: ";
	
	cin>>processno;
	
	cout<<"\nEnter each process size: \n";
	
	for(i = 0; i<processno; i++)
	
		cin>>processsize[i]; //memory allocation as per first fit
	
	for(i=0; i< processno; i++)
	
	for(j = 0; j<blockno; j++)
	
	if(flags[j] == 0 && blocksize[j]> processsize[i])
	
	{
		allocation[j] = i;
		
		flags[j] = 1;
		
		break;
	
	}
	
	//display allocation details
	
	cout<<"\nBlock no.\tsize\t\tprocess no. \t\tsize";
	
	for(i=0; i<blockno; i++)
	{
	
		cout<<"\n"<<i<<"\t\t"<<blocksize[i]<<"\t\t";
	
		if(flags[i] == 1)
	
			cout<<allocation[i]<<"\t\t\t"<<processsize[allocation[i]];
	
		else
	
			cout<<"Not allocated";
	
	}
	
	return 0;
}
