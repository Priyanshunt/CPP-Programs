#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,n,max=0,len=0,m;
	cout<<"Enter array size:";
	cin>>n;
	int a[n],o[n];
	cout<<"Enter array elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(max<a[i])
		{
			max=a[i];
		}
	}
	while(max>0)
	{
		max/=10;
		len++;
	}
	for(j=1;j<=len;j++)
	{
		max=0;
		m=(int)pow(10,j);
		for(i=0;i<n;i++)
		{
			if(max<a[i]%m)
			{
				max=a[i]%m;
			}
		}
		int c[max+1];
		for(i=0;i<=max;i++)
		{
			c[i]=0;
		}
		for(i=0;i<n;i++)
		{
			c[a[i]%m]++;
		}
		for(i=1;i<=max;i++)
		{
			c[i]+=c[i-1];
		}
		for(i=0;i<n;i++)
		{
			o[--c[a[i]%m]]=a[i];
		}
		for(i=0;i<n;i++)
		{
			a[i]=o[i];
		}
	}
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
