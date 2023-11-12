
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


void solveSubsequence(string output, vector<string>&ans, string words, int index) {
	//base case 
	if (index >= words.size()) return ans.push_back(output);

	// for exclude cases
	solveSubsequence(output, ans, words, index + 1);

	// for include cases
	char elem = words[index];
	output.push_back(elem);
	solveSubsequence(output, ans, words, index + 1);
}


void main() {
	string words = "abcde";
	vector<string>ans;
	string output;
	int index = 0;
	cout << "answer is : " << endl;
	solveSubsequence(output, ans, words, index);
	for (auto elem : ans) {
		cout << elem << " ";
	}
	cout << endl;

}

