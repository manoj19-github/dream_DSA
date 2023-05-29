

#include <iostream>
#include <vector>
#include<set>
using namespace std;


void unionOfUnsortedArray(vector<int>arr, vector<int>brr) {
    int length1 = arr.size(), length2 = brr.size();
    set<int>s;
    for (int i = 0; i < length1; i++) {
        s.insert(arr[i]);
    }
    for (int j = 0; j < length2; j++) {
        s.insert(brr[j]);
    }
    cout <<endl<< "Number of union element : " << endl;
    for(auto iter = s.begin();iter!=s.end();iter++){
        cout << *iter << " , ";
    }
    
}

void main() {
    vector<int>arr = { 2,5,2,6,7,2,5,7,1,4 };
    vector<int>brr = { 4,6,8,1,2,9 };
    unionOfUnsortedArray(arr, brr);

}