#include<iostream>
using namespace std;
int main()
{
	int n=5;
	//	    *
	//	   * *
	//	  * * *
	//	 * * * *
	//	* * * * *
	for(int i=1;i<=n;i++)//rows loop
	{
		for(int j=n;j>i;j--)
		{
			cout<<" ";
		}
		for(int j=1;j<=i;j++)//columns loop
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	return 0;
}
