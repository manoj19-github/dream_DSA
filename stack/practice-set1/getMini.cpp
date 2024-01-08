
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
#include<stack>
using namespace std;

class SpecialStack {
	stack<int>stk;
	int mini;
	public:
	void push(int data) {
		if (stk.empty()) {
			mini = data;
			stk.push(data);
		}
		else {
			if (data < mini) {
				stk.push(2 * data - mini);
				mini = data;
			}
			else {
				stk.push(data);

			}
		}
	}
	int pop() {
		if (stk.empty()) return-1;
		int curr = stk.top();
		stk.pop();
		if (curr > mini) return curr;
		int prevMini = mini;
		int val = 2 * mini - curr;
		mini = val;
		return prevMini;
	}
	int top() {
		if (stk.empty()) return -1;
		int curr = stk.top();
		if (curr < mini) return mini;
		return curr;
	}
	int getMin() {
		return mini;
	}
};


void  main() {
	SpecialStack stk;
	stk.push(13);
	stk.push(23);
	stk.push(3);
	stk.push(9);
	stk.push(5);
	
	cout << "Mini : " << endl;
	cout << endl << stk.getMin() << endl;
	stk.pop();
	cout << "Mini : " << endl;
	cout << endl << stk.getMin() << endl;
	stk.pop();
	stk.pop();
	stk.pop();
	
	cout << endl << stk.getMin() << endl;


}