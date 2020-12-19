// deleteing a node in bst

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
	

node *search(node *n,int ele)
{
	if(n==NULL)
		return NULL;

	while(n!=NULL)
	{
			if(n->data==ele)
				return n;
			
			else if(n->data > ele)
				n=n->lc;
			
			else if(n->data < ele)
				n=n->rc;
	}
	return NULL;
}


node *suc(node *n)	//of internal node
{
	node *temp=new node;
	temp=n->rc;	//go right once
	while(temp->lc!=NULL)	//then keep going left
		temp=temp->lc;
	return temp;
}

void del(node *&root)
{
	int ele;
	node *x=new node;
	node *y=new node;
	node *s=new node;
	node *ps=new node;
	
	cout<<endl<<" Ele u want to del? : ";
	cin>>ele;
	
	x=search(root,ele);	//x-ele to be deleted
	y=x->p;				//y-parent of x
	
	if(y==NULL)	//root
	{
		s=suc(x);	//successor
		ps=s->p;	//parent of s
		if(s->lc==NULL || s->rc==NULL)	//node with 1 child
		{
			if(s->rc!=NULL)	//s has a right child
			{
				if(ps->rc==s)
				{
					ps->rc=s->rc;
					s->rc->p=ps;
				}
				else if(ps->lc==s)
				{
					ps->lc=s->rc;
					s->rc->p=ps;
				}
			}
			
			if(s->lc!=NULL)	//s has a left child
			{
				if(ps->rc==s)
				{
					ps->rc=s->lc;
					s->lc->p=ps;
				}
				else if(ps->lc==s)
				{
					ps->lc=s->lc;
					s->lc->p=ps;
				}
			}
			
			if(s->lc==NULL && s->rc==NULL)
			{
				if(ps->rc==s)
					ps->rc=NULL;
				else if(ps->lc==s)
					ps->lc=NULL;
			}
			
			//at this point the successor has been removed from original place
		}
		
		if(x->lc!=s && x->lc!=NULL)	//giving children of x to suc
		{
			s->lc=x->lc;
			x->lc->p=s;
		}
		else if(x->lc==s ||x->lc==NULL)
			s->lc=NULL;
		
		if(x->rc!=s && x->rc!=NULL)
		{
			s->rc=x->rc;
			x->rc->p=s;
		}
		else if(x->rc==s ||x->rc==NULL)
			s->rc=NULL;
		
		s->p=NULL;
		root=s;
		cout<<endl<<" Deleted "<<x->data ;	
	}
	
	else if(x->lc==NULL && x->rc==NULL)	//leaf
	{
		if(y->rc==x)
			y->rc=NULL;
		else
			y->lc=NULL;
		cout<<endl<<" Deleted "<<x->data ;
	}		
		
	else if(x->lc==NULL || x->rc==NULL)	//node with 1 child
	{
		if(x->rc!=NULL)	//x has a right child
		{
			if(y->rc==x)
			{
				y->rc=x->rc;
				x->rc->p=y;
			}
			else
			{
				y->lc=x->rc;
				x->rc->p=y;
			}
			cout<<endl<<" Deleted "<<x->data ;
		}
		
		else if(x->lc!=NULL)	//x has a left child
		{
			if(y->rc==x)
			{
				y->rc=x->lc;
				x->lc->p=y;
			}
			else
			{
				y->lc=x->lc;
				x->lc->p=y;
			}
			cout<<endl<<" Deleted "<<x->data ;
		}
	}
	
	else	//x has 2 children 
	{
		s=suc(x);
		ps=s->p;
		if(s->lc==NULL || s->rc==NULL)	//node with 1 child
		{
			if(s->rc!=NULL)	//s has a right child
			{
				if(ps->rc==s)
				{
					ps->rc=s->rc;
					s->rc->p=ps;
				}
				else if(ps->lc==s)
				{
					ps->lc=s->rc;
					s->rc->p=ps;
				}
			}
			
			else if(s->lc!=NULL)	//s has a left child
			{
				if(ps->rc==s)
				{
					ps->rc=s->lc;
					s->lc->p=ps;
				}
				else if(ps->lc==s)
				{
					ps->lc=s->lc;
					s->lc->p=ps;
				}
			}
			
			//at this point the successor has been removed from original place
		}
		

		if(y->rc==x)	//making suc chilf of y
		{
			y->rc=s;
			s->p=y;
		}
		else
		{
			y->lc=s;
			s->p=y;
		}
		
		if(x->lc!=s)	//giving children of x to suc
		{
			s->lc=x->lc;
			x->lc->p=s;
		}
		else
			s->lc=NULL;
		
		if(x->rc!=s)
		{
			s->rc=x->rc;
			x->rc->p=s;
		}
		else
			s->rc=NULL;

		cout<<endl<<" Deleted "<<x->data ;
	}
	
	
}

void main()
{
	clrscr();
	node *root=NULL;
	node *n=new node;
	int ch,ele;
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<" bst options : "<<endl
			<<" 1. push"<<endl
			<<" 2. search"<<endl
			<<" 3. delete"<<endl
			<<" 4. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(root);
					break;
					
			case 2: cout<<endl<<" ele u wanna search? : ";
					cin>>ele;
					n=search(root,ele);
					
					cout<<endl<<" Node Data : "<<n->data<<endl
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
					break;
					
			case 3: del(root);
					break;
					
			case 4: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=4);
	getch();
}
		