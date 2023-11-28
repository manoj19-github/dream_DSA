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
void insertAtBottom(stack<int>&stk, int element) {
    // base case 
    if (stk.size()==0) {
        stk.push(element);
        return;
     
    }
    else {
        int num = stk.top();
        stk.pop();
        insertAtBottom(stk, element);
        stk.push(num);
    }
}
void reverseStack(stack<int>& stk) {
    if (stk.size()==0) return;
    int num = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk, num);
}

int main()
{
    stack<int>stk;
    stk.push(20);
    stk.push(13);
    stk.push(29);
    stk.push(27);
    stk.push(45);
    cout << endl;
    cout << "Before reverse" << endl;
    printStack(stk, 0, stk.size());
    cout << endl;

    cout << "After reverse" << endl;
    cout << endl;
    reverseStack(stk);
    cout << endl;
    printStack(stk, 0, stk.size());
    
}
