#include<iostream>
using namespace std;
class shape//base class containing virtual functions
{
	protected:
	float a;
	public:
	virtual void area()//virtual function containing default area
	{
		a=0;
	}
	virtual void display()//virtual function displaying default area
	{
		cout<<"Area of shape:"<<a;
	}
};
class circle:public shape//derived class giving new definition to base class virtual functions
{
	int r;
	public:
	void area()
	{
		cout<<"Enter radius:";
		cin>>r;
		a=3.1418*r*r;
	}
	void display()
	{
		cout<<"Area of circle:"<<a<<endl;
	}
};
class rectangle:public shape
{
	int l,b;
	public:
	void area()
	{
		cout<<"Enter length:";
		cin>>l;
		cout<<"Enter breadth:";
		cin>>b;
		a=l*b;
	}
	void display()
	{
		cout<<"Area of rectangle:"<<a<<endl;
	}
};
class trapezoid:public shape
{
	int l1,l2,h;
	public:
	void area()
	{
		cout<<"Enter first side length:";
		cin>>l1;
		cout<<"Enter second side length:";
		cin>>l2;
		cout<<"Enter height:";
		cin>>h;
		a=0.5*(l1+l2)*h;
	}
	void display()
	{
		cout<<"Area of trapezoid:"<<a<<endl;
	}
};
int main()
{
	shape *ptr,s;
	circle c;
	rectangle r;
	trapezoid t;
	int ch;
	cout<<"Enter\n1 for circle\n2 for rectangle\n3 for trapezoid\nEnter your choice:";
	cin>>ch;//asking choice from user for switch case
	switch(ch)
	{
		case 1:
		ptr=&c;
		ptr->area();
		ptr->display();
		break;
		case 2:
		ptr=&r;
		ptr->area();
		ptr->display();
		break;
		case 3:
		ptr=&t;
		ptr->area();
		ptr->display();
		break;
		default:
		cout<<"Invalid Input.\n";
		ptr=&s;
		ptr->area();
		ptr->display();
	}
	return 0;
}
