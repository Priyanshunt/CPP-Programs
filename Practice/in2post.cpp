#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node *next=NULL;
}*top=NULL;
int prec(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*'||c=='/')
	{
		return 2;
	}
	else if(c=='+'||c=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(char c)
{
	struct node *ptr=new node();
	ptr->data=c;
	if(top!=NULL)
	{
		ptr->next=top;
	}
	top=ptr;
}
char pop()
{
	char c;
	struct node *ptr=top->next;
	c=top->data;
	delete(top);
	top=ptr;
	return c;
}
int main()
{
	struct node *ptr;
	string str;
	char x,c;
	cout<<"Enter infix expression:";
	getline(cin>>ws,str);
	cout<<"Postfix expression:";
	for(int i=0;i<str.size();i++)
	{
		x=str[i];
		if((x>=65&&x<=90)||(x>=97&&x<=122)||(x>=48&&x<=57))
		{
			cout<<x;
		}
		else if(x==')')
		{
			c=pop();
			while(c!='(')
			{
				cout<<c;
				c=pop();
			}
		}
		else if(x=='(')
		{
			push('(');
		}
		else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			while(top!=NULL&&top->data!='(')
			{
				if(prec(top->data)>=prec(x))
				{
					cout<<pop();
				}
				else
				{
					break;
				}
			}
			push(x);
		}
		else
		{
			cout<<"\nInvalid infix expression";
			break;
		}
	}
	while(top!=NULL)
	{
		cout<<pop();
	}
	return 0;
}
