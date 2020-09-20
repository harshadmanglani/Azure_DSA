#include<iostream>
using namespace std;

int ackermann(int m, int n)
{
	if(m == 0)
		return n+1;

	else if(n == 0)
		return ackermann(m-1, 1);

	else
		return ackermann(m-1, ackermann(m, n-1));
}

int main()
{
	int a = 0;
	int b = 0;
	for(int i = 2; i < 100; i++)
	cout<<"Ackermann's function for "<<a+(i-2)<<", "<<b+(i-1)<<": "<<ackermann(a+(i-2), b+(i-1))<<endl;
	return 0;
}
