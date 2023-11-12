
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



int partition(int arr[], int start, int end) {

    int pivotItem = arr[start];
    int leftCount = 0;
    for (int i = start+1; i <= end; i++) {
        if (pivotItem <= arr[i])
        leftCount++;
    }
    int pivotIndex = start + leftCount;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[start];
    arr[start] = arr[pivotIndex];
    int ptr1 = start, ptr2 = end;
    while (ptr1<pivotIndex && ptr2>pivotIndex) {
        while (arr[ptr1] <= pivotItem) {
            ptr1++;
        }
        while (arr[ptr2] >= pivotItem) {
            
            ptr2--;
        }
        if (ptr1<pivotIndex && ptr2>pivotIndex) {
            int temp = arr[ptr1];
            arr[ptr1] = arr[ptr2];
            arr[ptr2] = temp;
            ptr1++;
            ptr2--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end) {
    if (start >= end) return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1,end);

}

void printArray(int arr[], int length) {
    cout << "Array is : " << endl;
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "  ";
    }
}
void main() {
    int arr[6] = { 100,90,80,70,50,20 };
    printArray(arr, 6);
    quickSort(arr, 0, 5);
    printArray(arr, 6);

}

