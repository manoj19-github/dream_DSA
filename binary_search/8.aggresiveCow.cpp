
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void swap(int* ptr1, int* ptr2) {
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}

// find first occurence 


bool isPossible(vector<int>&stalls, int mid, int k) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) return true;
            lastPos = stalls[i];
        }
        
    }
    return false;
}

int aggresiveCow(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++) {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end) {
        if (isPossible(stalls, mid, k)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
void main() {
    vector<int> arr = { 10,20,30,40 };
    int ans = aggresiveCow(arr, 2);
    cout << "Answer is : " << ans;

   
   
    



}

