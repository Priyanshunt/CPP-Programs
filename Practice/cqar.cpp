#include<iostream>
using namespace std;
int main()
{
	int front=0,rear=0,n,ch,d;
	cout<<"Enter size of queue:";
	cin>>n;
	int a[++n];
	cout<<"Enter 1 to enqueue.\nEnter 2 to dequeue.\n";
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			if(front==(rear+1)%n)
			{
				cout<<"Queue is full.\n";
			}
			else
			{
				cout<<"Enter data:";
				cin>>a[rear];
				rear=(rear+1)%n;
			}
		}
		else if(ch==2)
		{
			if(front==rear)
			{
				cout<<"Queue is empty.\n";
			}
			else
			{
				cout<<"Data deleted:"<<a[front]<<"\n";
				front=(front+1)%n;
			}
		}
	}while(ch!=0);
}
