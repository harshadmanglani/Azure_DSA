#include <iostream>

using namespace std;
void printArray(int *arr, int n);
void SelectionSort(int *a, const int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
			if(a[i]>a[j])
				swap(a[i], a[j]);
		printArray(a, n);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
//	cout<<"a: "<<*a<<" b: "<<*b<<endl;
}

void FindSmallest(int *a, int start, int end)
{
	if(start == end)
		return;

	if(a[start] > a[end])
		swap(a[start], a[end]);

	printArray(a, end+1);
	FindSmallest(a, start, --end);
}

void RecursiveSelectionSort(int *a, int start, int end)
{
	if(start == end)
		return;

	FindSmallest(a, start, end);
	RecursiveSelectionSort(a, ++start, end);
}

void printArray(int *arr, int n)
{
	for(int i = 0; i< n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	cout<<"Enter the number of elements in the array: "<<endl;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	SelectionSort(arr, n);
	cout<<"=====\n";
	printArray(arr, n);
	RecursiveSelectionSort(arr, 0, n-1);
	cout<<"=====\n";
	printArray(arr, n);
	return 0;
}
