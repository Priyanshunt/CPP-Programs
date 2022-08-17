#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cout<<"Enter first number:";
	cin>>x;
	cout<<"Enter second number:";
	cin>>y;
	try
	{
		try
		{
			if(x==0&&y==0)
			{
				throw x;
			}
		}
		catch(int a)
		{
			cout<<"0 divided by 0 is undefined.";
			return 0;
		}
		try
		{
			if(y==0)
			{
				throw(y);
			}
		}
		catch(int a)
		{
			throw;
		}
	}
	catch(int a)
	{
		cout<<"Number divided by 0 gives infinity.";
		return 0;
	}
	cout<<"Division of two numbers:"<<(float)x/y;
	return 0;
}
