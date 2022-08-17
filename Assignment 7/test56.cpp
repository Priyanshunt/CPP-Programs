#include<iostream>
using namespace std;
class cal
{
	float a,b,c;
	public:
	void sum()
	{
		c=a+b;
	}
	friend istream& operator>>(istream&,cal&);
	friend ostream& operator<<(ostream&,cal&);
};
istream& operator>>(istream &in,cal &ob)
{
	cout<<"Enter first number:";
	cin>>ob.a;
	cout<<"Enter second number:";
	cin>>ob.b;
	return in;
}
ostream& operator<<(ostream &out,cal &ob)
{
	cout<<"Sum of two numbers:"<<ob.c;
	return out;
}
int main()
{
	cal obj;
	cin>>obj;
	obj.sum();
	cout<<obj;
	return 0;
}
