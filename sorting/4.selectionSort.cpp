
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void swap(int* ptr1, int* ptr2) {
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}

void insertionSort(vector<int>& vec) {
    for (int i = 0; i < vec.size()-1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[minIndex] > vec[j]) {
                minIndex = j;
            }
        }
        int temp = vec[minIndex];
        vec[minIndex] = vec[i];
        vec[i] = temp;

    }
}
void printArray(vector<int>vec) {
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " , ";
    }
    cout << endl;
}

void main() {
    vector<int>vec = { 3,6,2,90,45,23,70,12,55 };
    cout << "unsorted array :" << endl;
    printArray(vec);
    insertionSort(vec);
    cout << endl << "sorted array " << endl;
    printArray(vec);
}

