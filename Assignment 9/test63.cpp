#include<iostream>
#include<fstream>
using namespace std;
class cal
{
	float a=0,b=0,c=0;
	public:
	void get()
	{
		cout<<"Enter first number:";
		cin>>a;
		cout<<"Enter second number:";
		cin>>b;
	}
	void sum()
	{
		c=a+b;
	}
	void display()
	{
		cout<<"Sum of two numbers:"<<c;
	}
};
int main()
{
	cal obj,obj1;
	obj.get();
	fstream dt;
	dt.open("binary.txt",ios::out|ios::binary);
	dt.write((char*)&obj,sizeof(obj));
	dt.close();
	dt.open("binary.txt",ios::in|ios::binary);
	dt.read((char*)&obj1,sizeof(obj1));
	dt.close();
	obj1.sum();
	obj1.display();
	return 0;
}
