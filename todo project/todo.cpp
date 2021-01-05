#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdio>


using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);
int year=1900 + ltm->tm_year;
int month=1 + ltm->tm_mon;
int day=ltm->tm_mday;
string date=to_string(year)+"-"+to_string(month)+"-"+to_string(day);
//string date=to_string(day)+"-"+to_string(month)+"-"+to_string(year);


/*************** ADD TODO ITEM *************/

void add_todo(string s2)
{
	string line;
	ifstream file1("todo.txt");
	ofstream file2("temp.txt");
	file2<<s2<<"\n";
	while(getline(file1, line))
		file2<<line<<"\n";
	file1.close();
	file2.close();
	
	ofstream file3("todo.txt");
	ifstream file4("temp.txt");
	while(getline(file4, line))
		file3<<line<<"\n";
	
	file3.close();	
	remove("temp.txt");	

	cout<<"Added todo: \""<<s2<<"\""<<endl;
}





/*************** DISPLAY FILE *************/

void display()
{
	int i=0;
	ifstream file("todo.txt");
	string line;
	
	while(getline(file, line))
		i++;
	file.clear();
	file.seekg(0);
	
	if(i==0)
	{
		cout<<"There are no pending todos!"<<endl;
		return;
	}
	
	while(getline(file, line))
	{
		cout<<"["<<i<<"] "<<line<<endl;
		i--;
	}
	file.close();
}






/*************** DELETE TODO ITEM *************/

void delete_todo(int n)
{
	int size=0;
	string line;
	ifstream file1("todo.txt");
	ofstream file2("temp.txt");
	
	while(getline(file1, line))
		size++;
	file1.clear();
	file1.seekg(0);
	
	if(n>size || n<1)
	{
		cout<<"Error: todo #"<<n<<" does not exist. Nothing deleted."<<endl;
		return;
	}
	
	for(int i=size;i>=1;i--)
	{
		getline(file1, line);
		if(i!=n)
			file2<<line<<"\n";
	}
	
	file1.close();	
	file2.close();
	
	ofstream file3("todo.txt");
	ifstream file4("temp.txt");
	while(getline(file4, line))
		file3<<line<<"\n";
	
	file3.close();	
	remove("temp.txt");
	cout<<"Deleted todo #"<<n<<endl;
}





/*************** MOVE ITEM FROM TODO.TXT TO DONE.TXT *************/

void done(int n)
{
	int size=0;
	string line;
	ifstream file1("todo.txt");
	ofstream file2("done.txt",file2.app);
	
	while(getline(file1, line))
		size++;
	file1.clear();
	file1.seekg(0);
	
	if(n>size || n<1)
	{
		cout<<"Error: todo #"<<n<<" does not exist."<<endl;
		return;
	}
	
	string s="x "+date+" ";
	
	for(int i=size;i>=1;i--)
	{
		getline(file1, line);
		if(i==n)
			file2<<s<<line<<"\n";
	}
	
	file1.close();	
	file2.close();
	
	delete_todo(n);
	cout<<"Marked todo #"<<n<<" as done."<<endl;
}




/*************** MAIN FUNCTION *************/

int main(int argc, char* argv[])
{
	string s1,s2,line;
	if(argv[1])
		s1=(string)argv[1];
    if((!argv[1]) || (s1=="help"))
	{
		cout << "Usage :-"<<endl
			 << "$ ./todo add \"todo item\""<<setw(18)<<"# Add a new todo"<<endl
			 << "$ ./todo ls"<<setw(37)<<"# Show remaining todos"<<endl
			 << "$ ./todo del NUMBER"<<setw(22)<<"# Delete a todo"<<endl
			 << "$ ./todo done NUMBER"<<setw(23)<<"# Complete a todo"<<endl
			 << "$ ./todo help"<<setw(25)<<"# Show usage"<<endl
			 << "$ ./todo report"<<setw(23)<<"# Statistics"<<endl;
		
	}
	
	
	//add an item
	else if(s1=="add")
	{
		if(!argv[2])
			cout<<"Error: Missing todo string. Nothing added!"<<endl;
			
		else
		{
			s2=(string)argv[2];
			add_todo(s2);	
		}			
	}
	
	//list items in todo.txt
	else if(s1=="ls")
		display();
	
	//delete item in todo.txt
	else if(s1=="del")
	{
		if(!argv[2])
			cout<<"Error: Missing NUMBER for deleting todo."<<endl;
			
		else
		{
			int n=atoi(argv[2]);
			delete_todo(n);	
		}			
	}
	
	//move item from todo.txt to done.txt
	else if(s1=="done")
	{
		if(!argv[2])
			cout<<"Error: Missing NUMBER for marking todo as done."<<endl;
			
		else
		{
			int n=atoi(argv[2]);
			done(n);
		}
	}
	
	//give report
	else if(s1=="report")
	{
		int pending=0,completed=0;
		ifstream file1("todo.txt");
		ifstream file2("done.txt");
		
		while(getline(file1, line))
			pending++;
		while(getline(file2, line))
			completed++;
		
		cout<<date<<" Pending : "<<pending<<" Completed : "<<completed<<endl;
	}
	
    return 0;
}
