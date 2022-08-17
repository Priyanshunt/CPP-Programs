#include<iostream>
int a=1;//Global variable
class Sro
{
	public:
	static int a;//Static variable
	int b;
	void set();
	void display();
};
int Sro::a=2;//Static variable initialisation(not possible inside class)
void Sro::set()//Member function defined outside class
{
	b=4;
}
void Sro::display()//Member function defined outside class
{
	std::cout<<"Value of variable defined inside the class:"<<b;//using built-in libraries
}
int main()
{
	int a=3;//Local variable
	Sro obj;
	obj.set();
	obj.display();
	std::cout<<"\nValue of global variable:"<<::a<<"\nValue of static variable declared inside class:"<<Sro::a<<"\nValue of local variable:"<<a;
	return 0;
}
