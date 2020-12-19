//avoiding collisons using linear probing in hash table(using arrays)

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


class hash
{
	int a[20];		
	
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
	for(int i=0;i<=10;i++)
		a[i]=0;
}
	
int hash::hf(int x)
{
	int y=x%m;
	return y;
}

void hash::ins()
{
	int p,x;	//p=probe
	cout<<endl<<" enter the data : ";
	cin>>x;
	p=hf(x);
	
	while(a[p]!=0 && a[p]!=x && a[p]!=100)		// 100 is the tombstone marker
		p=(p+1)%m;
	
	if(a[p]==x)
	{
		cout<<" "<<x<<" already exists in table";
		return;
	}
	else
		a[p]=x;
}

void hash::del()
{
	int x,p;
	cout<<endl<<" which ele do u wanna del? ";
	cin>>x;
	p=hf(x);
	
	while(a[p]!=0 && a[p]!=x)		
		p=(p+1)%m;		//offset=1
	
	if(a[p]==x)
	{
		a[p]=100;
		cout<<endl<<" "<<x<<" deleted ";
		return;
	}
		
	cout<<endl<<" "<<x<<" does not belong to the hash table ";
}

void hash::display()
{

	for(int i=0;i<m;i++)
	{
		cout<<endl;
		cout<<" "<<i;
		if(a[i]==100 || a[i]==0)
			continue;
		
		cout<<" -->"<<a[i];
	}
}

void hash::search()
{
	int x;
	cout<<endl<<" enter the ele u wanna search : ";
	cin>>x;
	int p=hf(x);
	
	while(a[p]!=0 && a[p]!=x)		
		p=(p+1)%m;
	
	if(a[p]==x)
	{
		cout<<endl<<" "<<x<<" found at pos "<<p;
		return;
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

		
			
		
		
	
	
	