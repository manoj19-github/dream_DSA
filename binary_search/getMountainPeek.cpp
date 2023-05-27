#include<iostream>
#include<vector>
using namespace std;

int getMountainPeek(vector<int>vec) {
    int e = vec.size() - 1;
    int s = 0;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (vec[mid] <  vec[mid+1]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    vector<int>vec = { 2,4,6,8,15,13,10,7 };
    cout << "Ans : " << getMountainPeek(vec) << "  ";
}
