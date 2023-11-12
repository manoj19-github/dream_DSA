
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;



int power(int a, int b) {
    //base case 
    if (b == 0) return 1;
    if (b == 1) return a;
    int ans = power(a, b / 2);
    if (b % 2 == 0) return ans * ans;
    return ans * ans * a;
}

void main() {
    int a = 2;
    int b = 4;
    cout << "Answer is : " << power(a, b);
    


}

