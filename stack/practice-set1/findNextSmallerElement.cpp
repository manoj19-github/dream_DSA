
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
		while (stk.top() >= vec[i]) stk.pop();
		ans[i] = stk.top();
		stk.push(vec[i]);
	}
	return ans;
}




int main()
{
	vector<int>vec = { 2,1,4,3 };
	vector<int>ans = findNextSmallElement(vec);
	cout<<endl << "Answer is : " << endl;
	for (int curr : ans) {
		cout << curr << " , ";
	}
}


