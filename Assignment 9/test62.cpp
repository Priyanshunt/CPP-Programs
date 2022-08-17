#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int n=0;
	char ch;
	fstream df;
	df.open("NOTES.txt",ios::in);
	if(!df)
	{
		cout<<"Error opening file."<<endl;
		return 0;
	}
	while(!df.eof())
	{
		df.get(ch);
		if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
			n++;
	}
	cout<<"No. of alphabets:"<<n;
	df.close();
	return 0;
}
