
// book_allocartion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>arr, int n, int studentCount, int mid) {
	int sCount = 1;
	int pageSum = 0;
	for (int i = 0; i < n; i++) {
		if (pageSum + arr[i] <= mid) {
			pageSum += arr[i];
		}
		else {
			sCount++;
			if (sCount > studentCount || arr[i] > mid) {
				return false;
			}
			pageSum = 0;
			pageSum += arr[i];
		}
	}
	return true;

}
int allocateBooks(vector<int> arr, int arLength, int studentCount) {
	int s = 0;
	int sum = 0;
	for (int i = 0; i < arLength; i++) {
		sum += arr[i];
	}
	int e = sum;
	int ans = -1;
	int mid = s + (e - s) / 2;
	while (s <= e) {
		if (isPossible(arr, arLength, studentCount, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
		mid = s + (e - s) / 2;
	}
	return ans;

}
int main()
{
	vector<int>vec = { 10,20,30,40 };
	int studentCount = 2;
	int ans = allocateBooks(vec, 4, 2);
	cout << "Ans  : " << ans;

	

}
