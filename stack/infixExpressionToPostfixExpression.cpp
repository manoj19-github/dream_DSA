// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

// convert infix expression  to postfix expression using stack data structure

// example : infix => (a+b+c) * d^e^f)/g   ====> postfix => ab+c-def^^g/

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-': return 1;
        default: return -1;

    }
}
bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}

string infixToPostfix(string infix) {
    stack<char> stk;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] >= 'Z')) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stk.top() != '(' && (!stk.empty())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if (isOperator(infix[i])) {
            if (stk.empty()) stk.push(infix[i]);
            else {
                if (precedence(infix[i]) > precedence(stk.top())) stk.push(infix[i]);
                else if((precedence(infix[i]) == precedence(stk.top())) && (infix[i]=='^'))  stk.push(infix[i]);
                else {
                    while ((!stk.empty()) && precedence(infix[i]) <= precedence(stk.top())) {
                        postfix += stk.top();
                        stk.pop();
                    }
                }
            }
        }
    }

    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int main()
{
    string infix = "((a+b+c) * d^e^f)/g";
    cout << "Answer: postfix Expression is : " << infixToPostfix(infix);
        
}
