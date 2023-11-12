
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



int binarySearch(int arr[], int start, int end,int search) {
    //base case 
    
    if (start > end) return -55;
    int mid = start + (end - start) / 2;
    if (arr[mid] == search) return mid;


    if ( arr[mid]<search) return binarySearch(arr, start,mid-1,search);
    return binarySearch(arr, mid+1,end, search);
}

void main() {
    int arr[6] = {100,70,60,40,20,10};
   
    int ans = binarySearch(arr, 0, 5, 70);
    cout << endl << ans << endl;
    if (ans>=0) cout << endl << "your number is found at : " << ans << endl;
    else cout << "not found";

    
}

