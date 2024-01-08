
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;

// check given expression is valid parantheses or not 

bool isValidParantheses(string expression) {
	stack<char>stk;
	for (char self : expression) {
		if (self == '(' || self == '{' || self == '[') {
			
			stk.push(self);
		}
		else {
			if (!stk.empty()) {
				char top = stk.top();
				cout << top << endl;
				if ((top == '(' && self == ')') || (top == '{' && self == '}') || (top == '[' && self == ']')) stk.pop();
				else return false;
			}
			else return false;
		}
	}
	if (stk.empty())  return true;
	return false;
	
}




int main()
{
	string expression = "[{({})}]";
	bool ans = isValidParantheses(expression);
	cout << "Answer is :  " << ans << endl;
	
}


