#include<iostream>
#include<iomanip>
using namespace std;
class process
{
	public:
		int wt;
		int at;
		int bt;
		int ct;
		process *next=NULL;
		process(int at, int bt)
		{
			this->at=at;
			this->bt=bt;
		}
		~process()
		{
			//Destructor Called
		}	
};
int main()
{
	int n=0,at,bt,ch,ttat=0,twt=0;
	process *first=NULL,*next=NULL,*p=NULL;
	cout<<"Enter 1 to add process.\nPress 2 to display average turn-around time & waiting time.\n";
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter arrival and burst time of process "<<++n<<":";
			cin>>at>>bt;
			next=new process(at,bt);
			if(n==1)
			{
				first=p=next;
				next->wt=0;
				next->ct=at+bt;
			}
			else
			{
				if(p->ct>=at)
				{
					next->wt=p->ct-at;
					next->ct=p->ct+bt;
				}
				else
				{
					next->wt=0;
					next->ct=at+bt;
				}
				p->next=next;
				p=next;
			}
		}
	}while(ch==1);
	n=0;
	p=first;
	cout<<"\nProcess No.\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\n";
	while(p!=NULL)
	{
		cout<<setw(6)<<++n<<setw(16)<<p->at<<setw(16)<<p->bt<<setw(17)<<p->wt<<setw(18)<<p->ct<<endl;
		ttat=ttat+p->ct-p->at;
		twt=twt+p->wt;
		next=p->next;
		delete p;
		p=next;
	}
	cout<<"\nAverage Turnaround Time:"<<(float)ttat/n<<"\nAverage Waiting Time:"<<(float)twt/n;
	return 0;
}
