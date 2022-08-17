#include<iostream>
using namespace std;
template<class T>void large(T a,T b)
{
	cout<<"Largest of "<<a<<" & "<<b<<" : "<<((a>b)?a:b)<<endl;
}
int main()
{
	large(2,3);
	large('x','y');
	large(4.3,2.7);
	return 0;
}
