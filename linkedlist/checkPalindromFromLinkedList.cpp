
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d = 0) {
		this->data = d;
		this->next = NULL;
	}
};


void addLast(int data, Node** head) {
	Node* newNode = new Node(data);
	Node* temp = *head;
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode;
}


void printNodes(Node* head) {
	Node* temp = NULL;
	temp = head;
	cout << endl << "Nodes : " << endl << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}


	temp = NULL;
	delete temp;
}

// check palindrom by taking an array
bool isPalindromApproach1(Node* head) {
	vector<int>arr;
	if (head->next == NULL) return true;
	Node* temp = head;
	while (temp != NULL) {
		arr.push_back(temp->data);
		temp = temp->next;
	}
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end) {
		if (arr[start] != arr[end]) return false;
		start++;
		end--;
	}
	return true;
	
}

Node* getMiddle(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	
	}
	return slow;
}
Node* reverseList(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;		
	}
	return prev;
}
// check palindrom approach 2 

bool isPalindromApproach2(Node* head) {
	if (head->next == NULL) return true;
	//step 1: find middle 
	Node* middle = getMiddle(head);

	// step 2: reverse list
	Node* temp = middle->next;
	middle->next = reverseList(temp);
	//step 3 : compare two list 
	Node* head1 = head;
	Node* head2 = middle->next;
	while (head2 != NULL) {
		if (head1->data != head2->data) return false;
		head1 = head1->next;
		head2 = head2->next;
	}
	// step 4 : repeat step 2 
	temp = middle->next;
	middle->next = reverseList(temp);
	return true;



}
void main() {
	Node* head = NULL;
	addLast(1,&head);
	addLast(2,&head);
	addLast(2, &head);
    addLast(1, &head);
	cout << endl << "Check palindrom from Linked List (Approach 1) : "<<endl;
	if (isPalindromApproach1(head)) {
		cout << "Yes is Palindrom "<<endl;
	}
	else {
		cout << "No is not Palindrom " << endl;
	}
	cout << "Approach 2 : " << endl;
	if (isPalindromApproach2(head)) {
		cout << "Yes is Palindrom " << endl;
	}
	else {
		cout << "No is not Palindrom " << endl;
	}
}


