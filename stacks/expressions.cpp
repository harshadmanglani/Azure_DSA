#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <iterator>
#include <bits/stdc++.h> 

using namespace std;

bool isVariable(char obj)
{
    if((obj >= 'a' && obj <= 'z') || (obj >= 'A' && obj <= 'Z'))
    return true;
    return false; 
}

int priority(char op)
{
    switch(op)
    {
        case '(': return -1;
        case '^': return 4;
        case '/': return 3;
        case '*': return 2;
        case '+': return 1;
        case '-': return 0;
    }
}

string infixToPostfix(string infix)
{
    stack<char> operands;
    string postfix;
    for(int i = 0; i < infix.length(); i++)
    {
        if(isVariable(infix[i]))
            postfix += infix[i];

        else if(infix[i] == '(')
            operands.push('(');
        
        else if(infix[i] == ')')
        {
            while(operands.top() != '(')
            {
                postfix += operands.top();
                operands.pop();
            }
            operands.pop();
        }
        
        else{
            
            if(operands.empty() || priority(infix[i]) > priority(operands.top()))
                {
                    operands.push(infix[i]);
                }
            else
            {
                while(!operands.empty() && priority(operands.top()) >= priority(infix[i]))
                {
                    postfix += operands.top();
                    operands.pop();
                }
                operands.push(infix[i]);
            }
        }
    }
    while(!operands.empty())
    {
        postfix += operands.top();
        operands.pop();
    }
    return postfix;
}

string postfixToInfix(string postfix)
{
    stack<string> operands;
    for(int i = 0; i < postfix.length(); i++)
    {
        if(isVariable(postfix[i]))
        {
            string o(1, postfix[i]);
            operands.push(o);
        }
        else
        {
            string op1 = operands.top(); 
            operands.pop(); 
            string op2 = operands.top(); 
            operands.pop(); 
            //NOTE: INNER TOP + OPERATOR + OUTER TOP
            operands.push("(" + op2 + postfix[i] + 
                   op1 + ")"); 
        }
    }
    return operands.top();
}

int evaluate(int b, int a, char operation)
{
    cout<<"operation: "<<to_string(a)<<" "<<operation<<" "<<to_string(b)<<endl;
    switch(operation)
    {
        case '^': return pow(b, a);
        case '/': return b/a;
        case '*': return a*b;
        case '-': return b-a;
        case '+': return a+b;
    }
}

int evaluatePostfix(string postfix)
{
    map<char, int> values;
    map<char, int>::iterator it;
    stack<int> operands;
    for(int i = 0; i < postfix.length(); i++)
    {
        if(isVariable(postfix[i]))
        {
            it = values.find(postfix[i]);
            if(it == values.end())
            {
                cout<<"Please enter a value for "<<postfix[i]<<": ";
                int a;
                cin>>a;
                values.insert({postfix[i], a});
                operands.push(a);
            }
            else
            {
                operands.push(it->second);
            }
        }

        else{
            int a = operands.top();
            operands.pop();
            int b = operands.top();
            operands.pop();
            int c = evaluate(b, a, postfix[i]);
            operands.push(c);
        }
    }
    return operands.top();
}

int main() 
{ 
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    cout<<"postfix result: "<<infixToPostfix(exp)<<endl; 
    cout<<"infix result: "<<postfixToInfix(infixToPostfix(exp))<<endl;
    int result = evaluatePostfix(infixToPostfix(exp));
    cout<<"the evaluation is: "<<result<<endl;
    return 0; 
} 
