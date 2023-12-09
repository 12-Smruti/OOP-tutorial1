#include<iostream>
using namespace std;
#define max 100;
#include<string.h>

class perinfo
{
	string lic,dob,blood;
	public:
		perinfo();
		perinfo(perinfo &);
		~perinfo()
		{
		cout<<"\n Destructor called!!!"<<endl<<"RECORD DELETED SUCESSFULLY"<<endl;
		}
		friend class student;
};
class student
{
	string name,add,year;
	char div;
	int mob,roll;
	static int cnt;
	public:
		void create(perinfo &);
		void display(perinfo &);
		
		inline static void inccnt()
		{ 
			cnt++;
		}
		inline static void showcnt()
		{
			cout<<"\n Total number of records are:";
		}
		student();
		student(student &);
		~student()
		{
			cout<<"\n Destructor is called"<<endl<<"Record delelted successfully";
		}
};

int student::cnt;
student::student()
{
	name="Smruti Parkale";
	add="Karjat";
	year="SE com";
	div='A';
	roll=82;
	mob=7385123;
}
perinfo::perinfo()
{
	lic="ABVRW3456";
	dob="17/02/2004";
	blood="o+";
}
student::student(student &obj)
{
	this->name=obj.name;
	this->add=obj.add;
	this->year=obj.year;
	this->div=obj.div;
	this->roll=obj.roll;
	this->mob=obj.mob;
}
perinfo::perinfo(perinfo &obj)
{
	lic=obj.lic;
	dob=obj.dob;
	blood=obj.blood;
}
void student::create(perinfo &obj)
{
	cout<<"\n Name:";
	cin>>name;
	cout<<"\n Address:";
	cin>>add;
	cout<<"\n Date Of Birth:";
	cin>>obj.dob;
	cout<<"\n Year";
	cin>>year;
	
	cout<<"\n Division:";
	cin>>div;
	cout<<"\n Roll no:";
	cin>>roll;
	cout<<"\n Blood Group:";
	cin>>obj.blood;
	cout<<"\n Liceince Number:";
	cin>>obj.lic;
	cout<<"\n Moblie num:";
	cin>>mob;
}

void student::display(perinfo &obj)
{
	cout<<"\n**************** STUDENT DATABASE****************";
	cout<<"\nName of Student: "<<name;
	cout<<"\nAddress of Student: "<<add;	
	cout<<"\nDOB of Student: "<<obj.dob;
	cout<<"\nYear of Student: "<<year;
	cout<<"\nDivision of Student: "<<div;
	cout<<"\nRoll no of Student: "<<roll;
	cout<<"\nBlood Group of Student: "<<obj.blood;
	cout<<"\nLiceince of Student: "<<obj.lic;
	cout<<"\nMoblie of Student: "<<mob;
	cout<<"\n**************************************************";
}
int main()
{
	int n;
	int ch;
	char ans;
	
	cout<<"\nEnter no of Students";
	cin>>n;
	cout<<"\n****************************";
	student *sobj=new student[n];
	perinfo *pobj=new perinfo[n];
	
	do{
		cout<<"MENU 1:Create Database \n    2:Display Database \n  3:copy constructor \n     4:Default Constructor   \n 5:Delete (Destructor)";
		cout<<"\n Enter your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				for(int i=0;i<n;i++)
				{
					sobj[i].create(pobj[i]);
					sobj[i].inccnt();
				}
		}
		break;
			case 2:
			{
				sobj[0].showcnt();
				for(int i=0;i<n;i++)
				{
					sobj[i].display(pobj[i]);
				}
			}
		break;
			case 3:
			{
				student obj1;
				perinfo obj2;
				obj1.create(obj2);
				student obj3(obj1);
				perinfo obj4(obj2);
				cout<<"\n Copy Constructor is called";
			}
		break;
			case 4:
				{
					student obj1;
					perinfo obj2;
					cout<<"\n Default constructor is called";
					obj1.display(obj2);
				}
		break;
			case 5:
				delete [] sobj;
				delete [] pobj;
			
		}
		cout<<"\n Want to Continue:(y/n)";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
