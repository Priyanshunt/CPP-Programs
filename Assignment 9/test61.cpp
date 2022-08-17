#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int i;
	fstream df;
	df.open("NUM.txt",ios::out);
	if(!df)
	{
		cout<<"Error opening file."<<endl;
		return 0;
	}
	for(i=1;i<=200;i++)
	{
		df<<i<<endl;
	}
	df.close();
	return 0;
}
