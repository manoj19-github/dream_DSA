// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

void swap(int first, int last) {
    int temp = first;
    first = last;
    last = temp;
}

void insertionSort(vector<int>&vec) {
    int i, j,key;
    for (int i = 1; i < vec.size(); i++) {
        key = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] < key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
   


}
void printArray(vector<int>vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << "  " << vec[i] << " ";
    }
    cout << endl << endl;
}
void main()
{
    vector<int>vec = { 4,23,56,23,90,78,92 };
    cout << "Unsorted Array : " << endl;
    printArray(vec);
    insertionSort(vec);
    cout << "Sorted Array :  " << endl;
    printArray(vec);
    
}
