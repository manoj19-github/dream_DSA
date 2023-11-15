
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

//  reverse linked list using recursive approach
void reverseList(Node** head, Node* curr, Node* prev) {
    if(*head==NULL || (*head)->next == NULL ) return;
	if (curr == NULL) {
		*head = prev;
		return;
	}
	reverseList(head, curr->next, curr);
	curr->next = prev;
}
void recursivelyReverse(Node** head) {
	Node* curr = *head;
	Node* prev = NULL;
	reverseList(head, curr, prev);
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
	recursivelyReverse(&head);
	printNodes(head);



}


