#include<iostream>
#include<chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

unsigned long long int recursive_factorial(unsigned long long int n)
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

unsigned long long int optimized_factorial(unsigned long long int n, unsigned long long int *arr)
{
	if(n==1)
		return 1;

	if(arr[n] != 0)
		return arr[n];

	else
	{
		unsigned long long int temp = n * optimized_factorial(n-1, arr);
		arr[n] = temp;
		return temp;
	}
}

int main()
{
	unsigned long long int a = 20;
	unsigned long long int *arr = new unsigned long long int[a];
	unsigned long long int recursive, optimized;
	clock_t start_recursive = clock();
	recursive = recursive_factorial(a);
	clock_t end_recursive = clock();
	double recursive_duration = double(end_recursive - start_recursive)/double(CLOCKS_PER_SEC);
	cout<<"Time taken for the recursive function to execute: "<<recursive_duration<<setprecision(10)<<" s\n";
	cout<<"\n---------\n";
	clock_t start_optimized = clock();
	optimized = optimized_factorial(a, arr);
	clock_t end_optimized = clock();
	double optimized_duration = double(end_optimized - start_optimized)/double(CLOCKS_PER_SEC);
	cout<<"Time taken for the optimized function to execute: "<<optimized_duration<<setprecision(10)<<" s\n";
	cout<<"Optimized factorial: "<<optimized<<"\tRecursive factorial: "<<recursive<<endl;
	delete [] arr;
	return 0;
}
