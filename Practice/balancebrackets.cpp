#include <bits/stdc++.h>
using namespace std;
class node
{
	public:
	char c;
	node* next;
	node(char ch)
	{
		c=ch;
		node* next=NULL;
	}
};
void bracketCheck(string s) {
	node *top=NULL,*temp;
    char c;
    int i,n=s.length();
    if(n%2==0)
    {
    	cout<<n<<endl;
        for(i=0;i<n;i++)
        {
            if((s[i]=='{')||(s[i]=='[')||(s[i]=='('))
            {
                temp=new node(s[i]);
                temp->next=top;
                top=temp;
                cout<<top->c<<endl;
            }
            else if((top!=NULL)&&(top->c=='{'&&s[i]=='}')||(top->c=='['&&s[i]==']')||(top->c=='('&&s[i]==')'))
            {
            	cout<<s[i]<<endl;
                temp=top;
                top=top->next;
                delete temp;
            }
            else
            {
            	break;
        	}
        }
        if(i==n)
        {
        	cout<<"Brackets are balanced.\n";
        }
        else
        {
        	cout<<"Brackets are not balanced.\n";
		}
    }
    else
    {
    	cout<<"Brackets are not balanced.\n";
	}
}
int main()
{
	string s="{{[[()]()]}}";
	bracketCheck(s);
	return 0;
}
