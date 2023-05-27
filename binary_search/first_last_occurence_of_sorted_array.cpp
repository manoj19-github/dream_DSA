// first_last_occurence_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>vec, int searchVal) {
	int e = vec.size()-1;
	int s = 0;
	int mid = s + (e - s) / 2;
	int ans = -1;
	while (s <= e) {
		if (vec[mid] == searchVal) {
			ans = mid;
			e = mid - 1;
		}
		else if (vec[mid] > searchVal) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
		mid = s + (e - s) / 2;
	}
	return ans;
}

int lastOccurence(vector<int>vec, int searchVal) {
	int e = vec.size() - 1;
	int s = 0;
	int mid = s + (e - s) / 2;
	int ans = -1;
	while (s <= e) {
		if (vec[mid] == searchVal) {
			ans = mid;
			s = mid + 1;
		}
		else if (vec[mid] > searchVal) {
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
	vector<int>vec = { 1,2,3,3,3,3,3,4,5,6,7 };

	cout << endl<<"First Occurence is : " << firstOccurence(vec,3);
	cout << endl <<"last Occurence is : " << lastOccurence(vec, 3);
}
