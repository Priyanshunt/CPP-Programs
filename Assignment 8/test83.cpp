#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
	protected:
		int roll;
		char name[25];
	public:
		void input()//function to accept and store details of students
		{
			cout<<"Enter your roll number:";
			cin>>roll;
			cout<<"Enter your name:";
			gets(name);
			gets(name);
		}
		virtual void display()=0;//pure virtual function
};
class Engineering:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nEngineering students\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
class Medicine:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nMedicine students\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
class Science:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nScience students\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
int main()
{
	int i,n,s;
	cout<<"Enter number of students:";
	cin>>n;
	Student *a[n];//Array of pointers
	int c[n];
	cout<<"\nFor student number:"<<i+1<<"\nEnter 1 for Engineering\nEnter 2 for Medicine\nEnter 3 for Science\n";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter your choice:";
		cin>>s;
		c[i]=s;
		if(s==1)
		{
			a[i]=new Engineering;//dynamic allocation of memory to base class pointer
			a[i]->input();
		}
		if(s==2)
		{
			a[i]=new Medicine;
			a[i]->input();
		}
		if(s==3)
		{
			a[i]=new Science;
			a[i]->input();
		}
	}
	for(i=0;i<n;i++)//displaying students details stream wise
	{
		if(c[i]==1)
			a[i]->display();
	}
	for(i=0;i<n;i++)
	{
		if(c[i]==2)
			a[i]->display();
	}
	for(i=0;i<n;i++)
	{
		if(c[i]==3)
			a[i]->display();
	}
	for(i=0;i<n;i++)//deallocating memory of base class pointers
	{
		delete a[i];
		a[i]=NULL;
	}
	return 0;
}
