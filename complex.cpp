#include<iostream>
using namespace std;
class complex
{
	float x;
	float y;
	public:
		complex()
		{
		 x=0;
		 y=0;	
		}
		
		complex operator+(complex &);
		complex operator*(complex &);
		friend istream &operator>>(istream &, complex &);
		friend ostream &operator<<(ostream &, complex &);
};
istream &operator>>(istream & in,complex &t)
{
	cout<<"\n Enter the Real part=";in>>t.x;
	cout<<"\n Enter the imaginary part=",in>>t.y;
	return in;
}
ostream &operator<<(ostream &out, complex &t)
{
	out<<t.x<<"+"<<t.y<<"i";
	return out;
}
complex complex::operator+(complex &c)
{
	complex add;
	add.x=x+c.x;
	add.y=y+c.y;
	return add;
}
complex complex::operator*(complex &c)
{
	complex mul;
	mul.x=(x*c.x)-(y*c.y);
	mul.y=(y*c.y)+(x*c.y);
	return mul;
}
int main()
{
	complex c1,c2,c3,c4;
	cout<<"\n Default Constructor:";
	cout<<c1;
	cout<<"\nEnter first complex number";
	cin>>c1;
	cout<<"\n Enter second complex number:";
	cin>>c2;
	c3=c1+c2;
	c4=c1*c2;
	cout<<"\n First Complex number="<<c1;
	cout<<"\n Second Complex number="<<c2;
	cout<<"\nAddition of two complex number="<<c3;
	cout<<"\nMultiplication of two complex number="<<c4;
	return 0;	
}

