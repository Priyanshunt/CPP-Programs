#include<iostream>
using namespace std;
class Test
{
	double func1(double a)
	{
		return a*a;
	}
	public:
		void func2()
		{
			double n,r;
			cout<<"Enter a number:";
			cin>>n;
			r=func1(n);
			cout<<"Square of number:"<<r;
		}
};
int main()
{
	Test obj1;
	obj1.func2();
	return 0;
}
