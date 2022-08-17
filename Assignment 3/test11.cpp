#include<iostream>
using namespace std;
class DB;
class DM
{
	double a;
	public:
	void input()
	{
		cout<<"Enter distance in centimetres:";
		cin>>a;
	}
	friend void add(DM,DB);
};
class DB
{
	double b;
	public:
	void input()
	{
		cout<<"Enter distance in inches:";
		cin>>b;
	}
	friend void add(DM,DB);
};
void add(DM x,DB y)
{
	cout<<"Sum of distances in centimetres:"<<x.a+(y.b)/2.5;
	cout<<"\nSum of distances in inches:"<<(x.a)*2.5+y.b;
}
int main()
{
	DM obj1;
	DB obj2;
	obj1.input();
	obj2.input();
	add(obj1,obj2);
	return 0;
}
