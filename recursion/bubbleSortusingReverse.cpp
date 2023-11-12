
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



void bubbleSort(int arr[], int length) {
    if (length == 0 || length == 1) return;  // base case 
    for (int i = 0; i < length-1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubbleSort(arr, length - 1);
}
void printArray(int arr[], int n) {
    cout << "Array is : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void main() {
    int arr[6] = { 70,60,50,30,20,10 };
    bubbleSort(arr, 6);
    printArray(arr, 6);
}

