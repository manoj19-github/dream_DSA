// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

void deleteMiddle(stack<int>&stk, int count, int size) {
    //base case 
    if (count == size / 2) {
        cout << endl;
        stk.pop();
        return;

    }

    int num = stk.top();
    stk.pop();
    deleteMiddle(stk, count + 1, size);
    stk.push(num);
}
void printStack(stack<int>stk, int count, int size) {
    //base case 
    if (count ==  size) return;
    cout << stk.top()<<" ";
    stk.pop();
    printStack(stk, count + 1, size);
   
}

int main()
{
    stack<int>stk;
    stk.push(20);
    stk.push(13);
    stk.push(29);
    stk.push(27);
    stk.push(45);
    cout << "Before delete" << endl;
    printStack(stk, 0, stk.size());
    deleteMiddle(stk, 0, stk.size());
    cout << "After delete" << endl;
    printStack(stk, 0, stk.size());
    
}
