#include<iostream>
#include<math.h>
using namespace std;
void triangle(int a)
{
	cout<<"Area of triangle:"<<sqrt(3)/4*a*a;
}
void triangle(int a,int b)
{
	cout<<"Area of triangle:"<<b/4*sqrt(4*a*a-b*b);
}
void triangle(int a,int b,int c)
{
	int s=(a+b+c)/2;
	cout<<"Area of triangle:"<<sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
	int c,p,q,r;
	cout<<"Enter 1 for equilaterial triangle\nEnter 2 for isosceles triangle\nEnter 3 for scalene triangle\nEnter your choice:";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter side of equilateral triangle:";
			cin>>p;
			triangle(p);
			break;
		case 2:
			cout<<"Enter equal side of isosceles triangle:";
			cin>>p;
			cout<<"Enter base of isosceles triangle:";
			cin>>q;
			triangle(p);
			break;
		case 3:
			cout<<"Enter first side of scalene triangle:";
			cin>>p;
			cout<<"Enter second side of scalene triangle:";
			cin>>q;
			cout<<"Enter third of scalene triangle:";
			cin>>r;
			triangle(p);
			break;
		default:
			cout<<"Invalid input";
	}
	return 0;
}
