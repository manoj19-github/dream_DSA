// input : test output : t, input please e 


#include<iostream>
using namespace std;
char getMaxOccur(string input) {
	int arr[26] = { 0 };
	for (int iter = 0; iter < input.size(); iter++) {
		char ch = input[iter];
		int number = 0;
		if (input[iter] >= 'a' && input[iter] <= 'z') {
			number = ch - 'a';
		}
		else {
			number = ch - 'A';
		}
		arr[number]++;
	}
	int maxi = 0, ans = 0;
	for (int iter = 0; iter < 26; iter++) {
		if (maxi < arr[iter]) {
			ans = iter;
			maxi = arr[iter];
		}
	}
	return 'a' +ans;
}
void main() {
	string input;
	cout << "Enter the string : " << endl;
	cin >> input;
	char ans = getMaxOccur(input);
	cout << endl << "Answer is : " << ans << endl;

}