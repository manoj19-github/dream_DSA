
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



int fibonacci(int n) {
    
    if (n <= 1) return n;//base case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    cout << endl;
    cout<<"Answer is : "<<fibonacci(n);
}

