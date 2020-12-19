//heap sort

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
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

void delmin(int a[20],int &i,int b[20],int &j)
{
	b[j]=a[1];
	j++;
	swap(a[1],a[i]);
	a[i]=0;
	i--;

	heapify2(a,1);
}

void hsort(int a[20],int n,int b[20],int &n2)		//n=size(last index)=i
{
	int x=n;
	for(int j=1;j<=n;j++)
		delmin(a,x,b,n2);
}

void main()
{
	clrscr();
	int i,n1,n2,a[20],b[20];
	for(i=0;i<=20;i++)
		a[i]=0;

	cout<<endl<<"HEAP SORT "<<endl;
	cout<<" Enter size : ";
	cin>>n1;
	
	cout<<endl<<" Accepting array : "<<endl;
	for(i=1;i<=n1;i++)
	{
		cout<<" Enter ele "<<i<<" : ";
		cin>>a[i];
	}
	
	cout<<endl<<" Unsorted array : "<<endl;
	for(i=1;i<=n1;i++)
		cout<<" "<<a[i];
	
	for(i=n1/2;i>=1;i--)
		heapify2(a,i);
	
	cout<<endl<<" heap array : "<<endl;
	for(i=1;i<=n1;i++)
		cout<<" "<<a[i];
	
	n2=1;	
	hsort(a,n1,b,n2);
	
	cout<<endl<<" Sorted array : "<<endl;
	for(i=1;i<n2;i++)
		cout<<" "<<b[i];
	
	getch();
}