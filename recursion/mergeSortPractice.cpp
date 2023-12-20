// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>


using namespace std;

void merge(vector<int>& arr, int start, int end) {
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
    while (arrIter1 < subArrayOne && arrIter2 < subArrayTwo) {
        if (firstArray[arrIter1] <= secondArray[arrIter2]) {
            arr[k++] = firstArray[arrIter1++];
        }
        else {
            arr[k++] = secondArray[arrIter2++];
        }
    }
    while (arrIter1 < subArrayOne) arr[k++] = firstArray[arrIter1++];
    while (arrIter2 < subArrayTwo) arr[k++] = secondArray[arrIter2++];
    firstArray = secondArray = NULL;
    delete firstArray; delete secondArray;
}
void mergeSort(vector<int>& arr,int start,int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);

}



int main()
{
    vector<int> input = { 33,23,78,98,27,10 };
    mergeSort(input, 0, 5);
    for (int item : input) {
        cout << item << " , ";
    }

    
}
