
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void sayDigit(int n,string arr[]) {
    //base case 
    if (n == 0) return;
    int digit = n % 10;
    n = n / 10;
    sayDigit(n,arr);
    cout << arr[digit] << "  ";


}

void main() {
    int n;
    string arr[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    cout << "Enter the number : " << endl;
    cin >> n;
    cout << endl;
    sayDigit(n, arr);
    
}

