//binary search tree

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data,l;
	node *rc,*lc,*p;
	node *next;
};


class queue
{
	public:
	node *front, *rear;
	queue()
	{
		front=rear=NULL;
	}
	void push(node *x);
	void pop();
};

void queue::push(node *x)
{
	if(front==NULL)
		front=rear=x;
	else
	{
		rear->next=x;
		rear=x;
	}
}

void queue::pop()
{
	front=front->next;
}



void ins(queue &q,node *&root)
{
	int a;
	node *x=new node;
	
	if(root!=NULL && q.front!=q.rear)
	{	
		cout<<endl<<" Do you wish to enter data or null for ";
		if(q.front->lc==NULL && q.front->l==0)
			cout<<"left child of "<<q.front->data<<"? (1/0) :  ";
		else
			cout<<"right child of "<<q.front->data<<"? (1/0) : ";
		
		cin>>a;
		if(a==0)
		{
			if(q.front->l==0 && q.front->lc==NULL)
			{
				cout<<<<" no left child of "<<q.front->data;
				q.front->l=1;
			}
			else 
			{	
				cout<<" no right child of "<<q.front->data;
				q.front=q.front->next;
			}
			return;
		}		
	}		
		

	
	cout<<endl<<" Enter data for ";
	if(root==NULL)
		cout<<"root : ";
	else if(q.front->lc==NULL && q.front->l==0)
		cout<<"left child of "<<q.front->data<<" : ";
	else
		cout<<"right child of "<<q.front->data<<" : ";
	
	cin>>x->data;
	x->rc=x->lc=x->next=NULL;
	x->l=0;
	x->p=q.front;
	
	if(root==NULL)
	{	
		x->p=NULL;
		root=x;
	}
	
	else if(q.front->lc==NULL && q.front->l==0)
		q.front->lc=x;
		
	else if(q.front->rc==NULL)
	{
		q.front->rc=x;
		q.pop();
	}
	
	q.push(x);
}
	
void pre_display(node *n)
{
	if(n==NULL)
		return;
	cout<<" "<<n->data;		
	
	pre_display(n->lc);
	pre_display(n->rc);
}



void search(node *n,int ele)
{
	if(n==NULL)
		return;
	
		if(n->data==ele)
		{
			cout<<endl<<" Node Data : "<<n->data<<endl
					  <<" Node parent : ";
			if(n->p==NULL)
				cout<<"none(root)"<<endl;
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
			
		}
	search(n->lc,ele);
	search(n->rc,ele);
}

void main()
{
	clrscr();
	queue q;
	node *root=NULL;
	int ch,ele;
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<" tree options : "<<endl
			<<" 1. push"<<endl
			<<" 2. preorder display"<<endl
			<<" 3. search : "<<endl
			<<" 4. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(q,root);
					break;
					
			case 2: cout<<endl<<" Displaying the tree(preorder) : "<<endl;
					pre_display(root);
					break;
					
			case 3: cout<<endl<<" ele u wanna search? : ";
					cin>>ele;
					search(root,ele);
					break;
					
			case 4: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=4);
	getch();
}
		