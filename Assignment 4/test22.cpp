#include<iostream>
using namespace std;
class employee
{
	int id,age,salary;
	string name;
	public:
	void inputInfo();
	void displayInfo();
};
void employee::inputInfo()
{
	static int i=1;
	cout<<"Enter id of employee "<<i<<":";
	cin>>id;
	cout<<"Enter name of employee "<<i<<":";
	gets(name);
	gets(name);
	cout<<"Enter age of employee "<<i<<":";
	cin>>age;
	cout<<"Enter salary of employee "<<i<<":";
	cin>>salary;
}
void employee::displayInfo()
{
	static int i=1;
	cout<<"Details of employee "<<i++<<"\nId:"<<id<<"\nName:"<<name<<"\nAge:"<<age<<"\nSalary:"<<salary<<endl;
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
