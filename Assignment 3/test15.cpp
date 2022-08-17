#include<iostream>
using namespace std;
class complex
{
	static int i;
	float a,b;
	public:
		complex();
		void display();
		complex sum(complex&);
		complex(complex &);
		~complex();
};
int complex::i=0;
complex::complex()
{
	cout<<"Contructing object number:"<<++i<<endl;
	if(i<=2)
	{
		cout<<"Enter real part of complex number "<<i<<":";
		cin>>a;
		cout<<"Enter imaginary part of complex number "<<i<<":";
		cin>>b;
	}
	
}
complex::complex(complex &copy)
{	
	cout<<"Construcing object:"<<++i<<" using copy constructor"<<endl;
}
void complex::display()
{
	cout<<"After adding two complex numbers\nReal part:"<<a<<"\tImaginary part:"<<b<<endl;
}
complex complex::sum(complex &object)
{
	complex o;
	o.a=a+object.a;
	o.b=b+object.b;
	return o;
}
complex::~complex()
{
	cout<<"Destructing object number:"<<i--<<endl;
}
int main()
{
	complex obj1,obj2,obj3;
	obj3=obj2.sum(obj1);
	obj3.display();
}
