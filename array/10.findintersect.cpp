
#include <iostream>
#include<vector>
using namespace std;

int findUnique(int* arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];

    }
    return ans;
}

vector<int>findInter(vector<int>& arr1, vector<int>& arr2) {
    vector<int>answer;
    int i = 0;
    int j = 0;
   /* for (int i = 0; i < arr1.size(); i++) {
        int elem = arr1[i];
        
        for (int j = 0; j < arr2.size(); j++) {
            if (elem < arr2[j]) break;
            if (elem == arr2[j]) {
                answer.push_back(arr2[j]);
                arr2[j] = -1;
                break;
            }
        }
    }*/
    while (i < arr1.size() && j < arr2.size()) {
        
        if (arr1[i] == arr2[j]) {
            answer.push_back(arr1[i]);
            i++; j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }

    }

    return answer;
}

int main()
{

    vector<int>arr = { 2, 2, 4, 4, 7 };
    vector<int>arr2 = { 2,3,4,56,78,172 };
    vector<int>result = findInter(arr, arr2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " , " << " ";
    }
    


    
}

