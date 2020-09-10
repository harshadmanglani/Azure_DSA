#include<iostream>
using namespace std;
int main(){
int i = 5;
int &j = i;
i = 7;
cout<<"i: "<<i<<" j: "<<j<<endl;

j = 10;
cout<<"i: "<<i<<" j: "<<j<<endl; 
return 0;}
