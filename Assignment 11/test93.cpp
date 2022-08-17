#include<iostream>
#include<cmath>
using namespace std;
class nl
{
	float a;
	public:
	nl(int x)
	{
		a=x;
	}
	void calculate()
	{
		try
		{
			if(a<=0)
			{
				throw *this;
			}
			cout<<"Natural logarithm of "<<a<<":"<<log(a);
		}
		catch(nl eo)
		{
			throw;
		}
	}
	~nl(){
	}
};
int main()
{
	int n;
	cout<<"Enter a number:";
	cin>>n;
	nl obj(n);
	try
	{
		obj.calculate();
	}
	catch(nl exp)
	{
		cout<<"Entered number is less than or equal to 0.";
	}
	return 0;
}
