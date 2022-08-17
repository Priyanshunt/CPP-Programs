#include<iostream>
using namespace std;
class matrix
{
	int r,c,m,n;
	float **arr;
	public:
	void getdata();
	void del();
	void show();
	friend matrix operator*(matrix,matrix);
};
void matrix::getdata()
{
	static int i=1;
	cout<<"For matrix "<<i++<<endl;
	cout<<"Enter number of rows:";
	cin>>r;
	cout<<"Enter number of columns:";
	cin>>c;
	arr=new float*[r];
	for(m=0;m<r;m++)
		arr[m]=new float[c];
	cout<<"Enter matrix element row-wise for matrix:"<<endl;
	for(m=0;m<r;m++)
	{
		for(n=0;n<c;n++)
		cin>>arr[m][n];
	}
}
void matrix::show()
{
	cout<<"Resultant matrix:"<<endl;
	for(m=0;m<r;m++)
	{
		for(n=0;n<c;n++)
		cout<<arr[m][n]<<"\t";
		cout<<"\n";
	}
}
matrix operator*(matrix x,matrix y)
{
	int m,n,p;
	matrix z;
	if(x.c==y.r)
	{
		z.arr=new float*[x.r];
		for(p=0;p<x.r;p++)
			z.arr[p]=new float[y.c];
		z.r=x.r;
		z.c=y.c;
		for(m=0;m<x.r;m++)
		{
			for(n=0;n<y.c;n++)
			{
				z.arr[m][n]=0;
				for(p=0;p<y.r&&p<x.c;p++)
					z.arr[m][n]+=x.arr[m][p]*y.arr[p][n];
			}
		}
	}
	return z;
}
void matrix::del()
{
	for(m=0;m<r;m++)
		delete arr[m];
	delete arr;
}
int main()
{
	matrix a,b,c;
	a.getdata();
	b.getdata();
	c=a*b;
	c.show();
	a.del();
	b.del();
	c.del();
	return 0;
}
