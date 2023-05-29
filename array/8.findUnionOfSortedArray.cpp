//Move all negative numbers to beginning and positive to end with constant extra space
//input : [-12,40,-9,1,-3,45,53] , output: [-12,-9,-3,40,1,45,53]

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedArrayUnion(vector<int>& arr, vector<int>& brr) {
    
    int ar1Length = arr.size();
    int ar2Length = brr.size();
    vector<int>ans;
    int i = 0, j = 0;
    while (i < ar1Length && j < ar2Length) {
        if (arr[i] < brr[j]) ans.push_back(arr[i++]);
        else if (arr[i] > brr[j]) ans.push_back(brr[j++]);
        else {
            ans.push_back(brr[j++]);
            i++;
        }
    }
    while (i < ar1Length) {
        ans.push_back(arr[i++]);
    }
    while (j < ar2Length) {
        ans.push_back(brr[j++]);
    }
    return ans;
}

void main() {
    vector<int>arr = { 10,13,15,17,19 };
    vector<int>brr = { 12,13,15,19,21,34,37,38 };
    
    vector<int> ans = sortedArrayUnion(arr, brr);
    cout << endl << "Union array is :" << endl;
    for (int iter : ans) {
        cout << iter << " , ";
    }
}