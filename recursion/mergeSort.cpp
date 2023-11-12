
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


void merge(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;
    int subArrayOne = mid - start + 1;
    int subArrayTwo = end - mid;
    int* firstArray = new int[subArrayOne];
    int* secondArray = new int[subArrayTwo];

    int k = start;
    for (int i = 0; i < subArrayOne; i++) firstArray[i] = arr[k++];
    k = mid + 1;
    for (int i = 0; i < subArrayTwo; i++) secondArray[i] = arr[k++];
    int arrIter1 = 0; int arrIter2 = 0;
    k = start;
    // main sorting algo
    while (arrIter1 < subArrayOne && arrIter2 < subArrayTwo) {
        if (firstArray[arrIter1] <= secondArray[arrIter2]) {
            arr[k++] = firstArray[arrIter1++];
        }
        else {
            arr[k++] = secondArray[arrIter2++];

        }
    }


    while (arrIter1 < subArrayOne) {
        arr[k++] = firstArray[arrIter1++];
    }
    while (arrIter2 < subArrayTwo) {
        arr[k++] = secondArray[arrIter2++];

    }
    firstArray = secondArray = NULL;
    delete firstArray; delete secondArray;

}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) return; //base case 
    int mid = start + (end - start) / 2;
    //left part 
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);

}
void printArray(int arr[], int length) {
    cout << endl << "Array is : " << endl;
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;

}


void main() {
    int arr[6] = { 100,90,80,70,50,20 };
    printArray(arr, 6);
    mergeSort(arr, 0, 5);
    printArray(arr, 6);

}

