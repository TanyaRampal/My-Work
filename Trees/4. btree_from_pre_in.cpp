// build a binary tree from given preorder and inorder travs

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	char data;
	node *lc,*rc;
};

node *buildtree(char pre[10], char in[10], int b, int e)	//b-beginning i of subarray, e-last i of subarray, n-current i of pre
{
	static int n=0;
	if(b>e)		//no child
		return NULL;
		
	int ini;	
	node *x=new node;
	x->data=pre[n];	//root when i=0, parent otherwise
	x->lc=NULL;
	x->rc=NULL;
	n++;
	
	if(b==e)	//leaf
		return x;
	
	for(int i=b;i<=e;i++)
	{
		if(in[i]==x->data)
			ini=i;
	}
	
	x->lc=buildtree(pre,in,b,ini-1);
	x->rc=buildtree(pre,in,ini+1,e);
	
	return x;
}

void pre_display(node *n)
{
	if(n==NULL)
		return;
	cout<<" "<<n->data;		
	
	pre_display(n->lc);
	pre_display(n->rc);
}


void main()
{
	clrscr();
	int n;
	char pre[10],in[10];
	cout<<" Size of preorder and inorder arrays : ";
	cin>>n;
	cout<<endl<<" Accepting preorder array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>pre[i];
	}
	
	cout<<endl<<" Accepting inorder array : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>in[i];
	}
	
	cout<<endl<<" Preorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<pre[i];
	
	cout<<endl<<" Inorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<in[i];
	
	node *root=new node;
	root=buildtree(pre,in,0,n-1);
	
	cout<<endl<<" Cross check preorder : ";
	pre_display(root);
	
	getch();
}
	