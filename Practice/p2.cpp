#include<iostream>
#include<iomanip>
using namespace std;
class process/*To store process accepted inputs and calculated outputs in linked list*/
{
	public:
		int n;
		int alloc;
		float bt;
		float wt;
		float at;
		float ct;
		bool cal;
		process *next=NULL;
		process(float at, float bt, int n)
		{
			this->at=at;
			this->bt=bt;
			this->n=n;
			this->cal=1;
		}
		~process()
		{
			//Destructor Called
		}	
};
int main()
{
	int n=0,ch,i=1,t=1;
	float at,bt,ttat=0,twt=0,min;
	process *first=NULL,*next=NULL,*p=NULL,*temp=NULL;
	cout<<"Enter 1 to add process.\nPress any key to display average turn-around time & waiting time.\n";
	do/*Accepting waiting and burst time from user then storing in linked list*/
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter arrival and burst time of process "<<++n<<":";
			cin>>at>>bt;
			next=new process(at,bt,n);
			if(n==1)
			{
				first=p=next;
				p->wt=0;
				p->ct=p->bt;
				p->cal=0;
				p->alloc=1;
			}
			else
			{
				p->next=next;
				p=next;
			}
		}
	}while(ch==1);
	/**********************************************/
	temp=first;
	while(++i<=n)/*while loop to perform SJF*/
	{
		p=first->next;
		while(p!=NULL)/*while loop to find process with lowest burst time when completion time of last process excecuted is less than or equal to arrival time*/
		{
			if(temp->ct>=p->at&&p->cal==1)
			{
				min=p->bt;
			}
			else
			{
				p=p->next;
				continue;
			}
			if(min>=p->bt)
			{
				min=p->bt;
				next=p;
				t=0;
			}
			p=p->next;
		}
		if(t==1)/*if block-while loop to find process when completion time of last process excecuted is greater to arrival time*/
		{
			p=first->next;
			while(p!=NULL)
			{
				if(temp->ct<p->at&&p->cal==1)
				{
					next=p;
					break;
				}
				p=p->next;
			}
		}
		next->cal=0;
		next->alloc=i;
		if(next->at<=temp->ct)/*if-else block to perform calculation on process after applying SJF*/
		{
			next->wt=temp->ct-next->at;
			next->ct=temp->ct+next->bt;
		}
		else
		{
			next->wt=0;
			next->ct=next->bt+next->at;
		}
		t=1;
		temp=next;
	}
	/**********************************************/
	i=1;
	p=first;
	cout<<"\nProcess No.\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n";
	while(p!=NULL)/*Display waiting and turnaround time to user*/
	{
		if(i==p->alloc)
		{
			cout<<setw(6)<<p->n<<setw(16)<<p->at<<setw(16)<<p->bt<<setw(17)<<p->wt<<setw(17)<<p->ct<<setw(16)<<p->ct-p->at<<endl;
			ttat=ttat+p->ct-p->at;
			twt=twt+p->wt;
			p=first;
			i++;
		}
		p=p->next;
	}
	cout<<"\nAverage Turnaround Time:"<<(float)ttat/n<<"\nAverage Waiting Time:"<<(float)twt/n;
	while(p!=NULL)/*Deleting linked list elements*/
	{
		next=p->next;
		delete p;
		p=next;
	}
}
