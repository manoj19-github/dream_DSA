// sumOfArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
void swap(int* ptr1, int* ptr2) {
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;

}
void reverseArray(vector<int>& vec) {
	int start = 0, end = vec.size()-1;
	while (start <= end) {
		swap(&vec[start], &vec[end]);
		start++;
		end--;
	}

}
vector<int>sumOfArray(vector<int>arr1,vector<int>arr2) {
	int arLength1 = arr1.size();
	int arLength2 = arr2.size();
	int i =arLength1-1, j = arLength2 - 1;
	int carry = 0;
	vector<int>ans;
	while (i >=0 && j >=0) {
		int value1 = arr1[i];
		int value2 = arr2[j];
		int sum = value1 + value2+carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while (i >= 0) {
		
		int sum =arr1[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}
	while (j >= 0) {
		int sum = arr2[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}
	while (carry != 0) {
		int sum = carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		
	}
	return ans;

}
int main()
{
	vector<int>arr1 = { 1,2,5,8 };
	vector<int>arr2 = { 2,3,7 };
	vector<int>ans = sumOfArray(arr1, arr2);
	reverseArray(ans);
	for (int iter : ans) {
		cout << iter;
	}

}
