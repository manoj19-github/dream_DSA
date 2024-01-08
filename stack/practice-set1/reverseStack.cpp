
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;



void printStackFromBottom(stack<int>& stk) {
	if (stk.empty()) return;
	int element = stk.top();
	stk.pop();
	printStackFromBottom(stk);
	cout << element << " , ";
	stk.push(element);
}


void sortedInsert(stack<int>& stk, int element) {
	if ((stk.empty()) || (stk.top() <= element)) {
		stk.push(element);
		return;
	}
	int num = stk.top();
	stk.pop();
	sortedInsert(stk,element);
	stk.push(num);

}
void sortStack(stack<int>& stk) {
	if (stk.empty()) return;
	int element = stk.top();
	stk.pop();
	sortStack(stk);
	sortedInsert(stk, element);
}



int main()
{
	stack<int>stk;
	stk.push(10);
	stk.push(60);
	stk.push(20);
	stk.push(13);
	stk.push(150);
	stk.push(20);
	cout << endl << "Stack element : " << endl;
	printStackFromBottom(stk);
	sortStack(stk);
	cout << endl << "Stack element : " << endl;
	printStackFromBottom(stk);


	
	
	
}


