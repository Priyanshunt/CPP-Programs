#include <iostream>
using namespace std;
template<class T>class Cal
{
	private:
	T a, b;
	public:
	Cal(T x, T y)
	{
		a=x;
		b=y;
	}
	void display()
	{
		cout<<a<<" + "<<b<<" = "<<a+b<<endl;
		cout<<a<<" - "<<b<<" = "<<a-b<<endl;
		cout<<a<<" * "<<b<<" = "<<a*b<<endl;
		cout<<a<<" / "<<b<<" = "<<a/b<<endl;
	}
};
int main()
{
	Cal<int> obj(1,2);
	Cal<float> obj1(3.4,5.6);
	obj.display();
	obj1.display();
	return 0;
}
