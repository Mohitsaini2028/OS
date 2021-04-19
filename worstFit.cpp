#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
		
struct bestFit{
	
	int blocksize[10], processsize[10],processId[10], blockno,blockId[10], processno, flags[10], allocation[10], i, j;	
	public:
		
		void sorting()
		{	
			int n=blockno;
			
			//selection sort
			for(i=0;i<n-1;i++)
			{
				int max=i;
				for(j=i+1;j<n;j++)
					if(blocksize[j]>blocksize[max])
						max=j;
			
				swap(&blocksize[max],&blocksize[i]);
				swap(&blockId[max],&blockId[i]);				
			}
			
			n=processno;
			for(i=0;i<n-1;i++)
			{
				int max=i;
				for(j=i+1;j<n;j++)
					if(processsize[j]>processsize[max])
						max=j;
			
				swap(&processsize[max],&processsize[i]);
				swap(&processId[max],&processId[i]);				
			}
		}
		
		
		
		void takeInput(){
	
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
			{			
				cin>>blocksize[i];
				blockId[i]=i;
			}
			
			//Entering processes
			
			cout<<"\nFill the number of processes: ";
			
			cin>>processno;
			
			cout<<"\nEnter each process size: \n";
			
			for(i = 0; i<processno; i++)
			{
				cin>>processsize[i]; //memory allocation as per first fit
				processId[i]=i;
			}
				
				}
				
				
		
				
				
		void allocate()
			{
				for(i=0; i< processno; i++)
				
				for(j = 0; j<blockno; j++)
				
				if(flags[j] == 0 && blocksize[j]> processsize[i])
				
				{

					allocation[j] = i;
					
					flags[j] = 1;
					
					break;
				
				}
				
			}
			
				
		void  display()
			{
				
				cout<<"\nBlock no.\tsize\t\tprocess no \t\tsize\n\n";
				
				for(i=0; i<blockno; i++)
				{
				
					cout<<"\n"<<blockId[i]<<"\t\t"<<blocksize[i]<<"\t\t";
				
					if(flags[i] == 1)
				
						cout<<processId[allocation[i]]<<"\t\t\t"<<processsize[allocation[i]]<<"\n";
				
					else
				
						cout<<"Not allocated\n";
				
				}
				cout<<"------------------------------------------------------";
			}
	
};




int main()
{
	bestFit obj;
	obj.takeInput();
	obj.sorting();
	obj.allocate();
	obj.display();
	return 0;
}
