
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


void printArray(vector<int>vec) {
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " , ";
    }
    cout << endl;
}
void rotateArray(vector<int>&vec,int k) {
    vector<int>temp(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        temp[(i + k) % vec.size()] = vec[i];
    }
    vec = temp;
}

void main() {
    vector<int>vec = { 3,6,2,90,45,23,70,12,55 };
    cout << "first array :" << endl;
    printArray(vec);
    rotateArray(vec, 2);
    cout << "rotated array :" << endl;
    printArray(vec);

}

