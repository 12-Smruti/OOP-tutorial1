#include<iostream>
#include<fstream>
using namespace std;
class employee
{
	string name;
	int id;
	float sal;
	
	public:
		void getdata()
		{
			cout<<"\n Enter the name of employee=";
			cin>>name;
			cout<<"\n Enter the id=";
			cin>>id;
			cout<<"\n Enter the salary";
			cin>>sal;
		}
		void putdata()
		{
			cout<<"\n Name:"<<name;
			cout<<"\n ID:"<<id;
			cout<<"\n Salary:"<<sal;
		}
};
int main()
{
	employee e[5];
	int i,n;
	fstream f;
	cout<<"\n Enter how many employee you want:";
	cin>>n;
	f.open("hi.txt",ios::app);
	
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter the informnation:";
		e[i].getdata();
		f.write((char*)&e[i], sizeof(e[i]));
	}
	f.close();
	f.open("hi.txt");
		for(i=0;i<n;i++)
	{
		f.read((char*)&e[i], sizeof(e[i]));
		e[i].putdata();
	}
	f.close();
	return 0;
	
}
