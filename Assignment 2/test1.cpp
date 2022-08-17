#include<iostream>
using namespace std;
class Students
{
	char name[100];
	long roll;
	char degree[100];
	double cgpa;
	char hostel;
	public:
		void addDetails()
		{
			cout<<"Enter name:";
			gets(name);
			gets(name);
			cout<<"Enter roll no.:";
			cin>>roll;
			cout<<"Enter degree:";
			gets(degree);
			gets(degree);
			cout<<"Enter hostel:";
			cin>>hostel;
			cout<<"Enter current CGPA:";
			cin>>cgpa;
		}
		void updateDetails()
		{
			cout<<"Enter name:";
			gets(name);
			gets(name);
			cout<<"Enter roll no.:";
			cin>>roll;
			cout<<"Enter degree:";
			gets(degree);
			gets(degree);
		}
		void updateHostel()
		{
			cout<<"Enter hostel:";
			cin>>hostel;
		}
		void updateCGPA()
		{
			cout<<"Enter current CGPA:";
			cin>>cgpa;
		}
		void display()
		{
			cout<<"Your name:";
			puts(name);
			cout<<"Your roll no.:"<<roll;
			cout<<"\nYour hostel:"<<hostel;
			cout<<"\nYour current CGPA:"<<cgpa<<endl;
		}
		
};
int main()
{
	int n,c,i;
	cout<<"Enter no. of students:";
	cin>>n;
	Students s[n];
	do
	{
		cout<<"Enter 1 to add all details\nEnter 2 to update basic details\nEnter 3 to update hostel\nEnter 4 to update CGPA\nEnter 5 to display details\nEnter 0 to quit\nEnter you choice:";
		cin>>c;
		switch(c)
		{
		case 0:
			exit(0);
			break;
		case 1:
			cout<<"Enter student number:";
			cin>>i;
			if(i<=n)
			{
				s[i].addDetails();
			}
			break;
		case 2:
			cout<<"Enter student number:";
			cin>>i;
			if(i<=n)
			{
				s[i].updateDetails();
			}
			break;
		case 3:
			cout<<"Enter student number:";
			cin>>i;
			if(i<=n)
			{
				s[i].updateHostel();
			}
			break;
		case 4:
			cout<<"Enter student number:";
			cin>>i;
			if(i<=n)
			{
				s[i].updateCGPA();
			}
			break;
		case 5:
			cout<<"Enter student serial number:";
			cin>>i;
			if(i<=n)
				s[i].display();
			break;
		default:
			cout<<"Invalid input\n";
		}
	}
	while(1);
	return 0;
}
