#include<iostream>
using namespace std;
class C
{
	public:
		static int a;
		static void inc()
		{
			a++;
		}
};
int C::a=0;
int main()
{
	C o1,o2,o3;
	o1.inc();
	o2.inc();
	o3.inc();
	cout<<"Number of objects:"<<C::a;
}
