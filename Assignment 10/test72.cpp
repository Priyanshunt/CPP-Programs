#include<iostream>
using namespace std;
template<class T>void swap(T a,T b)
{
	cout<<"Before swapping a:"<<a<<" & b:"<<b<<endl;
	T temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"After swapping a:"<<a<<" & b:"<<b<<endl;
}
int main()
{
	swap(1,2);
	swap(3.4,5.6);
	return 0;
}
