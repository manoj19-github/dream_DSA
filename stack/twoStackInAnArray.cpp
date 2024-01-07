
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class TwoStack {
	int* arr;
	int top1;
	int top2;
	int size;
	public:
		TwoStack(int s) {
			this->size = s;
			this->top1 = -1;
			this->top2 = s;
			arr = new int[s];
		}
		void push1(int num) {
			if (this->top2 - this->top1 > 1) {
				this->top1++;
				arr[top1] = num;
			}
			else {
				cout << "Stack overflow" << endl;
			}
		}
		void push2(int num) {
			if (this->top2 - this->top1 > 1) {
				this->top2--;
				arr[top2] = num;
			}
			else {
				cout << "Stack overflow" << endl;
			}
		}
		int pop1() {
			if (this->top1 >= 0) {
				int ans = arr[this->top1];
				this->top1--;
				return ans;
			}
			return -1;
		}
		int pop2() {
			if (this->top2 < this->size) {
				int ans = arr[this->top2];
				this->top2--;
				return ans;
			}
			return -1;

		}
};


int main()
{
	TwoStack tw(5);
	tw.push1(43);
	tw.push1(24);
	tw.push1(45);
	int ans = tw.pop1();
	cout << ans << endl;
	tw.push2(3);
	tw.push2(34);
	int ans2 = tw.pop2();
	cout << ans2 << endl;






   
}

