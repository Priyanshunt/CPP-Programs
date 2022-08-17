#include<iostream>
using namespace std;
int main()
{
	int i,n,max=0;
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
	int c[max+1];
	for(i=0;i<=max;i++)
	{
		c[i]=0;
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		c[i]+=c[i-1];
	}
	for(i=0;i<n;i++)
	{
		o[--c[a[i]]]=a[i];
	}
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<o[i]<<" ";
	}
}
