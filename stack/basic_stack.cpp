// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
class Stack {
public:
    int* arr;
    int top;
    int size;
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << endl << "Stack overflow" << endl;
        }

    }
    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is Empty" << endl << endl;
            return -1;
        }

    }
    void pop() {
        if (top >= 0)  top--;
        else {
            cout << "Stack underflow" << endl;
        }
    }
    bool isEmpty() {
        if (top == -1) return true; 
        return false;

    }

};

void main()
{
    Stack ss= Stack(5);
    ss.push(1);
    cout<<endl<<ss.peek();


    
}
