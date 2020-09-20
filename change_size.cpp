#include<iostream>
#include<algorithm>
using namespace std;
template <class T>
void changeSize1D(T* &a, const int oldSize, const int newSize)
{

	if(newSize <= 0) return;
	int number = min(oldSize, newSize);
	T* temp = new T[newSize];
	copy(a, a+number, temp);
	delete [] a;
	a = temp;
}

int main()
{
	int *a = new int[5];
	char choice;
	for(int i =0; i< 5; i++)
		cin>>a[i];
	cout<<"Do you want to enter more numbers? (Y/n)?";
	cin>>choice;
	if(choice == 'Y')
	{
		changeSize1D(a, 5, 10);
		for(int i = 5; i < 10; i++)
			cin>>a[i];
		cout<<"===\n";
		for(int i =0; i < 10; i++)
			cout<<a[i]<<endl;
	}
	return 0;
}
