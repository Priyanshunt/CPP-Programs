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
	string str,s="";
	char x,c;
	cout<<"Enter infix expression:";
	getline(cin>>ws,str);
	cout<<"Prefix expression:";
	for(int i=str.size()-1;i>=0;i--)
	{
		x=str[i];
		if((x>=65&&x<=90)||(x>=97&&x<=122)||(x>=48&&x<=57))
		{
			s+=x;
		}
		else if(x=='(')
		{
			c=pop();
			while(c!=')')
			{
				s+=c;
				c=pop();
			}
		}
		else if(x==')')
		{
			push(')');
		}
		else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
		{
			while(top!=NULL&&top->data!='(')
			{
				if(prec(top->data)>=prec(x))
				{
					s+=pop();
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
		s+=pop();
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
