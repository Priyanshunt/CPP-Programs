#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
	protected:
		int roll;
		char name[25];
	public:
		void input()
		{
			cout<<"Enter your roll number:";
			cin>>roll;
			cout<<"Enter your name:";
			gets(name);
			gets(name);
		}
		virtual void display()=0;
};
class Science:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nFollowing students need to take following subjects:-\n1. English Core\n2. Physics\n3. Chemistry\n4. Mathematics(Non-medical)/Biology(Medical)\n5. Any one subject of your choice from Computer Science/Physical Education/Fine Arts\n\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
class Commerce:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nFollowing students need to take following subjects:-\n1. English Core\n2. Economics\n3. Accountancy\n4. Business Studies\n5. Any one subject of your choice from Computer Science/Physical Education/Fine Arts\n\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
class Arts:public Student
{
	public:
		void display()
		{
			static int i=1;
			if(i++==1)
				cout<<"\nFollowing students need to take following subjects:-\n1. English Core\n2. History\n3. Geography\n4. Political Science\n5. Any one subject of your choice from Computer Science/Physical Education/Fine Arts\n\n"<<left<<setw(15)<<"Roll Number"<<"Name"<<endl;
			cout<<left<<setw(15)<<roll<<name<<endl;
		}
};
int main()
{
	int i,n,s;
	cout<<"Enter number of students:";
	cin>>n;
	Student* a[n];
	int c[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nFor student number:"<<i+1<<"\nEnter 1 for Science\nEnter 2 for Commerce\nEnter 3 for Arts/Humanities\nEnter your choice:";
		cin>>s;
		c[i]=s;
		if(s==1)
		{
			a[i]=new Science;
			a[i]->input();
		}
		else if(s==2)
		{
			a[i]=new Commerce;
			a[i]->input();
		}
		else
		{
			a[i]=new Arts;
			a[i]->input();
		}
	}
	for(i=0;i<n;i++)
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
	for(i=0;i<n;i++)
	{
		delete a[i];
		a[i]=NULL;
	}
	return 0;
}
