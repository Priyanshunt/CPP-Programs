#include<iostream>
using namespace std;
class unary
{
	int n;
	public:
	unary()
	{
		cout<<"Enter a number:";
		cin>>n;
	}
	unary operator-()
	{
		n=-n;
	}
	void display()
	{
		cout<<"The number after changing its arithmetic sign:"<<n;
	}
	~unary(){	
	}
};
int main()
{
	unary obj;
	-obj;
	obj.display();
	return 0;
}
