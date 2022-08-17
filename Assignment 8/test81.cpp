#include<iostream>
using namespace std;
class Polygon//base abstract class
{
	protected:
	int w,h;//data members (w for width and h for height)
	public:
	void set_value(int i,int j)//member function to set values to w & h
	{
		w=i;
		h=j;
	}
	virtual void calculate_area()=0;//pure virtual function to find area of different polygons
};
class Rectangle:public Polygon//derived class giving definition to pure virtual function
{
	public:
	void calculate_area()
	{
		cout<<"Area of rectangle:"<<w*h<<endl;
	}
};
class Triangle:public Polygon
{
	public:
	void calculate_area()
	{
		cout<<"Area of triangle:"<<0.5*w*h<<endl;
	}
};
int main()
{
	int w,h;
	cout<<"Enter width:";
	cin>>w;
	cout<<"Enter height:";
	cin>>h;
	Polygon *p;//base class pointer
	Rectangle r;//derived class object
	Triangle t;
	p=&r;//giving reference of derived class object to base class pointer
	p->set_value(w,h);//calling function using base class pointer
	p->calculate_area();
	p=&t;
	p->set_value(w,h);
	p->calculate_area();
	return 0;
}
