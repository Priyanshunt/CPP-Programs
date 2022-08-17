#include<iostream>
#include<cstring>
using namespace std;
class String
{
	char a[100];
	public:
	String()
	{
		cout<<"Enter a string:";
		gets(a);
	}
	void operator==(String ob)
	{
		int n=strcmp(a,ob.a);
		if(n)
			cout<<"String are unequal"<<endl;
		else
			cout<<"String are equal"<<endl;
	}
	void operator+(String ob)
	{
		strcat(a,ob.a);
		cout<<"New string:"<<a;
	}
	~String(){
	}
};
int main()
{
	String obj1,obj2;
	obj1==obj2;
	obj1+obj2;
	return 0;
}
