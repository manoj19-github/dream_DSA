
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;
void printArray(int arr[], int length) {
    cout << "Array is : " << endl;
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "  ";
    }
}
void swap(int* item1, int* item2) {
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}
int partition(int arr[], int start, int end) {
    int pivotItem = arr[start];
    int leftCount = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivotItem) leftCount++;
    }
    int pivotIndex = start + leftCount;
    swap(&arr[start], &arr[pivotIndex]);
    int ptr1 = start;
    int ptr2 = end;
    while (ptr1<pivotIndex && ptr2>pivotIndex) {
        while (arr[ptr1] < pivotItem) ptr1++;
        while (arr[ptr2] > pivotItem) ptr2--;
        if (ptr1<pivotIndex && ptr2>pivotIndex) {
            swap(&arr[ptr1], &arr[ptr2]);
            ptr1++;
            ptr2--;
        }
    }
    return pivotIndex;


}

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;
    int pivot = partition(arr,start,end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot+1,end);
}


void main() {
    int arr[7] = {34,12,78,9,123,56,90};
    cout << "unsorted list" << endl;
    printArray(arr, 7);
    quickSort(arr, 0, 6);
    cout <<endl<< "sorted list" << endl;
    printArray(arr, 7);


}


