
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;


vector<int>findNextSmallElement(vector<int>& vec) {
	vector<int>ans(vec.size());
	stack<int>stk;
	stk.push(-1);
	for (int i = vec.size()-1; i >=0;i--) {
		while ( stk.top()>-1 && vec[stk.top()] >= vec[i]) stk.pop();
		ans[i] = stk.top();
		stk.push(i);
	}
	return ans;
}

vector<int>findPrevSmallerElement(vector<int>& vec) {
	vector<int>ans(vec.size());
	stack<int>stk;
	stk.push(-1);
	for (int i = 0; i <vec.size(); i++) {
		while (stk.top() > -1 && vec[stk.top()] >= vec[i]) {
			stk.pop();

		}
		ans[i] = stk.top();
		stk.push(i);
	}
	return ans;
}

int largestRectangle(vector<int>& vec) {
	int n = vec.size();
	vector<int>next(n);
	vector<int>prev(n);
	next = findNextSmallElement(vec);
	prev = findPrevSmallerElement(vec);
	int area = INT_MIN;
	for (int i = 0; i < vec.size(); i++) {
		int l = vec[i];
		if (next[i] == -1) next[i] = n;
		int b = next[i] - prev[i] - 1;
		int newArea = l * b;
		area = max(area, newArea);

	}
	return area;

}



int main()
{
	vector<int>vec = { 2,1,5,6,2,3 };
	int n = largestRectangle(vec);
	cout << "Answer is : " << endl;
	cout << n;
}


