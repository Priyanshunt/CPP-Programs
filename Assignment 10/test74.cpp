#include<iostream>
using namespace std;
template<class T> class ll
{
	public:
	ll *p=NULL;
	T val;
	ll()
	{
		val=0;
	}
	void Insert(T a)
	{
		val=a;
	}
	T Pop()
	{
		return val;
	}
	T Next()
	{
		return p->val;
	}
};
int main()
{
	int ch;
	float n;
	ll<float> *ptr=NULL,*next=NULL,*first=NULL;
	do
	{
		cout<<"Enter 1 for insert\nEnter 2 for delete\nEnter 3 for display next element\nEnter any number to quit\nEnter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter a number:";
			cin>>n;
			if(ptr==NULL)
			{
				ptr=new ll<float>;
				ptr->p=NULL;
				first=ptr;
			}
			else
			{
				ptr=new ll<float>;
				ptr->p=next;
			}
			ptr->Insert(n);
			cout<<"The element \""<<n<<"\"is inserted"<<endl;
			next=ptr;
		}
		if(ch==2)
		{
			if(next!=NULL)
			{
				cout<<"The element \""<<next->Pop()<<"\" is deleted"<<endl;
				ptr=next;
				next=next->p;
				delete ptr;
			}
			else
				cout<<"No elements in linked list"<<endl;
		}
		if(ch==3)
		{
			if(next!=NULL)
			{
				if(next->p!=NULL)
				cout<<"The next number in linked list:"<<next->Next()<<endl;
				else
				cout<<"There is one element in linked list. So, there is no next element."<<endl;
			}
			else
				cout<<"There is no element in linked list. So, there is no next element."<<endl;
		}
	}
	while(ch>0&&ch<4);
	return 0;	
}
