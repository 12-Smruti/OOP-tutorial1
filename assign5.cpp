#include<iostream>
#define size 10
using namespace std;

template<class T>
void sel(T A[size])
{
	
	int i,j ,min,n;
	T temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
		if(A[i]<A[min])
		{
			min=j;
		}
	}	
	temp=A[i];
	A[i]=A[min];
	A[min]=temp;
}
   cout<<"\n sorted array:";
   for(i=0;i<n;i++)
   {
   	cout<<" "<<A[i];
   }
}
int main()
{
	int A[size];
	float B[size];
	int n,i;
	
	cout<<"\n Enter the total number of ele:";
	cin>>n;
	cout<<"\n Enter int ele=";
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sel(A);
	cout<<"\Enter the total num:";
	cin>>n;
	cout<<"\n Enter float el=";
	for(i=0;i<n;i++)
	{
		cin>>B[i];
	}
	sel(B);
	return 0;
}

