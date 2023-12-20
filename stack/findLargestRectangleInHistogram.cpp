// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>

// largest rectangle area in histogram
// input --> [2,1,5,6,2,3]    ouput --> 10

using namespace std;

vector<int>nextSmallerElement(vector<int>arr) {
    stack<int>stk;
    vector<int>ans(arr.size());
    stk.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--) {
        int curr = arr[i];
        while (stk.top() != -1 && arr[stk.top()] >= curr)stk.pop();
        ans[i] = stk.top();
        stk.push(i);

    }
    return ans;

}
vector<int>prevSmalllerElement(vector<int>arr) {
    stack<int>stk;
    vector<int>ans(arr.size());
    stk.push(-1);
    for (int i = 0; i < arr.size(); i++) {
        int curr = arr[i];
        while (stk.top() != -1 && arr[stk.top()] >= curr) stk.pop();
        ans[i] = stk.top();
        stk.push(i);

    }
    return ans;

}
int largestRectanleArea(vector<int>& heights) {
    int lengthofHeights = heights.size();
    vector<int>next(lengthofHeights);
    vector<int>prev(lengthofHeights);
    next = nextSmallerElement(heights);
    prev = prevSmalllerElement(heights);
    int area = INT_MIN;
    for (int i = 0; i < lengthofHeights; i++) {
        int l = heights[i];
        if (next[i] == -1) next[i] = lengthofHeights;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);

        
    }
    return area;

}





int main()
{
    vector<int>input = { 2,1,5,6,2,3 };
    cout << "Answer is : " << largestRectanleArea(input);
  

    
}
