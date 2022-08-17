#include<iostream>
using namespace std;
int main()
{
	int n=5;
	int a=0;
	int b=1;
	while(n>0){
		int c=a+b;
		a=b;
		b=c;
		n--;
	    cout<<b;
	
	}
	cout<<b;

	return 10;
}
