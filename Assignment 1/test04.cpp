#include<iostream>
using namespace std;
int main()
{
	int n;
	char c;
	cout<<"Enter an integer:";
	cin>>n;
	if(n>0)
	{
		c='P';
	}
	else if(n<0)
	{
		c='N';
	}
	else
	{
		c='Z';
	}
	switch(c)
	{
		case 'P':
			cout<<"Positive.";
			break;
		case 'N':
			cout<<"Negative.";
			break;
		case 'Z':
			cout<<"Zero.";
			break;
		default:
			cout<<"Default case but won't run since number will be positive, negative or zero.";
	}
	return 0;
}
