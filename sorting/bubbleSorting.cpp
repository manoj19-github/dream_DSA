// what is Bubble sort 

// Bubble sort works on the repeatedly swapping of adjacent elements until they are not in the 
// intended order. It is called bubble sort because the movement of array elements is just like the movement of air bubble in the water. bubble rises up to the surface , similarly the array elements in bubble sort move 
// to the end in each position


#include<iostream>
#include<vector>
using namespace std;

void swap(int* ptr1, int* ptr2) {
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;

}
void bubbleSort(vector<int>& arr) {
	int arLength = arr.size();
	for (int outer = 1; outer < arLength; outer++) {
		bool isSwapped = false;
		for (int inner = 0; inner < arLength - outer; inner++) {
			if (arr[inner] > arr[inner + 1]) {
				isSwapped = true;
				swap(&arr[inner], &arr[inner + 1]);
			}
		}
		if (!isSwapped) break;
	}
}

void main() {
	vector<int>arr = { 10,23,14,36,49,30,64,10,91,41 };
	cout << endl << " Unsorted Array : " << endl;
	for (int iter : arr) {
		cout << iter << " , ";
	}
	bubbleSort(arr);
	cout << endl << " Sorted Array : " << endl;
	for (int iter : arr) {
		cout << iter << " , ";
	}
	

}

