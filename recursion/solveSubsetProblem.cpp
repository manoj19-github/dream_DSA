
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



void solveSubset(vector<int>nums, vector<int>output, vector<vector<int>>&ans, int index) {
	//base case
	if (index >= nums.size()) 
		return ans.push_back(output);
	// for exclude 
	solveSubset(nums, output, ans, index + 1);
	//for include
	int element = nums[index];
	output.push_back(element);
	solveSubset(nums, output, ans, index + 1);
}
void main() {
	vector<int> output;
	int index = 0;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ans;
	solveSubset(nums, output, ans, index);
    cout<<"Answer is : "<<endl<<endl;
	for (auto item : ans) {
		for (auto elem : item) {
			cout << elem << " ";
		}
		cout << endl;
	}
   

}

