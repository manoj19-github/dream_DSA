// find_in_sorted_rotated_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>vec) {
	int s = 0, e = vec.size() - 1;
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
	return s;
}
int binarySearch(vector<int>vec, int s, int e,int searchVal) {
	int mid = s + (e - s) / 2;
	while (s <= e) {
		if (vec[mid] == searchVal) return mid;
		else if (vec[mid] > searchVal) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
		mid = s + (e - s) / 2;
	}
	return -1;
}
int main()
{
	vector<int> vec = { 10,15,20,1,5,7 };
	int searchVal;
	cout << "Enter SearchVal: " << endl;
	cin >> searchVal;
	int pivot = getPivot(vec);
	int ans;
	if (vec[0] > searchVal >= vec[pivot]) {
		cout << endl << "second part search" << endl;
		ans = binarySearch(vec, pivot, vec.size()-1,searchVal);
	}
	else {
		cout << endl << "first part search" << endl;
		ans = binarySearch(vec, 0, pivot-1, searchVal);
	}
	cout << "SearchVal is occured in  : " << ans << endl;
}
    