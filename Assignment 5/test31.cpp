#include<iostream>
#include<iomanip>
using namespace std;
class Student
{
	protected:
		int Rollno;
		char Name[20];
	public:
		void GetDetails()
		{
			cout<<"Enter student roll number:";
			cin>>Rollno;
			cout<<"Enter name of the student:";
			gets(Name);
			gets(Name);
		}
		void DisplayDetails()
		{
			cout<<left<<setw(15)<<Rollno<<setw(25)<<Name;
		}
};
class Marks:public Student
{
	protected:
		int Subject1,Subject2;
	public:
		void GetMarks()
		{
			cout<<"Enter the marks of subject 1:";
			cin>>Subject1;
			cout<<"Enter the marks of subject 2:";
			cin>>Subject2;
			cout<<endl;
		}
		void DisplayMarks()
		{
			cout<<left<<setw(14)<<Subject1<<setw(14)<<Subject2;
		}
};
class Result:public Marks
{
	private:
		int TotalMarks;
	public:
		void CalculateResult()
		{
			TotalMarks=Subject1+Subject2;
		}
		void DisplayResult()
		{
			cout<<left<<setw(25)<<TotalMarks;
			if(Subject1>=33&&Subject2>=33)
				cout<<"Passed"<<endl;
			else
				cout<<"Failed"<<endl;
		}
};
int main()
{
	int n,i;
	cout<<"Enter number of students:";
	cin>>n;
	Result obj[n];
	for(i=0;i<n;i++)
	{
		obj[i].GetDetails();
		obj[i].GetMarks();
	}
	cout<<left<<setw(15)<<"Roll No."<<setw(25)<<"Name"<<setw(14)<<"Subject 1"<<setw(14)<<"Subject 2"<<setw(25)<<"Total Marks obtained"<<"Result"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		obj[i].DisplayDetails();
		obj[i].DisplayMarks();
		obj[i].CalculateResult();
		obj[i].DisplayResult();
	}
	return 0;
}
