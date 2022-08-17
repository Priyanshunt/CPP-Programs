#include<iostream>
using namespace std;
class Publication
{
	string title;
	float price;
	public:
	void getdata()
	{
		
		cout<<"Enter title of publication:";
		cin.ignore();
		getline(cin,title);
		cout<<"Enter price of publication:";
		cin>>price;
	}
	void putdata()
	{
		cout<<"The title of publication:"<<title<<endl;
		cout<<"The price of publication:"<<price<<endl;
	}
};
class Book:public Publication
{
	int pages;
	public:
	void getdata()
	{
		Publication::getdata();
		cout <<"Enter number of pages of book:";
		cin>>pages;
	}
	void putdata()
	{
		Publication::putdata();
		cout<<"The number of pages of book:"<<pages<<endl;
	}
};
class Tape:public Publication
{
	float time;
	public:
	void getdata()
	{
		Publication::getdata();
		cout<<"Enter playing time of tape:";
		cin>>time;
	}
	void putdata()
	{
		Publication::putdata();
		cout<<"The playing time of tape:"<<time<<endl;
	}
};
int main()
{
	Book b;
	Tape t;
	b.getdata();
	t.getdata();
	b.putdata();
	t.putdata();
	return 0;
}
