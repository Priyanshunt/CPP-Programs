#include<iostream>
using namespace std;
class small
{
	int i,n,*arr,s;
	public:
	void input();
	void find();
	void display();
};
void small::input()
{
	cout<<"Enter number of integers to be entered:";
	cin>>n;
	arr=new int[n];
	cout<<"Enter integers:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void small::find()
{
	s=arr[0];
	for(i=1;i<n;i++)
	{
		if(s>arr[i])
			s=arr[i];
	}
}
void small::display()
{
	cout<<"Smallest integer:"<<s;
	delete[] arr;
	arr=NULL;
}
int main()
{
	small ob;
	ob.input();
	ob.find();
	ob.display();
	return 0;
}
