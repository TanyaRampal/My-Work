//avoiding collisons using chaining in hash table(using ll)

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

class hash
{
	node *a[20];		//acts as an array of heads
	
	public:
	
	int m;
	hash();
	int hf(int x);
	void ins();
	void del();
	void display();
	void search();
};

hash::hash()
{
	for(int i=0;i<10;i++)
		a[i]=NULL;
}
	
int hash::hf(int x)
{
	int y=x%m;
	return y;
}

void hash::ins()
{
	node *x=new node;
	node *temp=new node;
	cout<<endl<<" enter the data : ";
	cin>>x->data;
	x->next=NULL;
	int i=hf(x->data);
	
	if(a[i]==NULL)
		a[i]=x;
	else
	{
		temp=a[i];
		while(temp->next!=NULL)
		{
			if(temp->data==x->data)
			{
				cout<<endl<<" "<<x->data<<" already exists in table ";
				return;
			}
			temp=temp->next;
		}
		if(temp->data==x->data)
			{
				cout<<endl<<" "<<x->data<<" already exists in table ";
				return;
			}
		temp->next=x;
	}
}

void hash::del()
{
	int x;
	node *temp1=new node;
	node *temp2=new node;
	cout<<endl<<" which ele do u wanna del? ";
	cin>>x;
	int i=hf(x);
	
	if(a[i]->data==x)
		a[i]=a[i]->next;
	
	else
	{	
		temp1=a[i];
		while(temp1->next!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
			
			if(temp1->data==x)
			{
				temp2->next=temp1->next;
				cout<<endl<<" "<<x<<" deleted.";
				return;
			}
		}
		
		cout<<endl<<" "<<x<<" does not belong to the hash table ";
	}
}

void hash::display()
{
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		node *temp=new node;
		cout<<" "<<i;
		temp=a[i];
		while(temp!=NULL)
		{
			cout<<"-->"<<temp->data;
			temp=temp->next;
		}		
		cout<<endl;
	}
}

void hash::search()
{
	int ctr,x;
	node *temp=new node;
	cout<<endl<<" enter the ele u wanna search : ";
	cin>>x;
	int i=hf(x);
	
		temp=a[i];
		while(temp!=NULL)
		{	
			ctr++;
			if(temp->data==x)
			{
				cout<<endl<<" "<<x<<" found at slot "<<i<<" at pos "<<ctr;
				return;
			}
			temp=temp->next;
		}
		cout<<endl<<" "<<x<<" does not belong to the hash table ";
}
	
void main()
{
	clrscr();
	hash h;
	int ch;
	
	cout<<" enter no. of slots : ";
	cin>>h.m;
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<"hash  options : "<<endl
			<<" 1. ins"<<endl
			<<" 2. del"<<endl
			<<" 3. display"<<endl
			<<" 4. search"<<endl
			<<" 5. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1: h.ins();
				break;
		case 2: h.del();
				break;
		case 3: h.display();
				break;
		case 4: h.search();
				break;
		case 5: cout<<"\n\n Exiting...";
				getch();
				exit(0);
		default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=5);
	getch();
}

		
			
		
		
	
	
	