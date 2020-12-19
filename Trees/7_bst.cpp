// BST-binary search tree

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *rc,*lc,*p;
};

void ins(node *&root)
{
	
	node *x=new node;
	node *temp=new node;
	cout<<endl<<" Enter data : ";
	cin>>x->data;
	x->rc=x->lc=NULL;
	
	if(root==NULL)
	{
		x->p=NULL;
		root=x;
	}
	
	else
	{
		temp=root;
		while(temp->lc!=NULL || temp->rc!=NULL)
		{
			if(x->data==temp->data)
			{
				cout<<" element already in tree ";
				return;
			}
			else if(x->data < temp->data)	//ie it has to be put in left 
			{
				if(temp->lc==NULL)
					break;
				temp=temp->lc;
			}
			else if(x->data > temp->data)	//ie it has to be put in right
			{
				if(temp->rc==NULL)
					break;
				temp=temp->rc;
			}
		}
		
		x->h=1;
		if(x->data < temp->data)
		{
			temp->lc=x;
			x->p=temp;			
		}
		else if(x->data > temp->data)
		{
			temp->rc=x;
			x->p=temp;
		}
	}		
}
	
void pre_display(node *n)
{
	if(n==NULL)
		return;
	cout<<" "<<n->data;		
	
	pre_display(n->lc);
	pre_display(n->rc);
}

void search(node *root,node *n,int ele)
{
	if(n==NULL)
		return;

	while(n!=NULL)
	{
			if(n->data==ele)
			{	
				cout<<endl<<" Node Data : "<<n->data<<endl
						  <<" Node height : "<<n->h<<endl
						  <<" Node parent : ";
				if(n->p==NULL)
					cout<<"none(root)"<<endl;
				else if(n->p==root)
						cout<<n->p->data<<"(root)"<<endl;
				else 
					cout<<n->p->data<<endl;
						  
				cout<<" Node lc : ";
				if(n->lc==NULL)
					cout<<" no left child.";
				else 
					cout<<n->lc->data;
				
				cout<<endl<<" Node rc : ";
				if(n->rc==NULL)
					cout<<" no right child.";
				else 
					cout<<n->rc->data;
				return;
			}
			else if(n->data > ele)
				n=n->lc;
			
			else if(n->data < ele)
				n=n->rc;
	}
}

void main()
{
	clrscr();
	node *root=NULL;
	int ch,ele;
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<" bst options : "<<endl
			<<" 1. push"<<endl
			<<" 2. preorder display"<<endl
			<<" 3. search"<<endl
			<<" 4. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(root);
					break;
					
			case 2: cout<<endl<<" Displaying the tree(preorder) : "<<endl;
					pre_display(root);
					break;
					
			case 3: cout<<endl<<" ele u wanna search? : ";
					cin>>ele;
					search(root,root,ele);
					break;
					
			case 4: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=4);
	getch();
}
		