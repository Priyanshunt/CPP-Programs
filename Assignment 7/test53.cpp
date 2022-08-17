#include<iostream>
using namespace std;
class Complex
{
	float a,b;
	public:
	Complex()
	{
		cout<<"Enter real part of complex number:";
		cin>>a;
		cout<<"Enter imaginary part of complex number:";
		cin>>b;
	}
	void operator+(Complex ob)
	{
		cout<<"Sum of two complex number:"<<a+ob.a<<"+i("<<b+ob.b<<")";
	}
	~Complex(){
	}
};
int main()
{
	Complex obj1,obj2;
	obj1+obj2;
	return 0;
}
