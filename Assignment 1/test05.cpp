#include<iostream>
using namespace std;
int main()
{
	int n=5,i;
	cout<<"Printing first n number using for loop:\n";
	for(i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}
	cout<<"\nPrinting first n number using while loop:\n";
	i=1;
	while(i<=n)
	{
		cout<<i++<<" ";
	}
	cout<<"\nPrinting first n number using do-while loop:\n";
	i=1;
	do
	{
		cout<<i++<<" ";
	}
	while(i<=n);
	return 0;
}
