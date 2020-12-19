//quicksort

#include<iostream.h>
#include<conio.h>
   

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

int part(int a[], int p, int r)  //partitioning the array
{  
    int x = a[r]; //pivot  
	cout<<endl<<x;
	cout<<endl;
	for(int k=p;k<=r;k++)
		cout<<a[k]<<" ";
    int i = (p - 1); // Index of smaller element  
  
    for (int j = p;j <= r - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < x)  
        {  
            i++; // increment index of smaller element  
            swap(&a[i], &a[j]);  
        }  
    }  
    swap(&a[i + 1], &a[r]);  
	cout<<endl;
	for(k=p;k<=r;k++)
		cout<<a[k]<<" ";
    return (i + 1);  
} 


void qsort(int a[20],int p,int r) 
{
	if(p<r)
	{
		int q=part(a,p,r);
		qsort(a,p,q);
		qsort(a,q,r);		
	}
}


void main()
{
	clrscr();
	int a[20],n;
	cout<<" Sorting array using quick sort";
	cout<<endl<<" Enter size of array  : ";
	cin>>n;
	
	cout<<endl<<" Accepting array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Enter ele no. "<<i+1<<" : ";
		cin>>a[i];
	}
	
	cout<<endl<<" Unsorted array : ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	qsort(a,0,n-1);
	
	cout<<endl<<" Sorted array : ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" "; 
	
	getch();	
}