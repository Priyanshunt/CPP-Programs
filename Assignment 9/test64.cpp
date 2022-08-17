#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream dt,dt1;
	char ch;
	dt.open("file1.txt",ios::in);
	dt1.open("file2.txt",ios::out);
	while(!dt.eof())
	{
		dt.get(ch);
		dt1.put(ch);
	}
	dt.close();
	dt1.close();
	return 0;
}
