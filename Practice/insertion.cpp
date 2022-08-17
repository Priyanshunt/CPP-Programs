#include<iostream>
using namespace std;
int main()
{
	int i,j,k,n,t;
	cout<<"Enter array size:";
	cin>>n;
	int a[n];
	cout<<"Enter array elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i])
			{
				break;
			}
		}
		t=a[i];
		for(k=i-1;k>j;k--)
		{
			a[k+1]=a[k];
		}
		a[j+1]=t;
	}
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
