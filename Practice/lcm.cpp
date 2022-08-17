#include<iostream>
using namespace std;
int main()
{
	int a=3,c=7,x=1,m=101,i=1;
	do
	{
		x=(a*x+c)%m;
		cout<<i++<<"\t"<<x<<"\n";
	}while(x!=1);
	return 0;
}
