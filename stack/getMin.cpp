// Design a stack that supports getMin() in O(1) time and O(1) extra space


//

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>

// N stack in an array

using namespace std;

class SpecialStack {
public:
    stack<int>stk;
    int min = INT_MIN;
public:
    void push(int data) {
        if (stk.empty()) {
            stk.push(data);
            min = data;
        }
        else {
            if (data < min) {
                stk.push(2 * data - min);
                min = data;
            }
            else {
                stk.push(data);
            }
        }
    }
    int pop() {
        if (stk.empty()) return -1;
        else {
            int curr = stk.top();
            stk.pop();
            if (min > curr) {
                int prevMin = min;
                int val = 2 * min - curr;
                min = val;
                return prevMin;
            }
            return curr;

        }
    }
    int top() {
        if (stk.empty()) return -1;
        int top = stk.top();
        if (min > top) return min;
        return top;

    }
    int getMin() {
        if (stk.empty()) return -1;
        return min;
    }
};

int main()
{
 
    SpecialStack stk;
    stk.push(5);
    stk.push(3);
    stk.push(8);
    stk.push(1);
    stk.push(2);
    stk.push(4);
    cout << endl;
    cout << stk.top();
    stk.pop();
    stk.pop();
    stk.pop();
    cout << endl << "Min  : " << stk.getMin();
    

  

    
}
