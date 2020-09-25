#include <iostream>
#include <stack>
using namespace std;
bool shift_top(stack<int>&a, stack<int>&b);

void toh(int n, stack<int>& a, stack<int>& b, stack<int>& c)
{
//stack a is the source
//stack b is the intermediate
//stack c is the destination
	if(n==1)
	{
		if(shift_top(a, c))
			return;
		else
			cout<<"Something went wrong..\n";
	}
	else{
		toh(n-1, a, c, b);
		shift_top(a, c);
		toh(n-1, b, a, c);
	}
}

bool insert_into_stack(int data, stack<int>& st)
{
	if(st.empty())
		st.push(data);
	else{
		if(data < st.top())
			st.push(data);
		else
			return false;
	}
	return true;
}

bool shift_top(stack<int>& a, stack<int>& b){
	//shifts the top elemenet from stack a into stack b
	int x = a.top();
	bool res = insert_into_stack(x, b);
	if(res) a.pop() ;
	return res;
}

void print_stack(stack <int> st)
{
	stack <int> copy;
	while(!st.empty())
	{
		cout<<"==="<<endl;
		cout<<st.top()<<endl;
		copy.push(st.top());
		st.pop();
	}
	while(!copy.empty())
	{
		st.push(copy.top());
		copy.pop();
	}
}

int main()
{
	stack<int> a, b, c;
	for(int i = 5; i >= 1; i--)
	a.push(i);
	cout<<"stack A is: "<<endl;
	print_stack(a);
	//cout<<"top of a: "<<a.top()<<endl;
	toh(5, a, b, c);
	cout<<"stack C is: "<<endl;
	print_stack(c);
	return 0;
}
