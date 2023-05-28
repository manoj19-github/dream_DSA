// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// input : 39 >>>>> output : 6.24499

#include <iostream>
using namespace std;


int binarySearchForSqrt(int searchVal) {
	int start = 0, end = searchVal;
	int mid = start + (end - start) / 2;
	int ans = -1;
	while (start <= end) {
		long long int sqrt = mid * mid;
		if (sqrt == searchVal) return mid;
		else if (sqrt < searchVal) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
		mid = start + (end - start) / 2;
	}
	return ans;
}

double findPrecision(int num, int tempSol,int precision) {
	double ans = tempSol;
	double factor = 1;
	for (int i = 0; i < precision; i++) {
		factor /= 10;
		for (double j = ans; j * j < num; j += factor) {
			ans = j;
		}
	}
	return ans;

}
int main()
{
	int num;
	cout << "Enter the Number : " << endl;
	cin >> num;
	int tempSol = binarySearchForSqrt(num);
	double actualSqrt = findPrecision(num,tempSol,5);
	cout<<endl << "Answer is : " << actualSqrt;
    return 0;


}
