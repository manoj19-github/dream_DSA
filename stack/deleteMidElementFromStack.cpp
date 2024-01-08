
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {
	// base case 
	if (count == size / 2) {
		inputStack.pop();
		return;
	}
	int num = inputStack.top();
	inputStack.pop();
	solve(inputStack, count + 1, size);
	inputStack.push(num);
}

void deleteMiddleFromStack(stack<int>& inputStack, int size) {
	int count = 0;
	solve(inputStack, count, size);
}
void printStack(stack<int>inputStack) {
	if (inputStack.empty()) return;
	int element = inputStack.top();
	inputStack.pop();
	printStack(inputStack);
	cout << element << " , ";
	inputStack.push(element);
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
	stk.push(70);
	cout << "Stack element : " << endl;
	printStack(stk);
	cout << endl;
	deleteMiddleFromStack(stk, 7);
	cout << endl;
	cout << "Stack element : " << endl;
	printStack(stk);
}


