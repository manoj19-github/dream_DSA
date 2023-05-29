// check palidrom char array or not
#include <iostream>
using namespace std;


char toLowercase(char ch) {
	if (ch >= 'a' && ch <= 'z') return ch;
	else return ch - 'A' + 'a';
}

bool checkPalindrom(char mychar[],int size) {
	int s = 0;
	int e = size-1;
	while (s <= e) {
		if (toLowercase(mychar[s++]) !=toLowercase(mychar[e--])) return false;
	}
	return true;
}

int main()
{
	char mychar[] = { 'm','a','d','a','m' };
	bool ans = checkPalindrom(mychar, 5);
	if (ans) {
		cout <<endl<< "This is palindrom string"<<endl;
	}
	else {
		cout << endl << "This is not a palindrom string" << endl;
	}
}
