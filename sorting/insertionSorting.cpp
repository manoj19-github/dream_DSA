// WHAT IS INSERTION SORTING
//  insertion sort is a simple sorting algorithm that works similar  to 
// the way you sort playing cards in your hands. the array is vitually split 
// into a sorted array and an unsorted part. values from the unsorted
// placed at correct position in the sorted part



void swap(int* ptr1, int* ptr2) {
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;

}


void insertionSort(vector<int>& arr) {
	int i, key, j;
	for (i = 1; i < arr.size(); i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void main() {
	vector<int>arr = { 10,23,14,36,49,30,64,10,91,41 };
	cout << endl << " Unsorted Array : " << endl;
	for (int iter : arr) {
		cout << iter << " , ";
	}
	insertionSort(arr);
	cout << endl << " Sorted Array : " << endl;
	for (int iter : arr) {
		cout << iter << " , ";
	}
	

}