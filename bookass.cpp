#include<iostream>
using namespace std;

class publication
{
	public:
	string title;
	float price;
	void getdata()
	{
	
	cout<<"\n Enter  title=";
	cin>>title;

	cout<<"Enter the  price=";
	cin>>price;
	}
	public:
	void putdata()
	{
		cout<<"\ntile"<<title;
		cout<<"\nprice"<<price;
	}
	
};
class book:public publication
{
	int pages;
	public:
	void getdata()
	{
	
	try{
	
	
	publication::getdata();
	cout<<"\nEnter the pages=";
	cin>>pages;
	if(pages<=0)
	throw pages;
  }
catch(...)
{
  cout<<"\n Invalid pages count!!   try again";
  pages=0;	
}	
}
	public:
	void putdata()
	{
		publication::putdata();
		cout<<"\npages"<<pages;
		
	}
	
};
class tape:public publication
{
	float min;
	public:
	void getdata()
	{
		try{
		
		publication::getdata();
		cout<<"\nEnter minuters";
		cin>>min;
		if(min<=0)
		throw min;
	}
	catch(...)
	{ 
	  cout<<"\n Invlid Minute";
	  min=0;
	}
}
	//public:
	void putdata()
	{
		publication::putdata();
		cout<<"\ntime="<<min;
	}
};
int main()
{
	book b[30];
	tape t[30];
	int n,i;
	char ch;
	
	do{
		cout<<"\n Enter the number of book and tape:";
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			cout<<"\n Book and tape detials=";
			b[i].getdata();
			t[i].getdata();
		}
		for(i=0;i<n;i++)
		{
			cout<<"\n Disply Book and tape detials=";
			b[i].putdata();
			t[i].putdata();
		}
	cout<<"\n Do you want to continue(y/n)";
	cin>>ch;
	}while(ch=='y');
	return 0;
}
