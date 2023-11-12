
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


void swap(char* ptr1, char* ptr2) {
	char* temp = ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *temp;
    temp = NULL;
    delete temp;


}
void solvePermute(vector<string> input, vector<vector<string>>& ans, int index) {
	// base case 
	if (index >= input.size()) return ans.push_back(input);
	for (int i = index; i < input.size(); i++) {
		swap(input[index], input[i]);
		solvePermute(input, ans, index + 1);
		swap(input[index], input[i]);   // backtracking

	}
}

void main() {
	vector<string> input = { "a","b","c" };
	vector<vector<string>>ans;
	vector<string>output;
	int index = 0;
	solvePermute(input, ans, index);

	cout << "Answer is : " << endl << endl;
	for (auto items : ans) {
		for (auto elem : items) {
			cout << elem << " ";
		}
		cout << endl;
	}


	
   

}

