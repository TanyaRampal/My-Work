//successor in bst

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

void suc_pred(node *root)
{
	int ele;
	cout<<endl<<" ele whose successor and predecessor u want ? : ";
	cin>>ele;
	node *temp=new node;
	node *n=new node;
	
	n=search(root,ele);
	
	if(n==NULL)
	{
		cout<<"ele does not exist";
		return;
	}
	
	else if(n->lc==NULL && n->rc==NULL)	//leaf
	{
		temp=n;
		while(temp->p!=NULL)
		{
			if(temp==temp->p->rc)	//keep going left(upwards)
				temp=temp->p;
			else if(temp==temp->p->lc)	//go right once
			{
				temp=temp->p;
				break;
			}
		}
		cout<<endl<<"successor of "<<ele<<" is : "<<temp->data;
		
		temp=n;
		while(temp->p!=NULL)
		{
			if(temp==temp->p->lc)	//keep going right(upwards)
				temp=temp->p;
			else if(temp==temp->p->rc)	//go left once
			{
				temp=temp->p;
				break;
			}
		}
		cout<<endl<<"predecessor of "<<ele<<" is : "<<temp->data;
	}
	
	else	//internal node
	{
		temp=n->rc;	//go right once
		while(temp->lc!=NULL)	//then keep going left
			temp=temp->lc;
		cout<<endl<<"successor of "<<ele<<" is : "<<temp->data;
		
		temp=n->lc;	//go left once
		while(temp->rc!=NULL)	//then keep going left
			temp=temp->rc;
		cout<<endl<<"predecessor of "<<ele<<" is : "<<temp->data;
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
			<<" 3. successor & predecessor"<<endl
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
					
			case 3: suc_pred(root);
					break;
					
			case 4: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=4);
	getch();
}
		