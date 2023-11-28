// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;


void printStack(stack<int>stk, int count, int size) {
    //base case 
    if (count ==  size) return;
    cout << stk.top()<<" ";
    stk.pop();
    printStack(stk, count + 1, size);
   
}


void sortInsert(stack<int>&stk, int element) {
    //base case 
    if (stk.empty() || stk.top() < element) {
        stk.push(element);
        return;
    }
    int num = stk.top();
    stk.pop();
    sortInsert(stk,element);
    stk.push(num);
}

void sortStack(stack<int>& stk) {
    if (stk.empty()) return;
    int num = stk.top();
    stk.pop();
    sortStack(stk);
    sortInsert(stk, num);
}

int main()
{
    stack<int>stk;
    stk.push(20);
    stk.push(13);
    stk.push(59);
    stk.push(27);
    stk.push(15);
    cout << endl;
    cout << "Before reverse" << endl;
    printStack(stk, 0, stk.size());
    cout << endl;

    cout << "After reverse" << endl;
    cout << endl;
    cout << endl;
    printStack(stk, 0, stk.size());
    sortStack(stk);
    cout << endl;
    printStack(stk, 0, stk.size());



    
}
