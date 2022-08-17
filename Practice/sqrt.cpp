#include<bits/stdc++.h>
using namespace std;
double func(long long int n)
{
	for(int i=1;i*i<=n;i++)
	{
		if((n%i==0)&&(n/i==i))
		{
			return 1;
		}
	}
	return -1;
}
int main()
{
	long long int=25;
	cout<<func(25)<<endl;
}
