#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	int i,n;
	char ch,str[100];
	fstream dt;
	cout<<"Enter a string:";
	gets(str);
	n=strlen(str);
	dt.open("string.txt",ios::out);
	dt<<str;
	dt.close();
	dt.open("string.txt",ios::in);
	cout<<"All characters of strings:"<<endl;
	for(i=0;i<n;i++)
	{
		dt.get(ch);
		cout<<"'"<<ch<<"',";
	}
	return 0;
}
