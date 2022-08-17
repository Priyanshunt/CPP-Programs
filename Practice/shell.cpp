#include<iostream>
using namespace std;
int main()
{
	int i,j,n,t,gap;
	cout<<"Enter array size:";
	cin>>n;
	int a[n];
	gap=n/2;
	cout<<"Enter array elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(gap>=1)
	{		
		for(i=gap;i<n;i++)
		{
			for(j=i;j>=gap;j-=gap)
			{
				if(a[j]<a[j-gap])
				{
					t=a[j];
					a[j]=a[j-gap];
					a[j-gap]=t;
				}
				else
				{
					break;
				}
			}
		}
		gap/=2;
	}
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
