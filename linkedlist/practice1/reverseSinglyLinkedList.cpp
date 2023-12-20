
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
void reverseLinkedList(Node** head) {
	if (*head == NULL || (*head)->next == NULL) return;
	Node* prev = NULL;
	Node* curr = *head;
	Node* forward = NULL;
	while (curr != NULL) {
		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;

	}
	*head = prev;

}

// recursively reverse linked list 
void reverse(Node** head, Node* curr, Node* prev) {
	// base case 
	if (curr == NULL) {
		*head = prev;
		return;
	}
	Node* forward = curr->next;
	reverse(head, forward, curr);
	curr->next = prev;
}

void reverseLinkedListRecursive(Node** head) {
	Node* curr = *head;
	Node* prev = NULL;
	reverse(head, curr, prev);
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
	reverseLinkedList(&head);
	printNodes(head);
	reverseLinkedListRecursive(&head);
	printNodes(head);
	



}


