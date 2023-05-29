
#include<iostream>
#include<vector>
using namespace std;

void main() {
    vector<int>vec = { 10,23,456,12,45,634,56,74 };
    vector<int>temp(vec.size());
    for (int iter = 0; iter < vec.size(); iter++) {
        temp[(iter + 2) % vec.size()] = vec[iter];

    }
    vec = temp;
    for (int i : vec) {
        cout << i << " , ";
    }
    

}