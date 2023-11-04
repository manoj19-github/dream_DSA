
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

int foundPick(vector<int>arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    int mid = start + (end - start) / 2;
    while (start < end) {
        if (arr[mid]<arr[mid+1]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return end;
}
int binarySearch(vector<int>arr, int start, int end, int searchKey) {
    int startPoint = start;
    int endPoint = end;
    int mid = startPoint + (endPoint - startPoint) / 2;
    while (startPoint <= endPoint) {
        if (arr[mid] == searchKey) {
            return mid;
        }
        else if (arr[mid] > searchKey) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = startPoint + (endPoint - startPoint) / 2;
    }
    return -1;

}
int findPositionFromSortedAndRotatedArr(vector<int>& vec, int searchKey) {
    int Pivot = foundPick(vec);
    if ( searchKey>=vec[0] && searchKey <= vec[Pivot]) {
        return binarySearch(vec, 0, Pivot - 1, searchKey);
    }
    else return binarySearch(vec, Pivot, vec.size() - 1, searchKey);
}

void main() {
    vector<int> arr = { 6,9,16,28,35,53,1,3,5 };

    int ans = findPositionFromSortedAndRotatedArr(arr,3);
    cout << "Answer is : " << ans;

   
   
    



}

