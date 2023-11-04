
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
pair<int,int> findFirstAndLastOccurence(vector<int>arr, int search) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans1 = -1;
    
    while (start <= end) {
        if (arr[mid] == search) {
            end = mid - 1;
            ans1 = mid;

        }
        else if (arr[mid] < search) {
            start = mid + 1;
        }
        else {
            end = mid - 1;;
        }
        mid = start + (end - start) / 2;

    }
    start = 0;
    end = arr.size() - 1;
    mid = start + (end - start) / 2;
    int ans2 = -1;

    while (start <= end) {
        if (arr[mid] == search) {
            start = mid + 1;
            ans2 = mid;

        }
        else if (arr[mid] < search) {
            start = mid + 1;
        }
        else {
            end = mid - 1;;
        }
        mid = start + (end - start) / 2;

    }

    pair<int,int> result = { ans1,ans2 };

    return result;
}

void main() {

    vector<int> arr = { 1,2,5,77,77,78,90,912 };
    pair<int,int> occurence = findFirstAndLastOccurence(arr, 77);
    cout << "First occurence is:" << occurence.first<<endl;
    cout << "Last occurence is : " << occurence.second;
}

