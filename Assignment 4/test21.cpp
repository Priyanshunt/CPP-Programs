#include<iostream>
using namespace std;
class rectangle
{
	int l,b;
	public:
	rectangle();
	void area();
	~rectangle();
};
rectangle::rectangle()
{
	static int i=1;
	cout<<"Enter length of rectangle "<<i<<":";
	cin>>l;
	cout<<"Enter breadth of rectangle "<<i++<<":";
	cin>>b;
}
void rectangle::area()
{
	static int i=1;
	cout<<"Area of rectangle "<<i++<<":"<<l*b<<endl;
}
rectangle::~rectangle(){
	//Empty definition
}
int main()
{
	int n,i;
	cout<<"Enter number of rectangles:";
	cin>>n;
	rectangle ob[n];
	for(i=0;i<n;i++)
	{
		ob[i].area();
	}
	return 0;
}
