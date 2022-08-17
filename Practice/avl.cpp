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
node* left_left_rotation(node *root)
{
	if(root->left!=NULL)
	{
		node* temp=root;
		root=root->left;
		temp->left=root->right;
		root->right=temp;
	}
	return root;
}
node* right_right_rotation(node *root)
{
	if(root->right!=NULL)
	{
		node* temp=root;
		root=root->right;
		temp->right=root->left;
		root->left=temp;
	}
	return root;
}
node* left_right_rotation(node *root)
{
	if(root->left!=NULL)
	{
		root->left=right_right_rotation(root->left);
		root=left_left_rotation(root);
	}
	return root;
}
node* right_left_rotation(node *root)
{
	if(root->right!=NULL)
	{
		root->right=left_left_rotation(root->right);
		root=right_right_rotation(root);
	}
	return root;
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
void display(node* root)
{
	int i=0,j=0,c=1,x,len=7;
	x=(int)pow(2,len)-1;
	node* temp=root;
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
int main()
{
	node *root=NULL,*temp=NULL;
	
	insert(&root,3);
	insert(&root,7);
	insert(&root,5);
	insert(&root,4);
	insert(&root,2);
	insert(&root,6);
	insert(&root,1);

	display(root);
	root=right_left_rotation(root);
	display(root);
}
