

#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;


class NStack {
	int* arr;
	int n, k;
	int* top;
	int* next;
	int freeSpot;
	public:
		NStack(int n, int k) {
			this->n = n;
			this->k = k;
			this->arr = new int[n];
			this->top = new int[k];
			this->next = new int[n];
			this->freeSpot = 0;
			for (int i = 0; i < n; i++) this->next[i] = i + 1;
			this->next[n - 1] = -1;
			for (int i = 0; i < k;i++) {
				this->top[i] = -1;
			}
		}
		bool push(int num, int n) {
			// check for overflow
			if (this->freeSpot == -1) return false;
			// find index 
			int index = this->freeSpot;
			// update freeSpot
			this->freeSpot = this->next[index];
			// insert element within array 
			this->arr[index] = num;
			// update next
			this->next[index] = this->top[n - 1];
			this->top[n - 1] = index;
			return true;
		}
		int pop(int n) {
			// check for underflow
			if (this->top[n - 1] == -1) return -1;
		    // get the array index 
			int index = this->top[n - 1];
			// update top 
			this->top[n - 1] = this->next[index];
			// update next
			this->next[index] = this->freeSpot;
			// update freeSpot
			this->freeSpot = index;
			return this->arr[index];
		}


};

int main()
{
	NStack nStack(10, 3);
	nStack.push(4, 1);
	nStack.push(6, 1);
	nStack.push(14, 2);
	cout << endl << nStack.pop(1) << endl;
	cout << endl << nStack.pop(1) << endl;
	cout << endl << nStack.pop(2) << endl;

	
}


