// sort 0s,1s and 2s without using any sorting alog
// using dutch national flag algo

#include <iostream>
#include<vector>
using namespace std;
void swap(int* ptr1, int* ptr2) {
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;

}

int main()
{
	vector<int>arr1 = { 0,0,1,1,0,2,0,1,0,1,0 };
	int mid = 0, low = 0;
	int high = arr1.size() - 1;
	while (mid <= high) {
		switch (arr1[mid]) {
		case 0:
			swap(&arr1[low++], &arr1[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(&arr1[high--], &arr1[mid]);
			break;
		}
	}
	
	
	for (int iter : arr1) {
		cout << iter;
	}

}
