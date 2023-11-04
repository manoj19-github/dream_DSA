
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
void printWaveMattrix(vector<vector<int>>vec,int rowLength,int colLength) {
    for (int i = 0; i < colLength; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < rowLength; j++) {
                cout << vec[j][i]<<"  ,  ";
            }
        }
        else {
            for (int j = colLength - 1; j >= 0; j--) {
                cout << vec[j][i] << "  ,  ";
            }
        }
    }
}

void printSpiralWay(vector<vector<int>>vec) {
    int row = vec.size();
    int col = vec[0].size();
    int count = 0;
    int total = row * col;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col - 1;
    vector<int> answer;
    while (count < total) {
        for (int index = startingCol; index <= endingCol && count<total; index++) {
            answer.push_back(vec[startingRow][index]);
            cout << vec[startingRow][index] << ", ";
            count++;
        }
        startingRow++;
        for (int index = startingRow; index <= endingRow && count<total; index++) {
            cout << vec[index][endingCol] << ", ";
            count++;
        }
        endingCol--;
        for (int index = endingCol; index >= startingCol && count<total; index--) {
            cout << vec[endingRow][index] << ", ";
            count++;
        }
        endingRow--;
        for (int index = endingRow; index >= startingRow && count < total; index--) {
            cout << vec[index][startingCol] << ", ";
            count++;
        }
        startingCol++;
        

    }
    cout << endl;
    

   
}
void rotateArray(vector<vector<int>>vec,vector<vector<int>>answer) {
    
    
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            answer[i][j] = vec[j][i];
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        int first = 0;
        int last = vec[i].size() - 1;
        while (first <= last) {
            int temp = answer[i][first];
            answer[i][first] = answer[i][last];
            answer[i][last] = temp;
            first++;
            last--;
        }
    }
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << answer[i][j]<<", ";
        }
        cout << endl;
    }

}

void main() {
    vector <vector<int >> vec = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>>answer = { {0,0,0},{0,0,0},{0,0,0} };
    rotateArray(vec,answer);
 
    
   
    
}

