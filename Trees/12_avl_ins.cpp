//AVL tree- only ins

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data,h;	//data=key, h=height
	node *rc,*lc,*p;
};


//function for rotation
void rotate(node *&z)	//z-height unbalanced
{
	node *temp=new node;
	node *y=new node;
	if(z->rc->h > z->lc->h)			//if right childs height is more
	{
		y=z->rc;
		temp=y->lc;
		y->lc=z;
		z->rc=temp;
		
		if(temp!=NULL)
			temp->p=z;
		y->p=z->p;
		if(z->p->lc==z)
			z->p->lc=y;
		else
			z->p->rc=y;
		z->p=y;
	}
	
	else if(z->rc->h < z->lc->h)		//if left childs height is more
	{
		y=z->lc;
		temp=y->rc;
		y->rc=z;
		z->lc=temp;
		
		if(temp!=NULL)
			temp->p=z;
		y->p=z->p;
		if(z->p->lc==z)
			z->p->lc=y;
		else
			z->p->rc=y;
		z->p=y;
	}
}


//function for insertion in avl tree(contains ins of bst)
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
		x->h=1;
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
			else if(x->data < temp->data)
			{
				if(temp->lc==NULL)
					break;
				temp=temp->lc;
			}
			else if(x->data > temp->data)
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
		
		//till here we did bst insertion, now chceking whether rotation is reqd
		temp=x->p;
		
		while(temp!=NULL)
		{
			if(temp->rc==NULL)
				temp->h=temp->lc->h+1;
			else if(temp->lc==NULL)
				temp->h=temp->rc->h+1;
			else if(temp->lc->h==temp->rc->h)
				temp->h=temp->lc->h+1;
			
			else if(temp->lc->h==temp->rc->h+1)
				temp->h=temp->lc->h+1;
			else if(temp->rc->h==temp->lc->h+1)
				temp->h=temp->rc->h+1;
			
			else if(temp->lc->h==temp->rc->h+2 || temp->rc->h==temp->lc->h+2)		//temp-node with height unbalanced
			{
				if(temp->lc->lc==x->p || temp->rc->rc==x->p)
				{
					rotate(temp);			//rotate(y,z)
					continue;
				}
				
				else
				{
					if(temp->rc->lc==x->p)
					{
						rotate(temp->rc);	//rotate(x,y)
						temp->rc->rc->h--;
						rotate(temp);		//rotate(x,z)
					}
					else if(temp->lc->rc==x->p)
					{
						rotate(temp->lc);
						temp->lc->lc->h--;
						rotate(temp);
					}
					continue;
				}
			}	
			
			temp=temp->p;
		}
	}		
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
			<<" AVL options : "<<endl
			<<" 1. push"<<endl
			<<" 2. search"<<endl
			<<" 3. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(root);
					break;
					
			case 2: cout<<endl<<" ele u wanna search? : ";
					cin>>ele;
					search(root,root,ele);
					break;
					
			case 3: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=3);
	getch();
}
		