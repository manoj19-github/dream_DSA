
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


vector<vector<int>> findPairSum(vector<int>& arr, int sum) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr.size(); i++) {
        
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == sum){
                vector<int> row;
                row.push_back(min(arr[i], arr[j]));
                row.push_back(max(arr[i], arr[j]));
                answer.push_back(row);

            }

        }
    }
   sort(answer.begin(), answer.end());
   return answer;

}



int main()
{

    vector<int>arr = { 1,2,3,4,2,5 };
    vector<vector<int>> ans = findPairSum(arr, 6);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ,  ";
        }
        cout << endl;
    }

    


    
}

