#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
	int n1=q-p+1,n2=r-q;
	int l[n1],m[n2];
	for(int i=0;i<n1;i++)
	{
        l[i]=a[p+i];
    }
    for(int i=0;i<n2;i++)
    {
        m[i]=a[q+1+i];
    }
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
    	if(l[i]<m[j])
		{
			a[p+k++]=l[i++];
		}
		else
		{
			a[p+k++]=m[j++];
		}
	}
	while(i<n1)
	{
		a[p+k++]=l[i++];
	}
	while(j<n2)
	{
		a[p+k++]=m[j++];
	}
}
void mergesort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);
    	mergesort(a,q+1,r);
    	merge(a,p,q,r);
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
	mergesort(a,0,n-1);
	cout<<"Sorted array:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
