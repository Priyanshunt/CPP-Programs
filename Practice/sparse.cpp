#include<iostream>
using namespace std;
class node
{
	public:
	int d;
	int i;
	int j;
	node *next;
	node(int n,int r,int c)
	{
		d=n;
		i=r;
		j=c;
		next=NULL;
	}
	~node()
	{
		//Destructor
	}
};
int main()
{
	int n,r,c,ch,nr,nc;
	node *head1=NULL,*head2=NULL,*ptr,*p,*temp;
	cout<<"The code is designed to perform operations in row major format.\nSo please enter the entries of matrix in row major form only.\n";
	cout<<"Enter total number of rows and columns:";
	cin>>nr>>nc;
	cout<<"Enter the elements of first sparse matrix.\nPress 1 to enter or any key to exit.\nChoice:";
	cin>>ch;
	while(ch==1)
	{
		cout<<"Number Row Column:";
		cin>>n>>r>>c;
		ptr=new node(n,r,c);
		if(head1==NULL)
		{
			p=head1=ptr;
		}
		else
		{
			p->next=ptr;
			p=p->next;
		}
		cout<<"Choice:";
		cin>>ch;
	}
	cout<<"Enter the elements of second sparse matrix.\nPress 1 to enter or any key to exit.\nChoice:";
	cin>>ch;
	while(ch==1)
	{
		cout<<"Number Row Column:";
		cin>>n>>r>>c;
		ptr=new node(n,r,c);
		if(head2==NULL)
		{
			p=head2=ptr;
		}
		else
		{
			p->next=ptr;
			p=p->next;
		}
		cout<<"Choice:";
		cin>>ch;
	}
	p=head1;
	if(head1!=NULL)
	{
		p=head2;
		ptr=NULL;
		while(p!=NULL&&(p->i<head1->i||(p->i==head1->i&&p->j<head1->j)))
		{
			ptr=p;
			p=p->next;
		}
		
		if(ptr!=NULL)
		{
			ptr->next=head1;
			ptr=head1;
			head1=head2;
			head2=p;
			p=ptr;
		}
	}
	while(p!=NULL&&head2!=NULL)
	{
		if((head2->i==p->i&&head2->j>p->j)||head2->i>p->i)
		{
			ptr=p;
			p=p->next;
		}
		else if(head2->i==p->i&&head2->j==p->j)
		{
			ptr=head2->next;
			p->d+=head2->d;
			delete head2;
			head2=ptr;
		}
	}
	if(head2!=NULL)
	{
		ptr->next=head2;
	}
	p=head1;
	for(int m=1;m<=nr;m++)
	{
		for(int n=1;n<=nc;n++)
		{
			if(p!=NULL&&p->i==m&&p->j==n)
			{
				cout<<p->d<<" ";
				p=p->next;
			}
			else
			{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
	return 0;
}
