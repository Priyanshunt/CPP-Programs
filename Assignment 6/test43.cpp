#include<iostream>
using namespace std;
void display()
{
	cout<<"*"<<endl;
}
void display(char c)
{
	cout<<c<<endl;
}
void display(char c,int n)
{
	for(int i=1;i<=n;i++)
		cout<<c;
}
int main()
{
	cout<<"No arguments passed:";
	display();
	cout<<"\nFirst arguments passed:";
	display('#');
	cout<<"\nBoth arguments passed:";
	display('$',5);
	return 0;
}
