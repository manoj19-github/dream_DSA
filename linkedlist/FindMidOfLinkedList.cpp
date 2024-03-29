
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
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


Node* findMiddle(Node* head) {
	
	if (head == NULL || head->next == NULL) return head;
	if (head->next->next == NULL) return head->next;

	Node* first = head->next;
	Node* slow = head;
	while (first != NULL) {
		first = first->next;
		if (first) {
			first = first->next;
		}
		slow = slow->next;


	}

	return slow;
}

// reverse k group 
Node* reverseKGroup(Node* head, int k) {
	// base case 
	if (head == NULL) return NULL;

	// step1: reverse first k nodes
	Node* next = NULL;
	Node* curr = head;
	Node* prev = NULL;
	int count = 0;
	while (curr != NULL && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if (next != NULL) {
		head->next = reverseKGroup(next, k);
	}
	return prev;
}


void main() {
	Node* head = NULL;
	addLast(50, &head);
	addLast(10, &head);
	addLast(20, &head);
	addLast(30, &head);
	addLast(40, &head);
	addLast(60, &head);
	addLast(80, &head);
	addLast(90, &head);
	addLast(510, &head);
	Node* middle = findMiddle(head);
	printNodes(head);
	reverseKGroup(head,2);
	printNodes(head);





}


