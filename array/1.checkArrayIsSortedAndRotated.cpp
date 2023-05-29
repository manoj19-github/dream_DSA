// move zerroes

#include<iostream>
#include<vector>
using namespace std;

bool isArraySortedAndRotatedArray(vector<int>vec) {
    int arLength = vec.size();
    int count = 0;
    for (int i = 1; i < arLength; i++) {
        if (vec[i - 1] > vec[i]) {
            count++;
        }
    }
    if (vec[arLength - 1] > vec[0]) count++;
    return count <= 1;

}
void main() {
    vector<int>vec = { 3,5,7,1,2};
    if (isArraySortedAndRotatedArray(vec)) {
        cout << "Array is sorted and rotated" << endl;
    }
    else {
        cout << "Array is not sorted and rotated" << endl;
    }
}