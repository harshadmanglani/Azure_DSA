#include <iostream>
using namespace std;

int DivZero(int a, int b, int c)
{
	if (a == 0 && b == 0 &&  c == 0)
		throw 2;
	else if (a < 0 && b < 0 &&  c < 0)
		throw 1;

	return a + b * c + b / c;
}

int main()
{
	int a, b, c;
	cout<<"enter three numbers: ";
	cin>>a>>b>>c;
	try{
	cout<<"result: "<<DivZero(a,b,c)<<endl;
	}
	catch(int i)
	{
		switch(i)
		{
			case 1: cout<<"All three numbers < 0"<<endl;
				break;
			case 2: cout<<"All three numbers = 0"<<endl;
				break;
		}
	}
	return 0;
}

