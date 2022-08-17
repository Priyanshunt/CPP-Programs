#include<iostream>
using namespace std;
class A
{
	protected:
		int a,b;
};
class B:public A
{
	public:
		B()
		{
			cout<<"Enter first number:";
			cin>>a;
		}
};
class C:public A
{
	public:
		C()
		{
			cout<<"Enter second number:";
			cin>>b;
		}
};
class D:public B,public C
{
	public:
		D()
		{
			cout<<"Sum of two numbers:"<<B::a+C::b;
			//scope resolution operator removes ambiguity between original variables in A and inherited variables in B & C
		}
};
int main()
{
	D ob;
	return 0;
}
