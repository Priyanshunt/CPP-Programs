#include<iostream>
using namespace std;
class complex
{
	float a,b;
	public:
	complex(int a,int b)
	{
		this->a=a;
		this->b=b;
	}
	complex()
	{
		a=1;
		b=2;
	}
	complex sum(complex object)
	{
		complex o;
		o.a=object.a+a;
		o.b=object.b+b;
		return o;
	}
	void display()
	{
		cout<<"After adding two complex numbers\nReal part:"<<a<<"\tImaginary part:"<<b<<endl;
	}
	~complex()
	{
		
	}
};
int main()
{
	int a,b,c;
	cout<<"Enter 1 for using default values for complex numbers\nEnter 2 for manually enter the values of complex numbers\nEnter your choice:";
	cin>>c;
	if(c==1)
	{
	
		cout<<"Enter real part of complex number 1:";
		cin>>a;
		cout<<"Enter imaginary part of complex number 1:";
		cin>>b;
		complex ob1(a,b);
		cout<<"Enter real part of complex number 2:";
		cin>>a;
		cout<<"Enter imaginary part of complex number 2:";
		cin>>b;
		complex ob2(a,b);
		complex ob3;
		ob3=ob2.sum(ob1);
		ob3.display();
	}
	else if(c==2)
	{
		complex ob4,ob5,ob6;
		ob6=ob5.sum(ob4);
		cout<<"Default values for two complex number\nReal part:1\tImaginary part:2"<<endl;
		ob6.display();
	}
	else
		cout<<"Invalid input";
	return 0;
}
