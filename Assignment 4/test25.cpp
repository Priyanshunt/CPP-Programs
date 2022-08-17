#include<iostream>
using namespace std;
class employee
{
	int *id,*age,*salary;
	char *name;
	public:
	employee();
	void inputInfo();
	void displayInfo();
	~employee();
};
employee::employee()
{
	id=new int;
	name=new char[50];
	age=new int;
	salary=new int;
}
void employee::inputInfo()
{
	static int i=1;
	cout<<"Enter id of employee "<<i<<":";
	cin>>*id;
	cout<<"Enter name of employee "<<i<<":";
	gets(name);
	gets(name);
	cout<<"Enter age of employee "<<i<<":";
	cin>>*age;
	cout<<"Enter salary of employee "<<i<<":";
	cin>>*salary;
}
void employee::displayInfo()
{
	static int i=1;
	cout<<"Details of employee "<<i++<<"\nId:"<<*id<<"\nName:"<<name<<"\nAge:"<<*age<<"\nSalary:"<<*salary<<endl;
}
employee::~employee()
{
	delete id;
	id=NULL;
	delete [] name;
	name=NULL;
	delete age;
	age=NULL;
	delete salary;
	salary=NULL;
}
int main()
{
	int n,i;
	cout<<"Enter number of employees:";
	cin>>n;
	employee ob[n];
	for(i=0;i<n;i++)
	{
		ob[i].inputInfo();
	}
	for(i=0;i<n;i++)
	{
		ob[i].displayInfo();
	}
	return 0;
}
