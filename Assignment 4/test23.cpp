#include<iostream>
using namespace std;
class thisptr
{
	int n;
	public:
	void set(int);
	thisptr greatest(thisptr);
	void display();
};
void thisptr::set(int n)
{
	this->n=n;
}
thisptr thisptr::greatest(thisptr obj1)
{
	if(n<=obj1.n)
		return obj1;
	else
		return *this;
}
void thisptr::display()
{
	cout<<"Greatest of two numbers:"<<n;
}
int main()
{
	int a,b;
	thisptr ob,ob1,ob2;
	cout<<"Enter first number:";
	cin>>a;
	cout<<"Enter second number:";
	cin>>b;
	ob.set(a);
	ob1.set(b);
	ob2=ob.greatest(ob1);
	ob2.display();
	return 0;
}
