#include<iostream>
using namespace std;
void swap(int a[],int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void max_heapify(int a[],int i,int len)
{
	int left=2*i,right=2*i+1,max=i;
	if(left<=len&&a[left]>a[max])
	{
		max=left;
	}
	if(right<=len&&a[right]>a[max])
	{
		max=right;
	}
	if(max!=i)
	{
		swap(a,i,max);
		max_heapify(a,max,len);
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	int len=n;
	int a[n+1];
	cout<<"Enter elements:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<n;j++)
	{
		for(int i=len/2;i>=1;i--)
		{
			max_heapify(a,i,len);
		}
		swap(a,1,len);
		len--;
	}
	cout<<"Sorted array:";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
