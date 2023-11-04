
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

 long long int SqrtInteger(int num) {
    int start = 0;
    int end = num;
    long long int mid = start + (end - start) / 2;
    long long  int ans = -1;
    while (start <= end) {
        long long int square = mid * mid;
        if (square == num) {
            return mid;
        }
        else if (square < num) {
            ans = mid;
            start = mid + 1;
            
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
    
}
 double morePrecision(int num, int precision, int tempsol) {
     double factor = 1;
     double ans = tempsol;
     for (int i = 0; i < precision; i++) {
         factor /= 10;
         for (double j = ans; j * j < num; j += factor) {
             ans = j;
         }
     }
     return ans;
 }

void main() {
    cout << "Enter your number to find sqrt : " << endl;
    int num;
    cin >> num;
    int tempsol = SqrtInteger(num);
    double ans = morePrecision(num, 3, tempsol);
    cout<<endl << "Answer is : " << ans;


    

   
   
    



}

