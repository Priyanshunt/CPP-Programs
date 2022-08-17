#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next=NULL;
};
void insert(struct node **head,int data)
{
	struct node *ptr=new node;
	ptr->data=data;
	if(*head!=NULL)
	{
		ptr->next=*head;
	}
	*head=ptr;
}
void remove(struct node **head,int data)
{
	struct node *p=*head,*p1,*t;
	if((*head)->data==data)
	{
		t=(*head)->next;
		delete *head;
		*head=t;
	}
	else
	{
		while(p->next!=NULL)
		{
			if(p->next->data==data)
			{
				t=p->next->next;
				delete p->next;
				p->next=t;
				return;
			}
			p1=p;
			p=p->next;
		}
		if(p->next==NULL&&p->data==data)
		{
			delete p;
			p=NULL;
			p1->next=NULL;
		}
	}
}
int search(struct node *head,int data)
{
	struct node *p=head;
	while(p!=NULL)
	{
		if(p->data==data)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
int main()
{
	int n,i,ch,num;
	cout<<"Enter hashing mod function parameter value:";
	cin>>n;
	struct node *a[n];
	for(i=0;i<n;i++)
	{
		a[i]=NULL;
	}
	cout<<"Press\n1 to insert\n2 to delete\n3 to search\nany key to exit\n";
	do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter a number to insert:";
			cin>>num;
			int key=num%n;
			insert(&a[key],num);
			cout<<"Number is inserted successfully.\n";
		}
		else if(ch==2)
		{
			cout<<"Enter a number to delete:";
			cin>>num;
			int key=num%n;
			if(search(a[key],num))
			{
				remove(&a[num%n],num);
				cout<<"Number is deleted successfully.\n";
			}
			else
			{
				cout<<"Number to be deleted is not found.\n";
			}
		}
		else if(ch==3)
		{
			cout<<"Enter a number to search:";
			cin>>num;
			int key=num%n;
			if(search(a[key],num))
			{
				cout<<"Number to be searched is found.\n";
			}
			else
			{
				cout<<"Number to be searched is not found.\n";
			}
		}
	}while(ch>0&&ch<4);
	return 0;
}
