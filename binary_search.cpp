#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int BinarySearch(int *a, const int n, const int x)
{
	int left = 0, right = n-1;
	while(left <= right)
	{
		int middle = (left + right)/2;
		if (x < a[middle]) right = middle - 1;
		else if (x > a[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}

int RecursiveBinarySearch(int *a, const int left, const int right, const int x)
{
	if (left > right)
		return -1;

	int middle = (left + right)/2;
	if (x < a[middle]) return RecursiveBinarySearch(a, left, middle-1, x);
	else if(x > a[middle]) return RecursiveBinarySearch(a, middle+1, right, x);
	else return middle;
}

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;
	cout<<"3 is present at index: "<<BinarySearch(a, n, 3)<<endl;
	cout<<"12 is present at index: "<<BinarySearch(a, n, 12)<<endl;
	cout<<"========\n";
	cout<<"3 is present at index: "<<RecursiveBinarySearch(a, 0, n-1, 3)<<endl;
	cout<<"12 is present at index: "<<RecursiveBinarySearch(a, 0, n-1, 12)<<endl;
	return 0;
}
