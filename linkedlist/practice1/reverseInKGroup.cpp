
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
	cout << endl << endl;
}

Node* reverseLinkedListInKGroup(Node* head, int k) {
	if (head == NULL) return head;
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count = 0;
	while (curr != NULL && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if (next != NULL) {
		head->next = reverseLinkedListInKGroup(curr, k);
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
	printNodes(head);
	head = reverseLinkedListInKGroup(head,2);
	printNodes(head);
	



}


