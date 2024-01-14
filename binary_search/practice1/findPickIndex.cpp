#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
#include<stack>
using namespace std;

int findPickIndex(vector<int>vec) {
	int start = 0;
	int end = vec.size() - 1;
	int mid = start + (end - start) / 2;
	while (start < end) {
		if (vec[mid] < vec[mid + 1]) start = mid + 1;
		else end = mid;
		mid = start + (end - start) / 2;
	}
	return start;
}

void main() {
	vector<int>vec = { 12,34,56,78,45,3 };
	int ans = findPickIndex(vec);
	cout << ans << endl;
}