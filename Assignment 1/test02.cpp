#include<iostream>
using namespace std;
int main()
{
	int n=300,c=0,j,k=0,d;
	int a[n]={0};
	for(int i=2;i<=n;i++)
	{
		d=i/2;
		for(j=0;a[j]!=0&&a[j]<=d;j++)
		{
			if(i%a[j]==0)
			{
				c=1;
				break;
			}
		}
		if(c==0)
		{
			a[k++]=i;
			cout<<i<<endl;
		}
		else
		{
			c=0;
		}
	}
	return 0;
}
