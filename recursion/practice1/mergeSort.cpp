// mergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void merge(int arr[], int start, int end) {
	int mid = start + (end - start) / 2;
	int firstArrLength = mid - start + 1;
	int secondArrLength = end - mid;
	int *firstArr = new int[firstArrLength];
	int* secondArr = new int[secondArrLength];

	// split the array into two sub parts 

	int k = start;
	// first part
	for (int i = 0; i < firstArrLength; i++) firstArr[i] = arr[k++];
	//second part
	k = mid + 1;
	for (int i = 0; i < secondArrLength; i++) secondArr[i] = arr[k++];

	// merge and sort both into main  array
	int arr1Iter = 0;int arr2Iter = 0;
	k = start;
	while (arr1Iter < firstArrLength && arr2Iter < secondArrLength) {
		if (firstArr[arr1Iter] <= secondArr[arr2Iter]) {
			arr[k++] = firstArr[arr1Iter++];
		}
		else {
			arr[k++] = secondArr[arr2Iter++];
		}

	}

	while (arr1Iter < firstArrLength)  arr[k++] = firstArr[arr1Iter++];
	while (arr2Iter < secondArrLength)  arr[k++] = secondArr[arr2Iter++];
	firstArr = secondArr = NULL;
	delete firstArr;
	delete secondArr;
}

void mergeSort(int arr[], int start,int end) {
	if (start >= end) return;
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, end);
}

void printArray(int arr[],int size) {
	cout << endl << "The Array is : " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ,  ";
	}
}

int main()
{
	int arr[7] = { 12,43,59,20,54,66,23 };
	printArray(arr, 7);
	mergeSort(arr, 0, 6);
	printArray(arr, 7);

}
