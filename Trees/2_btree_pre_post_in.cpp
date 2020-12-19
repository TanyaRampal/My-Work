// Binary tree with pre-,post- and in- order traversal

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *rc,*lc;
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
	node *x=new node;
	cout<<endl<<" Enter data : ";
	cin>>x->data;
	x->rc=x->lc=x->next=NULL;
	
	if(root==NULL)
		root=x;
	
	else if(q.front->lc==NULL)
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

void post_display(node *n)
{
	if(n==NULL)
		return;

	post_display(n->lc);
	post_display(n->rc);
	
	cout<<" "<<n->data;
}

void in_display(node *n)
{
	if(n==NULL)
		return;

	in_display(n->lc);
	
	cout<<" "<<n->data;
	
	in_display(n->rc);
}

void main()
{
	clrscr();
	queue q;
	node *root=NULL;
	int ch;
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<" tree options : "<<endl
			<<" 1. push"<<endl
			<<" 2. preorder display"<<endl
			<<" 3. postorder display"<<endl
			<<" 4. inorder display"<<endl
			<<" 5. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(q,root);
					break;
					
			case 2: cout<<endl<<" Displaying the tree(preorder) : "<<endl;
					pre_display(root);
					break;
					
			case 3: cout<<endl<<" Displaying the tree(postorder) : "<<endl;
					post_display(root);
					break;
					
			case 4: cout<<endl<<" Displaying the tree(inorder) : "<<endl;
					in_display(root);
					break;
					
			case 5: cout<<"\n\n Exiting...";
					getch();
					exit(0);
			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=5);
	getch();
}
		