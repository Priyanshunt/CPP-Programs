#include<iostream>
using namespace std;
void swap(int a[],int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int partition(int a[],int p,int r)
{
	int q=p,pivot=a[r];
	for(int i=p;i<r;i++)
	{
		if(a[i]<pivot)
		{
			swap(a,i,q++);
		}
	}
	swap(a,q,r);
	return q;
}
void quicksort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=partition(a,p,r);
    	quicksort(a,p,q-1);
    	quicksort(a,q+1,r);
	}
}
int main()
{
	int i,n;
	cout<<"Enter array size:";
	cin>>n;
	int a[n];
	cout<<"Enter array elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
