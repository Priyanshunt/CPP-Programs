#include<iostream>
using namespace std;
class Swapc2;
class Swapc1
{
	int a;
	public:
		void input()
		{
			cout<<"Enter first number:";
			cin>>a;
		}
		friend void swap(Swapc1,Swapc2);
};
class Swapc2
{
	int b;
	public:
	void input()
	{
		cout<<"Enter second number:";
		cin>>b;
	}
	friend void swap(Swapc1,Swapc2);
};
void swap(Swapc1 obj1,Swapc2 obj2)
{
	cout<<"Before swapping\nFirst number:"<<obj1.a<<"\tSecond number:"<<obj2.b;
	int t;
	t=obj1.a;
	obj1.a=obj2.b;
	obj2.b=t;
	cout<<"\nAfter swapping\nFirst number:"<<obj1.a<<"\tSecond number:"<<obj2.b;
}
int main()
{
	Swapc1 obj1;
	Swapc2 obj2;
	obj1.input();
	obj2.input();
	swap(obj1,obj2);
	return 0;
}
