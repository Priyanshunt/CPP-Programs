#include<iostream>
#include<cstring>
using namespace std;
class X
{
	protected:
		char str[100];
	public:
		X()
		{
			cout<<"Enter first string:";
			gets(str);
		}
		~X()
		{
			cout<<"New String:"<<str;
		}
};
class Y
{
	protected:
		char str1[50];
	public:
		Y()
		{
			cout<<"Enter second string:";
			gets(str1);
		}
		~Y()
		{
			cout<<"Second String:"<<str1<<endl;
		}
};
class Z:public X,public Y
{
	public:
		Z()
		{
			cout<<"First String:"<<str<<endl;
		}
		~Z()
		{
			strcat(str,str1);
		}
};
int main()
{
	Z ob;
	return 0;
}
