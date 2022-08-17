#include <iostream>
using namespace std;
int main()
{
    int min,temp,n;
    cout<<"enter number of processes: ";
    cin>>n;
    int p[n];
    int at[n],bt[n],wt[n],tat[n],ct[n];
    cout<<"\n";
    for(int i=0;i<n;i++)
	{
    	p[i]=i+1;
    	cout<<"Enter arrival time for process "<<i+1<<": ";
    	cin>>at[i];
    	cout<<"Enter burst time for process "<<i+1<<": ";
    	cin>>bt[i];
    }
    wt[0]=0;
    ct[0]=bt[0];
    for(int i=1;i<n;i++)
	{
    	min=i;
    	for(int j=i+1;j<n;j++)
		{
        	if(ct[i-1]>=at[j]&&bt[min]>bt[j])
        	    min=j;
        }
        temp=p[min];
        p[min]=p[i];
        p[i]=temp;
        temp=at[min];
        at[min]=at[i];
        at[i]=temp;
        temp=bt[min];
        bt[min]=bt[i];
        bt[i]=temp;
        wt[i]=-at[i]+ct[i-1];
        ct[i]=ct[i-1]+bt[i];
    }
    cout<<"process no.\tarrival time\tburst time\twaiting time\tturn-around time\n";
    for(int i=0;i<n;i++){
    	cout<<"  "<<p[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<ct[i]-wt[i]<<"\n";
    }
}
