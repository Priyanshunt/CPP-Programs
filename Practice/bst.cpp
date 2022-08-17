#include<iostream>
#include<math.h>
using namespace std;
class node
{
	public:
	int n;
	node* left=NULL;
	node* right=NULL;
};
void max(node* temp)
{
	if(temp->right)
	{
		temp=temp->right;
		max(temp);
	}
	else
	{
		cout<<temp->n;
	}
}
void levelorder(node *temp)
{
	if(temp!=NULL)
	{
		if(temp->left!=NULL)
		{
			levelorder(temp->left);
		}
		cout<<temp->n<<" ";
		if(temp->right!=NULL)
		{
			levelorder(temp->right);
		}
	}
}
void preorder(node* temp)
{
	if(temp!=NULL)
	{
		cout<<temp->n<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(node* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->n<<" ";
		inorder(temp->right);
	}
}
void postorder(node* temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->n<<" ";
	}
}
void insert(node **root,int n)
{
	node *temp;
	if(*root==NULL)
	{
		*root=new node();
		(*root)->n=n;
	}
	else
	{
		temp=*root;
		while(1)
		{
			if(n<temp->n)
			{
				if(temp->left!=NULL)
				{
					temp=temp->left;
				}
				else
				{
					temp->left=new node();
					temp->left->n=n;
					break;
				}
			}
			else
			{
				if(temp->right!=NULL)
				{
					temp=temp->right;
				}
				else
				{
					temp->right=new node();
					temp->right->n=n;
					break;
				}
			}
		}
	}
}
int numcheck(node *temp,int n)
{
	while(temp!=NULL)
	{
		if(temp->n==n)
		{
			return 1;
		}
		else if(temp->n<n)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	return 0;
}
void lca(node **root,int a,int b)
{
	node *temp=*root,*ptr=NULL;
	if(a>b)
	{
		int c=a;
		a=b;
		b=c;
	}
	while(temp!=NULL&&!((temp->n)>=a&&(temp->n)<=b))
	{
		if(temp->n>a&&temp->n>b)
		{
			temp=temp->left;
		}
		else if(temp->n<a&&temp->n<b)
		{
			temp=temp->right;
		}
		else
		{
			temp=NULL;
			break;
		}
	}
	if(temp!=NULL)
	{
		cout<<temp->n<<endl;
	}
	else
	{
		cout<<"No such node exist."<<endl;
	}
}
int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return 1+max(height(root->left),height(root->right));
	}
}
int dia(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int lh=height(root->left);
		int rh=height(root->right);
		int ld=dia(root->left);
		int rd=dia(root->right);
		return max(lh+rh+1,max(ld,rd));
	}
}
int main()
{
	int len=7,ch,n;
	node *root=NULL,*temp=NULL;
	/*
	insert(&root,40);
	insert(&root,50);
	insert(&root,22);
	insert(&root,33);
	insert(&root,30);
	insert(&root,80);
	insert(&root,15);
	insert(&root,25);
	insert(&root,60);
	insert(&root,90);
	insert(&root,75);
	insert(&root,44);
	*/
	
	insert(&root,4);
	insert(&root,2);
	insert(&root,6);
	insert(&root,1);
	insert(&root,3);
	insert(&root,5);
	insert(&root,7);
	
	cout<<"Enter 1 to insert node.\n\t2 to delete node.\n\t3 to search node.\n\t4 to display BST\nPress any key to exit.\n";
	do
	{
		levelorder(root);
		cout<<"\nEnter you choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the number to insert:";
			cin>>n;
			insert(&root,n);
			++len;
		}
		else if(ch==2)
		{
			node* temp1;
			cout<<"Enter a number:";
			cin>>n;
			if(numcheck(root,n))
			{
				temp=root;
				
				while(temp->n!=n)
				{
					temp1=temp;
					if(temp->n>n)
					{
						temp=temp->left;
					}
					else
					{
						temp=temp->right;
					}
				}
				if(temp->left==NULL&&temp->right==NULL)
				{
					if(temp==root)
					{
						root=NULL;
					}
					if(temp1->left->n==n)
					{
						temp1->left=NULL;
					}
					else
					{
						temp1->right=NULL;
					}
					delete temp;
				}
				else if(temp->left==NULL)
				{
					if(temp==root)
					{
						root=temp->right;
					}
					else if(temp1->left->n==n)
					{
						temp1->left=temp->right;
					}
					else
					{
						temp1->right=temp->right;
					}
					delete temp;
					temp=NULL;
				}
				else if(temp->right==NULL)
				{
					if(temp==root)
					{
						root=temp->left;
					}
					else if(temp1->right->n==n)
					{
						temp1->right=temp->left;
					}
					else
					{
						temp1->left=temp->left;
					}
					delete temp;
					temp=NULL;
				}
				else
				{
					if(temp->right->left==NULL)
					{
						temp->n=temp->right->n;
						delete temp->right;
						temp->right=NULL;
					}
					else
					{
						temp1=temp->right;
						while(temp1->left->left!=NULL)
						{
							temp1=temp1->left;
						}
						temp->n=temp1->left->n;
						delete temp1->left;
						temp1->left=NULL;
					}
				}
			}
			else
			{
				cout<<"Not found.";
			}
		}
		else if(ch==3)
		{
			cout<<"Enter a number:";
			cin>>n;
			if(numcheck(root,n))
			{
				cout<<"Found.";
			}
			else
			{
				cout<<"Not found.";
			}
		}
		else if(ch==4)
		{
			int i=0,j=0,c=1,x;
			x=(int)pow(2,len)-1;
			temp=root;
			if(root!=NULL)
			{
				node* a[x]={NULL};
				a[j++]=root;
				while(j<x)
				{
					if(a[i]!=NULL&&a[i]->left!=NULL)
					{
						a[j]=a[i]->left;
					}
					j++;
					if(a[i]!=NULL&&a[i]->right!=NULL)
					{
						a[j]=a[i]->right;
					}
					i++;
					j++;
				}
				for(i=0;i<x;i++)
				{
					if(a[i]!=NULL)
					{
						cout<<a[i]->n<<" ";
					}
					else
					{
						cout<<"  ";
					}
					if(i+1==(int)pow(2,c)-1)
					{
						cout<<endl;
						c++;
					}
				}
			}
			else
			{
				cout<<"Tree is empty.";
			}
		}
		else if(ch==5)
		{
			preorder(root);
		}
		else if(ch==6)
		{
			inorder(root);
		}
		else if(ch==7)
		{
			postorder(root);
		}
		else if(ch==8)
		{
			max(root);
		}
		else if(ch==9)
		{
			int a,b;
			cout<<"Enter first number:";
			cin>>a;
			cout<<"Enter second number:";
			cin>>b;			
			lca(&root,a,b);
		}
	}
	while(ch>0&&ch<10);
}
