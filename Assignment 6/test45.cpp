#include<iostream>
using namespace std;
class copyc
{
	int n;
	public:
	copyc()
	{
		cout<<"Enter a number:";
		cin>>n;
	}
	copyc(copyc &c)
	{
		n=c.n;
	}
	void display()
	{
		cout<<"The number entered:"<<n;
	}
};
int main()
{
	copyc ob1;
	copyc ob2(ob1);
	ob2.display();
	return 0;
}
