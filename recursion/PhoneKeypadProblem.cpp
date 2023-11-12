
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


void solvePhoneKeypadProb(string digits, string keyMap[], string output, int index, vector<string>&ans) {
	//base case 
	if (index >= digits.size()) return ans.push_back(output);

	int num = digits[index] - '0'; // to convert this string into a integer
	string keys = keyMap[num];
	for (int i = 0; i < keys.size(); i++) {
		output.push_back(keys[i]);
		solvePhoneKeypadProb(digits, keyMap, output, index + 1, ans);
		output.pop_back();  // backtracking to reset output for next option
	}
}



void main() {
	string digits = "24";
	string keyMap[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	string output = "";
	vector<string>ans;
	int index = 0;
	solvePhoneKeypadProb(digits, keyMap, output, index, ans);

	cout << "Answer is : " << endl<<endl;
	for (auto item : ans) {
		cout << item << "  ";
	}
}

