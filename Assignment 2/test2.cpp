#include<iostream>
using namespace std;
class Complex
{
	float a=0,b=0;
	public:
		void set(float *,float *);
		void display();
		Complex sum(Complex);
};
void Complex::set(float *x,float *y)
{
	a=*x;
	b=*y;
}
void Complex::display()
{
	cout<<"After adding two complex numbers\nReal part:"<<a<<"\tImaginary part:"<<b;
}
Complex Complex::sum(Complex object)
{
	Complex o;
	o.a=object.a+a;
	o.b=object.b+b;
	return o;
}
int main()
{
	float c,d;
	Complex obj1,obj2,obj3;
	cout<<"Enter real part of complex number 1:";
	cin>>c;
	cout<<"Enter imaginary part of complex number 1:";
	cin>>d;
	obj1.set(&c,&d);
	cout<<"Enter real part of complex number 2:";
	cin>>c;
	cout<<"Enter imaginary part of complex number 2:";
	cin>>d;
	obj2.set(&c,&d);
	obj3=obj2.sum(obj1);
	obj3.display();
}
