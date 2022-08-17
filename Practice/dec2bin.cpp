#include<iostream>
using namespace std;
int main()
{
	int n=123;
	int n1=0;
	while(n>0)
	{
		int d=n%2;
		n1=n1*10+d;
		n=n/2;
	}
	while(n1>0)
	{
		int d=n1%10;
		n=n*10+d;
		n1=n1/10;
	}
	cout<<n;
	return 0;
}
