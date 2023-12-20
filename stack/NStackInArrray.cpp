// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>

// N stack in an array

using namespace std;


class NStack {
    int* arr;
    int* top;
    int* next;
    int n, s;
    int freeSpot;
public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // initialize top
        for (int i = 0; i < n; i++) top[i] = -1;
        // next initialize;
        for (int i = 0; i < s; i++) next[i] = i + 1;
        //update last index to -1
        next[s - 1] = -1;
        // initialize freespot
        freeSpot = 0;

    }
    bool push(int x, int m) {
        if (freeSpot == -1) return false;

        // find index 
        int index = freeSpot;

        // update free spot 
        freeSpot = next[index];
        //insert an element into array 
        arr[index] = x;
        // update next
        next[index] = top[m - 1];
        // update top
        top[m - 1] = index;
        return true;
    }
    int pop(int m) {
        if (top[m - 1] == -1) return -1;
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

};

int main()
{
    NStack nstk(3, 9);
    nstk.push(10, 1);
    cout << "Answer is : " << nstk.pop(1);
  

    
}
