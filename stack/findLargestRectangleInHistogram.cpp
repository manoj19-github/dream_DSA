// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>

// largest rectangle area in histogram
// input --> [2,1,5,6,2,3]    ouput --> 10

using namespace std;

vector<int>prevSmallerElement(vector<int>arr) {
    int arLength = arr.size();
    stack<int> stk;
    stk.push(-1);
    vector<int>ans(arLength);
    for (int i = 0; i < arLength; i++) {
        int curr = arr[i];
        while (stk.top() != -1 && arr[stk.top()] >= curr) stk.pop();
        ans[i] = stk.top();
        stk.push(i);
    }
    return ans;
}

vector<int>nextSmallerElement(vector<int>arr) {
    int arLength = arr.size();
    stack<int> stk;
    stk.push(-1);
    vector<int>ans(arLength);
    for (int i = arLength - 1; i >= 0; i--) {
        int curr = arr[i];
        while (stk.top() != -1 && arr[stk.top()] >= curr) stk.pop();
        ans[i] = stk.top();
        stk.push(i);
    }
    return ans;
}


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int>next(n);
    next = nextSmallerElement(heights);
    vector<int>prev(n);
    prev = prevSmallerElement(heights);
    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        if (next[i] == -1) {
            next[i] = n;
        }
        int newArea = l * b;
        area = max(area, newArea);

    }
    return area;

    
    
}




int main()
{
    vector<int>input = { 2,1,5,6,2,3 };
    int ans = largestRectangleArea(input);
    cout << "Answer is : " << ans << endl;
    


    
}
