// heap insertion and eletion of minimum ele

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void heapify1(int a[20],int i)		//heapify1 for INSERTION i-index of last ele(initially)
{
	int p=i/2;
	if(a[p]>0)
	{	
		if(a[i]<a[p])
		{
			swap(a[i],a[p]);			
			heapify1(a,p);
		}
	}	
}

void ins(int a[20],int &i)
{
	cout<<endl<<" Enter the new ele : ";
	cin>>a[i];
	i++;
	
	heapify1(a,i-1);
}

void heapify2(int a[20],int i)		//heapify2 for DELETION, i=1 (intially)
{
	int j,l,r;
	int temp;
	l=2*i;
	r=2*i+1;
	
	if(a[l]>a[i] && a[r]>a[i])	//both satisfy heap prop ie both children are larger that p
		return;
	
	else if((a[l]<a[i] && a[r]<a[i]) && (a[l]!=0 && a[r]!=0))	//both children are smaller than p
	{
		if(a[l]<a[r])
		{
			j=l;
			swap(a[l],a[i]);
			heapify2(a,j);
		}
		
		else 
		{
			j=r;
			swap(a[r],a[i]);
			heapify2(a,j);
		}
	}
		
	else if(a[l]<a[i] && a[l]!=0)	//if only left child is smaller
	{
		j=l;
		swap(a[l],a[i]);
		heapify2(a,j);
	} 
	
	else if(a[r]<a[i] && a[r]!=0)	//if only right child is smaller
	{
		j=r;
		swap(a[r],a[i]);
		heapify2(a,j);
	}
}

void delmin(int a[20],int &i)
{
	cout<<endl<<" Deleted "<<a[1];
	a[1]=a[i-1];
	a[i-1]=0;
	i--;
	
	heapify2(a,1);
}

void search(int a[20],int i)		//i-size of array(1+index of last ele)
{
	int ele;
	
	cout<<endl<<" Enter ele to be searched : ";
	cin>>ele;
	
	for(int j=1;j<i;j++)
	{
		if(a[j]==ele)
		{
			cout<<endl<<" Node data : "<<a[j];
			if(j==1)
				cout<<"(root)";
			
			cout<<endl<<" Node parent : "<<a[j/2];
				if(a[j/2]==0 || a[j/2]==a[1])
					cout<<"(root)";
				
			cout<<endl<<" Node lc: "<<a[2*j]
				<<endl<<" Node rc "<<a[(2*j)+1];
			return;
		}
	}
}

void display(int a[20], int i)
{
	cout<<endl<<" Displaying the heap : "<<endl;
	for(int j=1;j<i;j++)
		cout<<a[j]<<" ";
}

void main()
{
	clrscr();
	int a[20],ch,ele;
	int i;
	
	for(int j=0;j<=20;j++)
		a[j]=0;
	
	i=1;
	
	do
	{
		cout<<"\n\n **MAIN MENU**"<<endl
			<<" Heap options : "<<endl
			<<" 1. push"<<endl
			<<" 2. display"<<endl
			<<" 3. search"<<endl
			<<" 4. delete min "<<endl
			<<" 5. Exit"<<endl
			<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	ins(a,i);	//array index starts fro 1
					break;
					
			case 2: display(a,i);
					break;
					
			case 3: search(a,i);
					break;
					
			case 4: delmin(a,i);
					break;
					
			case 5: cout<<"\n\n Exiting...";
					getch();
					exit(0);

			default : cout<<"\n Invalid choice! ";
		}
	}while(ch!=5);
	getch();
}