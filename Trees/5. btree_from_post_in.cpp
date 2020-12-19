// build a binary tree from given postorder and inorder travs

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	char data;
	node *lc,*rc;
};

node *buildtree(char post[10], char in[10], int b, int e,int *n)	//b-beginning i of subarray, e-last i of subarray, n-current i of pre
{

	if(b>e)		//no child
		return NULL;
		
	int ini;	
	node *x=new node;
	x->data=post[*n];	//root when i=0, parent otherwise
	x->lc=NULL;
	x->rc=NULL;
	(*n)--;
	
	if(b==e)	//leaf
		return x;
	
	for(int i=b;i<=e;i++)
	{
		if(in[i]==x->data)
			ini=i;
	}
	
	x->rc=buildtree(post,in,ini+1,e,n);
	x->lc=buildtree(post,in,b,ini-1,n);
	
	return x;
}

void post_display(node *n)
{
	if(n==NULL)
		return;

	post_display(n->lc);
	post_display(n->rc);
	
	cout<<" "<<n->data;
}


void main()
{
	clrscr();
	int n;
	char post[10],in[10];
	cout<<" Size of postorder and inorder arrays : ";
	cin>>n;
	cout<<endl<<" Accepting postorder array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>post[i];
	}
	
	cout<<endl<<" Accepting inorder array : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>in[i];
	}
	
	cout<<endl<<" Postorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<post[i];
	
	cout<<endl<<" Inorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<in[i];
	
	int l=n-1;
	node *root=new node;
	root=buildtree(post,in,0,n-1,&l);
	
	cout<<endl<<" Cross check postorder : ";
	post_display(root);
	
	getch();
}
	