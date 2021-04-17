#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10],p[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

   cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter arrival time of process: ";
      cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter burst time of process: ";
      cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter priority of process: ";
      cin>>p[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    p[9]=-1;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
     cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0; i<n; i++)
    {
         cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<"\t\t"<<p[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
   cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}

