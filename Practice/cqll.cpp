#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL;
};
int main()
{
	struct node *head=NULL,*p,*ptr;
	int ch,d;
	cout<<"Enter 1 to enqueue.\nEnter 2 to dequeue.\n";
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter data:";
			cin>>d;
			ptr=new node();
			ptr->data=d;
			if(head==NULL)
			{
				head=ptr;
				head->next=head;
			}
			else
			{
				ptr->next=head->next;
				head->next=ptr;
				head=ptr;
			}
		}
		else if(ch==2)
		{
			if(head==NULL)
			{
				cout<<"No element to dequeue.\n";
			}
			else
			{
				if(head->next==head)
				{
					cout<<"Element dequeued:"<<head->data<<"\n";
					delete(head);
					head=NULL;
				}
				else
				{
					p=head->next->next;
					cout<<"Element dequeued:"<<head->next->data<<"\n";
					delete(head->next);
					head->next=p;
				}
			}
		}
	}while(ch!=0);
}
