
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;

void solve(stack<int>& stk, int num) {
	if (stk.empty()) {
		stk.push(num);
		return;
	}
	int element = stk.top();
	stk.pop();
	solve(stk, num);
	stk.push(element);
}

void printStackFromBottom(stack<int>& stk) {
	if (stk.empty()) return;
	int element = stk.top();
	stk.pop();
	printStackFromBottom(stk);
	cout << element << " , ";
	stk.push(element);
}

void insertAtBottomInStack(stack<int>& stk, int num) {
	solve(stk, num);
}

void reverseStack(stack<int>& stk) {
	if (stk.empty()) return;
	int element = stk.top();
	stk.pop();
	reverseStack(stk);
	insertAtBottomInStack(stk, element);
}




int main()
{
	stack<int>stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.push(60);
	cout<<endl << "Stack element : " << endl;
	printStackFromBottom(stk);
	reverseStack(stk);
	cout << endl << "Stack element : " << endl;
	printStackFromBottom(stk);

	
	
	
}


