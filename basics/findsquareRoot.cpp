// findSquareRoot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter Number : " << endl;
	cin >> num;
	int i = 1, result = 0;
	while (result<=num) {
		i++;
		result = i * i;

	}
	cout << "Sqare Root is : " << i - 1;
	return 0;
}

