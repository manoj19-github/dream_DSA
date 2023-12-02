// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

// (a+b), (a+(b+c),((a+b)+(c+d)) is not redundant bracket
// ((a+b)) is redundant bracket


bool findRedundantBracke(string& s) {
    stack<char>st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') st.push(ch);
        else {
            if (ch == ')') {
                bool isRedundant = true;
                while (st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') isRedundant = false;
                    st.pop();
                }
                if (isRedundant) return true;
                st.pop();
            }
        }

       
    }
    return false;
}
int main()
{
    string s = "((a+b))";

    cout << findRedundantBracke(s)<<endl;


    
}
