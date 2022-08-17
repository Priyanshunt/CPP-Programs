#include<iostream>
using namespace std;
int main()
{
	try
	{
		float x,y;
		cout<<"Enter first number:";
		cin>>x;
		cout<<"Enter second number:";
		cin>>y;
		if(y==0)
		{
			throw y;
		}
		cout<<"Division of two numbers:"<<x/y;
		int a;
		cout<<"\nEnter your age:";
		cin>>a;
		if(a<18)
		{
			throw a;
		}
		cout<<"You are eligible to vote.";
		char c;
		cout<<"\nEnter a english alphabet:";
		cin>>c;
		if(c<65||(c>90&&c<97)||c>122)
		{
			throw c;
		}
		cout<<"The ASCII code of alphabet:"<<(int)c;
	}
	catch(float n)
	{
		cout<<"Number is divided by zero.";
	}
	catch(int age)
	{
		cout<<"You are not eligible to vote.";
	}
	catch(char ch)
	{
		cout<<"Character entered is not alphabet.";
	}
	catch(...)
	{
		cout<<"Default catch. Likely to never get executed";
	}
	return 0;
}
