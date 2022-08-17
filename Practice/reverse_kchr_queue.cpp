#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL;
};
struct node *first=NULL,*last=NULL,*initlast;
void enqueue(int n)
{
	struct node *ptr;
	ptr=new node();
	ptr->data=n;
	if(first==NULL)
	{
		first=last=ptr;
	}
	else
	{
		 last->next=ptr;
		 last=ptr;
	}
}
int dequeue()
{
	struct node *ptr;
	ptr=first->next;
	int n=first->data;
	delete(first);
	first=ptr;
	if(first==NULL)
	{
		last=NULL;
	}
	return n;
}
void reverse(int k)
{
	int n;
	if(first==initlast)
	{
		n=dequeue();
		initlast=NULL;
	}
	else if(k>1)
	{
		n=dequeue();
		reverse(--k);	
	}
	else
	{
		n=dequeue();
	}
	enqueue(n);	
}
int main()
{
	struct node *p;
	int ch,n,i=0,k;
	cout<<"Enter 1 to enter elements of queue or press any key to exit.\nEnter choice:";
	cin>>ch;
	while(ch==1)
	{
		cout<<"Enter data:";
		cin>>n;
		enqueue(n);
		cout<<"Enter choice:";
		cin>>ch;
	}
	initlast=last;
	p=first;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	cout<<"\nEnter value of k where every k nodes is to be reversed in queue:";
	cin>>k;
	while(initlast!=NULL)
	{
		reverse(k);
	}
	p=first;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
	return 0;
}
