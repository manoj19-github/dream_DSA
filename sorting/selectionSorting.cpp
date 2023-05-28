//  what is selection sort : 
// selection sort is simple and efficiend sorting algorithm that works
// by repeatedly selecting the smallest(or largest) element from the unsorted portion of the list 
// and moving it to the sorted portion of the list.

// time  Complexity : 
// the time complexity of selection sort is O(N2) as there two nested loops : 
// one loop select an element one by one = O(N)
// another loop to compare that element with every other array element = O(N)
// therefore overall complexity is =  O(N)*O(N) = O(N2)


// selection sort

#include<iostream>
#include<vector>
using namespace std;

void swap(int* first, int* second) {
	*first = *first + *second;
	*second = *first - *second;
	*first = *first - *second;
}
void selectionSort(vector<int>&arr) {
	int arLength = arr.size();
	int minIndex = 0;
	for (int outer = 0; outer < arLength-1; outer++) {
		minIndex = outer;
		for (int inner = outer + 1; inner < arLength; inner++) {
			if (arr[minIndex] > arr[inner]) minIndex = inner;
		}
		if(outer !=minIndex)
		swap(&arr[minIndex], &arr[outer]);
	}
}
void main() {
	vector<int>arr = { 10,20,13,90,35,67,17 };
	selectionSort(arr);
	cout << endl;
	for (int iter : arr) {
		cout << iter << " , ";
	}
}


