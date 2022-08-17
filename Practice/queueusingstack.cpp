#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
	~node()
	{
		//destructor
	}
};
void push(node **top,int d)
{
	node *temp=new node(d);
	if(*top==NULL)
	{
		*top=temp;
	}
	else
	{
		temp->next=*top;
		*top=temp;
	}
}
int pop(node **top)
{
	int d=(*top)->data;
	node *temp=*top;
	*top=(*top)->next;
	delete temp;
	return d;
}
int main()
{
	int n,i,size,x,y,a,b,c,d,t=0;
	node *top1=NULL,*top2=NULL,*top3=NULL,*temp;
	cin>>size;
	for(i=1;i<=size;i++)
	{
		cin>>n;
		push(&top1,n);
		push(&top3,n);
	}
	while(top1!=NULL)
	{
		if(top2==NULL)
		{
			x=pop(&top1);
			push(&top2,x);
		}
		else if(top1->data/10==0&&top2->data/10==0&&abs(top1->data-top2->data)==1)
		{
			a=pop(&top1);
			b=pop(&top2);
			if(a>b)
			{
				push(&top2,a*10+b);
			}
			else
			{
				push(&top2,b*10+a);
			}
		}
		else if(top1->data/10==0&&top2->data/10!=0)
		{
			x=pop(&top1);
			a=pop(&top2);
			b=a%10;
			a=a/10;
			if(abs(x-a)==1||abs(x-b)==1)
			{
				c=a>b?(a>x?a:x):(b>x?b:x);
				d=a>b?(b>x?x:b):(a>x?x:a);
				push(&top2,c*10+d);
			}
			else if(x>a)
			{
				push(&top2,a*10+b);
				push(&top2,x);
			}
			else
			{
				push(&top2,a*10+b);
				push(&top1,x);
				t=1;
			}
		}
		else if(top1->data/10!=0&&top2->data/10==0)
		{
			x=pop(&top2);
			a=pop(&top1);
			b=a%10;
			a=a/10;
			if(abs(x-a)==1||abs(x-b)==1)
			{
				c=a>b?(a>x?a:x):(b>x?b:x);
				d=a>b?(b>x?x:b):(a>x?x:a);
				push(&top2,c*10+d);
			}
			else
			{
				push(&top1,a*10+b);
				push(&top2,x);
				t=1;
			}
		}
		else if(top1->data/10!=0&&top2->data/10!=0)
		{
			a=pop(&top1);
			b=a%10;
			a=a/10;
			c=pop(&top2);
			d=c%10;
			c=c/10;
			if(abs(a-d)==1||abs(b-c)==1)
			{
				x=a>c?a:c;
				y=b>d?d:b;
				push(&top2,x*10+y);
			}
			else
			{
				push(&top1,a*10+b);
				push(&top2,c*10+d);
				t=1;
			}
		}
		else
		{
			x=pop(&top1);
			if(top2->data>x)
			{
				y=pop(&top2);
				push(&top1,y);
				push(&top1,x);
			}
			else
			{
				push(&top2,x);
			}
			t=0;
		}
		if(t==1)
		{
			x=pop(&top1);
			if(top2->data>x)
			{
				y=pop(&top2);
				push(&top1,y);
				push(&top1,x);
			}
			else
			{
				push(&top2,x);
			}
			t=0;
		}
		node* temp1=top1;
		node* temp2=top2;
		cout<<"S1: ";
		while(temp1!=NULL)
		{
			cout<<temp1->data<<" ";
			temp1=temp1->next;
		}
		cout<<endl;
		cout<<"S2: ";
		while(temp2!=NULL)
		{
			cout<<temp2->data<<" ";
			temp2=temp2->next;
		}
		cout<<endl;
		cout<<endl;
	}
//	while(top2!=NULL)
//	{
//		cout<<pop(&top2)<<" ";
//	}
//	cout<<endl;
//	while(top3!=NULL)
//	{
//		if(top1==NULL)
//		{
//			x=pop(&top3);
//			push(&top1,x);
//		}
//		else if(top3->data>top1->data)
//		{
//			x=pop(&top3);
//			push(&top1,x);
//		}
//		else
//		{
//			x=pop(&top3);
//			while(top1!=NULL)
//			{
//				y=pop(&top1);
//				push(&top3,y);
//			}
//			push(&top1,x);
//		}
//	}
//	while(top1!=NULL)
//	{
//		cout<<pop(&top1)<<" ";
//	}
	return 0;
};
