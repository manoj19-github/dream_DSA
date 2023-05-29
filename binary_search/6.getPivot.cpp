// getPivot.cpp : This file contains the 'main' function. Program execution begins and ends there.
// [10,15,17,1,2,5]   ===>   1

#include <iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>vec) {
	int s = 0, e = vec.size()-1;
	int mid = s + (e - s) / 2;
	while (s < e) {
		if (vec[mid] >= vec[0]) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
		mid = s + (e - s) / 2;
	}
	return vec[s];
}
int main()
{
	vector<int> vec = { 10,15,20,1,5,7 };
	int ans = findPivot(vec);
	cout << "Answer : " << ans;
}


