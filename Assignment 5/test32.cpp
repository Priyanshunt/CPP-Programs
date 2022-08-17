#include<iostream>
#include<cstring>
using namespace std;
class Alpha
{
	protected:
		int s=0;
		char str[100];
	public:
		Alpha()
		{
			cout<<"Enter first string:";
			gets(str);
		}
		~Alpha()
		{
			cout<<"Number of special characters:"<<s;
		}
};
class Beta
{
	protected:
		int c=0;
		char str1[50];
	public:
		Beta()
		{
			cout<<"Enter second string:";
			gets(str1);
		}
		~Beta()
		{
			cout<<"Number of consonants:"<<c<<endl;
		}
};
class Gamma:public Alpha,public Beta
{
	int n,i,v=0;
	public:
		Gamma()
		{
			strcat(str,str1);
			n=strlen(str);
			for(i=0;i<n;i++)
			{
				if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
					v++;
				else if(str[i]>=65&&str[i]<=90||str[i]>=97&&str[i]<=122)
					c++;
				else
					s++;
			}
			cout<<"New String:"<<str<<endl;
			cout<<"Number of letters:"<<n<<endl;
		}
		~Gamma()
		{
			cout<<"Number of vowels:"<<v<<endl;
		}
};
int main()
{
	Gamma ob;
	return 0;
}
