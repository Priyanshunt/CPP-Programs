#include<iostream>
using namespace std;
class FLOAT
{
	float n;
	public:
	FLOAT()
	{
		static int i=1;
		if(i++<=2)
		{
			cout<<"Enter a decimal number:";
			cin>>n;
		}
	}
	void operator+(FLOAT ob)
	{
		cout<<n<<" + "<<ob.n<<" = "<<n+ob.n<<endl;
	}
	void operator-(FLOAT ob)
	{
		cout<<n<<" - "<<ob.n<<" = "<<n-ob.n<<endl;
	}
	void operator*(FLOAT ob)
	{
		cout<<n<<" * "<<ob.n<<" = "<<n*ob.n<<endl;
	}
	void operator/(FLOAT ob)
	{
		cout<<n<<" / "<<ob.n<<" = "<<n/ob.n<<endl;
	}
	~FLOAT(){	
	}
};
int main()
{
	FLOAT obj1,obj2;
	obj1+obj2;
	obj1-obj2;
	obj1*obj2;
	obj1/obj2;
	return 0;
}
