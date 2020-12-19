// build a binary tree from given postorder and inorder travs every node has 2 children


#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	char data;
	node *lc,*rc;
};

node *buildtree(char pre[10], char post[10], int b, int *e,int *n)	//b-beginning i of subarray, e-last i of subarray, n-current i of pre
{
	if(b>*e)		//no child
		return NULL;
		
	int pri;	
	node *x=new node;
	x->data=post[*n];	
	x->lc=NULL;
	x->rc=NULL;
	(*n)--;
	
	for(int i=b;i<=*e;i++)
	{
		if(pre[i]==x->data)
			pri=i;
	}
	
	if(i==*e)
	{
		(*e)--;
		return x;
	}
	
	x->rc=buildtree(pre,post,pri+1,e,n);
	x->lc=buildtree(pre,post,pri+1,e,n);
	
	(*e)--;
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
	char pre[10],post[10];
	cout<<" Size of preorder and postorder arrays : ";
	cin>>n;
	cout<<endl<<" Accepting preorder array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>pre[i];
	}
	
	cout<<endl<<" Accepting postorder array : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<" Enter ele no  "<<i+1<<" : ";
		cin>>post[i];
	}
	
	cout<<endl<<" Preorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<pre[i];
	
	cout<<endl<<" postorder array : ";
	for(i=0;i<n;i++)
		cout<<" "<<post[i];
	
	int l=n-1;	
	int e=n-1;
	node *root=new node;
	root=buildtree(pre,post,0,&e,&l);
	
	cout<<endl<<" Cross check preorder : ";
	pre_display(root);
	
	getch();
}
	