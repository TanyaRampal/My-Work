//arbritary tree

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *p;	//parent address
	node *lc,*s;	//s for next sibling and lc for child
	node *next;		//FOR QUEUE ONLY
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
	int n;
	node *x=new node;
	node *temp=new node;
	
	if(root==NULL)
	{
		cout<<endl<<" Enter data : ";
		cin>>x->data;
		x->lc=x->p=x->s=NULL;
			
		root=x;
		q.push(x);
	}
	
	else if(q.front->lc==NULL)
	{
		cout<<endl<<" how many children of "<<q.front->data<<" do u want ? ";
		cin>>n;
		
		if(n==0)
			q.pop();
		
		else
		{
			cout<<endl;
			for(int i=0;i<n;i++)
			{
				node *x=new node;				
				cout<<" Enter data for child no. " <<i+1<<" : ";
				cin>>x->data;
				x->lc=x->s=NULL;
				x->p=q.front;
				
				q.push(x);
				
				if(q.front->lc==NULL)
				{
					q.front->lc=x;
					temp=q.front->lc;
				}					
				
				else
				{
					temp->s=x;
					temp=x;
				}
				
			}
			
			q.pop();
		}
	}
}
	
void display(node *n)
{
	if(n==NULL)
		return;
	cout<<" "<<n->data;		
	
	display(n->lc);
	display(n->s);
}

void search(node *n,int ele)
{
	if(n==NULL)
		return;
	
		if(n->data==ele)
		{
			node *temp=new node;
			cout<<endl<<" Node Data : "<<n->data<<endl;
					  <<" Node parent : ";
			if(n->p==NULL)
				cout<<"none(root)"<<endl;
			else
				cout<<n->p->data<<endl;
					  
			cout<<" Node children : ";
			temp=n->lc;
			if(temp==NULL)
				cout<<" none";
			else
			{
				while(temp!=NULL)
				{
					cout<<temp->data<<", ";
					temp=temp->s;
				}
			}
			
		}
	
	
	search(n->lc,ele);
	search(n->s,ele);
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
			<<" 2. display"<<endl
			<<" 3. search "<<endl
			<<" 4. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ins(q,root);
					break;
					
			case 2: cout<<endl<<" Displaying the tree(preorder) : "<<endl;
					display(root);
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
		