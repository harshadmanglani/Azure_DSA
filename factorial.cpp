#include<iostream>
using namespace std;

int recursive_factorial(int n)
{
	if(n==1)
	return 1;
	else
	return n*recursive_factorial(n-1);
}

int iter_factorial(int n)
{
	int f = 1;
	while(n>0)
	{
		f = f*n;
		n--;
	}
	return f;
}

int main()
{
	int a = 5;
	cout<<"The recursive factorial for 5 is: "<<recursive_factorial(a)<<endl;
	cout<<"======\n";
	cout<<"The iterative factorial for 5 is: "<<iter_factorial(a)<<endl;
	return 0;
}
