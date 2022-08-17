#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};
bool search(node *head,int d)
{
	node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==d)
		{
			return true;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		return false;
	}
}
int main()
{
	int ch,d,n;
	node *head=NULL,*temp;
	cout<<"Enter\n1 to insert number\n2 to delete number\n3 to search\n4 to display\n5 to quit\n";
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter number to insert:";
			cin>>d;
			if(head==NULL)
			{
				head=new node(d);
			}
			else
			{
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=new node(d);
			}
			cout<<"Number is inserted successfully.\n";
		}
		else if(ch==2)
		{
			cout<<"Enter number to delete:";
			cin>>d;
			if(search(head,d))
			{
				temp=head;
				node *prev;
				while(temp!=NULL)
				{
					if(temp->data==d)
					{
						if(temp==head)
						{
							node *ptr=head->next;
							delete head;
							head=ptr;
						}
						else
						{
							prev->next=temp->next;
							delete temp;
						}
						break;
					}
					prev=temp;
					temp=temp->next;
				}
				cout<<"Number is deleted successfully.\n";
			}
			else
			{
				cout<<"Number to delete is not found.\n";
			}
		}
		else if(ch==3)
		{
			cout<<"Enter number to search:";
			cin>>d;
			if(search(head,d))
			{
				cout<<"Number to search is found.\n";
			}
			else
			{
				cout<<"Number to search is not found.\n";
			}
		}
		else if(ch==4)
		{
			if(head==NULL)
			{
				cout<<"No numbers to display.\n";
			}
			else
			{
				int i=0;
				temp=head;
				while(temp!=NULL)
				{
					cout<<++i<<". "<<temp->data<<endl;
					temp=temp->next;
				}
			}
		}
		else if(ch==5)
		{
			break;
		}
		else
		{
			cout<<"Invalid choice.\n";
		}
	}while(true);
	return 0;
}
