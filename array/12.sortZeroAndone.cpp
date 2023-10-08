
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

void sortZeroAndOne(vector<int>& arr) {
    int i = 0;
    int j = arr.size() - 1;
    while (i<j) {
        while (arr[i] <= 0&& i<j) i++;
        while (arr[j] > 0 && i<j) j--;
        if (arr[i] > 0 && arr[j] <=0  && i<j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
        
    }
}



int main()
{

    vector<int>arr = { 1,2,0,0,0,3,0,2,0,2 };
    sortZeroAndOne(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ", ";
    }
   

    


    
}

