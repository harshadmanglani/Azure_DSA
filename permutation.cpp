#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

void inbuilt_generator(char *a, int m)
{
	do{
		copy(a, a+m+1, ostream_iterator<char>(cout, " "));
		cout<<endl;
	}while(next_permutation(a, a+m+1));
}

void swap(char *a, char *b);

void generator(string a, int l, int r)
{
//	cout<<"function call"<<endl;
	if(l==r)
		cout<<a<<endl;
	else
	{
		for(int i = l; i <= r; i++)
		{
		//	cout<<"i: "<<i<<" l: "<<l<<" str: "<<a<<endl;
			swap(a[l], a[i]);
			generator(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}

void swap(char *a, char *b)
{
//	cout<<"a: "<<*a<<" b: "<<*b<<endl;
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	string str;
	cout<<"Enter the string for which you want to generate permutations: ";
	cin>>str;
	cout<<endl<<"Generating permutations..\n==============\n";
	generator(str, 0, str.length()-1);
	return 0;
}
