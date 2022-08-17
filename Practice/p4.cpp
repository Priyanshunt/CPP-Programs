#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int pi;
	int at;
	int bt;
	int c;
	node *next;
	node(int p,int a,int b)
	{
		pi=p;
		at=a;
		bt=b;
		next=NULL;
		c=1;
	}
	~node()
	{
		//destructor
	}
};
void enqueue(node **scll,int p,int a,int b)
{
	node* ptr=new node(p,a,b);
	if(*scll==NULL)
	{
		*scll=ptr;
		(*scll)->next=(*scll);
	}
	else
	{
		ptr->next=(*scll)->next;
		(*scll)->next=ptr;
		*scll=ptr;
	}
}
void dequeue(node **scll)
{
	if((*scll)->next==*scll)
	{
		delete *scll;
		*scll=NULL;
	}
	else
	{
		node *temp=*scll;
		while(temp->next!=*scll)
		{
			temp=temp->next;
		}
		*scll=temp;
		node *ptr=(*scll)->next->next;
		delete (*scll)->next;
		(*scll)->next=ptr;
	}
}
void insert(node **ll,int p,int a,int b)
{
	node *ptr,*temp;
	ptr=new node(p,a,b);
	if(*ll==NULL)
	{
		*ll=ptr;
	}
	else
	{
		temp=*ll;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
}
void remove(node **ll,int time)
{
    if(*ll!=NULL&&(*ll)->at==time) 
    {
    	node *temp=(*ll)->next;
        delete *ll;
        *ll=temp;
    }
	else
	{
		node* temp=(*ll)->next,*prev=*ll;  
	    while(temp!=NULL&&temp->at!=time) 
	    { 
	        prev=temp; 
	        temp=temp->next; 
	    }
    	if(temp!=NULL)
	  	{
		    prev->next=temp->next; 
		    delete temp;
		}
	}
}
int main()
{
	node *ll=NULL;
	node *scll=NULL,*temp,*ptr;
	int n,a,b,p,time=0,tq=1,count=0,t=0,pt,d,e,tx;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>a>>b;
		insert(&ll,p,a,b);
	}
	while(ll!=NULL||scll!=NULL)
	{
		tx=t;
		temp=ll;
		while(temp!=NULL)
		{
			if(temp->at==time)
			{
				t++;
				enqueue(&scll,temp->pi,temp->at,temp->bt);
				remove(&ll,time);
			}
			temp=temp->next;
		}
		if(scll==NULL&&tx==t)
		{
			++time;
			continue;
		}
		temp=scll;
		d=temp->pi;
		scll=scll->next;
		ptr=temp->next;
		pt=time;
		while(scll!=NULL&&time==pt)
		{
			if(time>=scll->at&&scll->c==1)
			{
				if(scll->bt>0)
				cout<<scll->pi<<" ";
				if(--scll->bt<=0)
				{
					e=scll->pi;
					dequeue(&scll);
					if(d==e)
					{
						temp=scll;
					}
					t--;
				}
				else
				{
					scll->c=0;
					scll=scll->next;
				}
				time++;
			}
			else
			{
				scll=scll->next;
				ptr=scll;
				if(count==t)
				{
					count=0;
					do
					{
						ptr->c=1;
						ptr=ptr->next;
					}while(ptr!=scll);
					scll=temp->next;
				}
				count++;
			}
		}
		count=0;
		scll=temp;
	}		
	return 0;
}
