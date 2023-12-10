// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
using namespace std;



vector<int>nextSmallerElement(vector<int>& arr, int n) {
    stack<int>stk;
    stk.push(-1);
    vector<int>ans(n);
    for (int i = n - 1; i >= 0; i--) {
        while (stk.top() >= arr[i]) {
            stk.pop();
        }
        ans[i] = stk.top();
      
        stk.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> vec = { 2,3,1 };
    vector<int>ans = nextSmallerElement(vec, 3);
  cout<<"Answer is : "<<endl;
  for (int c : ans) {
      cout << c << " ,";
  }
    


    
}
